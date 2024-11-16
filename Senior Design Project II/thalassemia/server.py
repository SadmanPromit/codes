from flask import Flask, render_template, request, session, redirect, url_for
from flask_sqlalchemy import SQLAlchemy
from flask_login import LoginManager, UserMixin, login_user, login_required, logout_user, current_user
from werkzeug.security import generate_password_hash, check_password_hash
import torch
import numpy as np
import torch.nn as nn
import pandas as pd
from datetime import datetime

app = Flask(__name__)
app.config['SECRET_KEY'] = 'your_secret_key_here'
app.config['SQLALCHEMY_DATABASE_URI'] = 'sqlite:///users.db'
db = SQLAlchemy(app)
login_manager = LoginManager(app)
login_manager.login_view = 'login'
DROPOUT_RATE = 0.1


class User(UserMixin, db.Model):
    id = db.Column(db.Integer, primary_key=True)
    username = db.Column(db.String(150), unique=True, nullable=False)
    password = db.Column(db.String(60), nullable=False)


class History(db.Model):
    id = db.Column(db.Integer, primary_key=True)
    user_id = db.Column(db.Integer, db.ForeignKey('user.id'), nullable=False)
    prediction = db.Column(db.String(255), nullable=False)
    timestamp = db.Column(db.DateTime, default=datetime.utcnow)

    Sex = db.Column(db.String(10))
    Age = db.Column(db.Float)
    Hb = db.Column(db.Float)
    PCV = db.Column(db.Float)
    RBC = db.Column(db.Float)
    MCV = db.Column(db.Float)
    MCH = db.Column(db.Float)
    MCHC = db.Column(db.Float)
    RDW = db.Column(db.Float)
    WBC = db.Column(db.Float)
    Plt = db.Column(db.Float)
    hbA = db.Column(db.Float)
    hbA2 = db.Column(db.Float)


class CNN(nn.Module):
    def __init__(self, dropout_prob=DROPOUT_RATE):
        super(CNN, self).__init__()
        self.conv1 = nn.Conv1d(1, 32, kernel_size=3, stride=1, padding=1)
        self.conv1x1 = nn.Conv1d(32, 64, kernel_size=1)  # 1x1 convolution to increase the channel size
        self.conv2 = nn.Conv1d(32, 64, kernel_size=3, stride=1, padding=1)
        self.dropout = nn.Dropout(dropout_prob)
        self.fc1 = nn.Linear(64 * 13, 128)
        self.fc2 = nn.Linear(128, 4)

    def forward(self, x):
        # First convolutional layer
        out_conv1 = nn.LeakyReLU()(self.conv1(x))

        # Use 1x1 convolution to match the channels for skip connection
        out_conv1_matched = self.conv1x1(out_conv1)

        # Second convolutional layer with skip connection from the first layer
        out_conv2 = nn.LeakyReLU()(self.conv2(out_conv1) + out_conv1_matched)

        out_conv2_flat = out_conv2.view(out_conv2.size(0), -1)
        out_fc1 = self.dropout(nn.LeakyReLU()(self.fc1(out_conv2_flat)))
        out_fc2 = self.fc2(out_fc1)

        return out_fc2


MODEL_PATH = './model.pth'
model = CNN().cuda()
model.load_state_dict(torch.load(MODEL_PATH))
model.eval()

mean_std_dict = {
    'Age': {'mean': 20.463929872495445, 'std': 11.466335513456459},
    'Hb': {'mean': 8.586215846994536, 'std': 0.7680998219843287},
    'MCH': {'mean': 21.352756264236902, 'std': 3.169943178666055},
    'MCHC': {'mean': 28.576662112932606, 'std': 7.898872179040151},
    'MCV': {'mean': 60.9526912568306, 'std': 15.410261536891122},
    'PCV': {'mean': 29.864676684881612, 'std': 3.723633373341736},
    'Plt': {'mean': 305.27199453551907, 'std': 117.73830685188247},
    'RBC': {'mean': 2.984774487471526, 'std': 0.8676333245429627},
    'RDW': {'mean': 33.510824225865214, 'std': 2.0144089619856493},
    'WBC': {'mean': 8.394635701275046, 'std': 2.0411274307133516},
    'hbA': {'mean': 73.80427595628416, 'std': 13.008079223281449},
    'hbA2': {'mean': 3.229125683060109, 'std': 1.148557205521791}
}

features_to_normalize = list(mean_std_dict.keys())


thalassemia_type_map_reverse = {
    1: 'Beta Minor',
    2: 'Beta Major',
    3: 'Alpha Major',
    0: 'Alpha Minor'
}


@login_manager.user_loader
def load_user(user_id):
    return User.query.filter_by(id=int(user_id)).first()


@app.route('/signup', methods=['GET', 'POST'])
def signup():
    if request.method == 'POST':
        username = request.form['username']
        password = request.form['password']
        user = User.query.filter_by(username=username).first()
        if user:
            error = "Username already exists!"
            return render_template('signup.html', error=error)
        hashed_password = generate_password_hash(password, method='scrypt')
        new_user = User(username=username, password=hashed_password)
        db.session.add(new_user)
        db.session.commit()
        return redirect(url_for('login'))
    return render_template('signup.html')


@app.route('/login', methods=['GET', 'POST'])
def login():
    error = None
    if request.method == 'POST':
        username = request.form['username']
        password = request.form['password']
        user = User.query.filter_by(username=username).first()
        if user and check_password_hash(user.password, password):
            login_user(user)
            return redirect(url_for('home'))
        else:
            error = "Invalid username or password! Please try again."

    return render_template('login.html', error=error)


@app.route('/logout')
@login_required
def logout():
    logout_user()
    return redirect(url_for('login'))


@app.route('/history')
@login_required
def history():
    user_history = History.query.filter_by(user_id=current_user.id).order_by(History.timestamp.desc()).all()
    return render_template('history.html', history=user_history)


@app.route('/about')
def about():
    return render_template('about.html')


@app.route('/', methods=['GET', 'POST'])
@login_required
def home():
    message = None
    prediction = None
    if request.method == 'POST':
        try:
            dataRow = request.form.get('dataRow')
            if dataRow:
                values = dataRow.split()
                if len(values) != 13:
                    raise ValueError("Invalid number of input values.")
                data = {
                    'Sex': [values[0]],
                    'Age': [float(values[1])],
                    'Hb': [float(values[2])],
                    'PCV': [float(values[3])],
                    'RBC': [float(values[4])],
                    'MCV': [float(values[5])],
                    'MCH': [float(values[6])],
                    'MCHC': [float(values[7])],
                    'RDW': [float(values[8])],
                    'WBC': [float(values[9])],
                    'Plt': [float(values[10])],
                    'hbA': [float(values[11])],
                    'hbA2': [float(values[12])]
                }
            else:
                data = {
                    'Sex': [request.form['Sex']],
                    'Age': [float(request.form['Age'])],
                    'Hb': [float(request.form['Hb'])],
                    'PCV': [float(request.form['PCV'])],
                    'RBC': [float(request.form['RBC'])],
                    'MCV': [float(request.form['MCV'])],
                    'MCH': [float(request.form['MCH'])],
                    'MCHC': [float(request.form['MCHC'])],
                    'RDW': [float(request.form['RDW'])],
                    'WBC': [float(request.form['WBC'])],
                    'Plt': [float(request.form['Plt'])],
                    'hbA': [float(request.form['hbA'])],
                    'hbA2': [float(request.form['hbA2'])]
                }
            input_df = pd.DataFrame(data)
            input_df['Sex'] = input_df['Sex'].apply(lambda x: 1 if x == 'M' else 0)
            for feature in features_to_normalize:
                input_df[feature] = (input_df[feature] - mean_std_dict[feature]['mean']) / mean_std_dict[feature]['std']
            tensor_features = torch.tensor(input_df.values).float().cuda().reshape(1, 1, 13)
            with torch.no_grad():
                output = model(tensor_features)
                predicted_class = np.argmax(output.cpu().numpy())
            predicted_type = thalassemia_type_map_reverse[predicted_class]
            history_entry = History(
                user_id=current_user.id,
                prediction=predicted_type,
                Sex=data['Sex'][0],
                Age=data['Age'][0],
                Hb=data['Hb'][0],
                PCV=data['PCV'][0],
                RBC=data['RBC'][0],
                MCV=data['MCV'][0],
                MCH=data['MCH'][0],
                MCHC=data['MCHC'][0],
                RDW=data['RDW'][0],
                WBC=data['WBC'][0],
                Plt=data['Plt'][0],
                hbA=data['hbA'][0],
                hbA2=data['hbA2'][0]
            )
            db.session.add(history_entry)
            db.session.commit()
            return render_template('home.html', prediction=f"{predicted_type} (71.75% probable)")
        except Exception:
            message = "Please check your input and try again."
    return render_template('home.html', message=message)


if __name__ == '__main__':
    with app.app_context():
        db.create_all()
    app.run(debug=True)

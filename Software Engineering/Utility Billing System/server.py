import os
from flask import Flask, render_template, request, redirect, url_for, send_file, flash
from flask_sqlalchemy import SQLAlchemy
from flask_login import LoginManager, UserMixin, login_user, login_required, logout_user, current_user
from werkzeug.security import generate_password_hash, check_password_hash
from reportlab.pdfgen import canvas
from reportlab.lib.pagesizes import letter
from reportlab.lib.units import inch
from io import BytesIO
import random
from datetime import datetime, timedelta

app = Flask(__name__)

# Configuration
app.config['SECRET_KEY'] = os.environ.get('SECRET_KEY', 'default_fallback_secret_key')
app.config['SQLALCHEMY_DATABASE_URI'] = os.environ.get('DATABASE_URL', 'sqlite:///users.db')
app.config['SQLALCHEMY_TRACK_MODIFICATIONS'] = False

# Database Initialization
db = SQLAlchemy(app)
login_manager = LoginManager(app)
login_manager.login_view = 'login'


# Models
class User(UserMixin, db.Model):
    id = db.Column(db.Integer, primary_key=True)
    username = db.Column(db.String(150), unique=True, nullable=False)
    password = db.Column(db.String(60), nullable=False)
    role = db.Column(db.Enum('admin', 'user', 'meter', name='user_roles'))
    email = db.Column(db.String(150), unique=True, nullable=True)
    address = db.Column(db.String(255), nullable=True)
    phone = db.Column(db.String(20), nullable=True)


class Bill(db.Model):
    id = db.Column(db.Integer, primary_key=True)
    amount = db.Column(db.Float, nullable=False)
    date = db.Column(db.DateTime, nullable=False)
    user_id = db.Column(db.Integer, db.ForeignKey('user.id'), nullable=False)


class BillingRate(db.Model):
    id = db.Column(db.Integer, primary_key=True)
    rate = db.Column(db.Float, nullable=False)


class Complaint(db.Model):
    id = db.Column(db.Integer, primary_key=True)
    content = db.Column(db.Text, nullable=False)
    user_id = db.Column(db.Integer, db.ForeignKey('user.id'), nullable=False)
    timestamp = db.Column(db.DateTime, index=True, default=datetime.utcnow)


def create_random_bills(user_id, num_bills=5):
    for _ in range(num_bills):
        amount = round(random.uniform(100.0, 1000.0), 2)
        date = datetime.now() - timedelta(days=random.randint(1, 365))
        new_bill = Bill(amount=amount, date=date, user_id=user_id)
        db.session.add(new_bill)
    db.session.commit()


# Routes
@app.route('/customer')
@login_required
def customer():
    bills = Bill.query.filter_by(user_id=current_user.id).all()
    if not bills:
        create_random_bills(current_user.id)
        bills = Bill.query.filter_by(user_id=current_user.id).all()
    return render_template('customer.html', bills=bills)


@app.route('/profile', methods=['GET'])
@login_required
def profile():
    return render_template('profile.html', user=current_user)


@app.route('/generate_bill_pdf/<int:bill_id>')
@login_required
def generate_bill_pdf(bill_id):
    try:
        bill = Bill.query.get_or_404(bill_id)
        if bill.user_id != current_user.id:
            flash("You are not authorized to view this bill.", category='error')
            return redirect(url_for('customer'))

        # Create a PDF with ReportLab
        buffer = BytesIO()
        p = canvas.Canvas(buffer, pagesize=letter)
        width, height = letter
        logo_x = inch
        logo_y = height - inch
        header_y_offset = 0.25 * inch
        details_x = inch
        details_y_start = logo_y - inch - header_y_offset
        line_height = 14
        static_folder = app.static_folder
        logo_path = os.path.join(static_folder, 'descologo.png')
        p.drawImage(logo_path, logo_x, logo_y, width=2 * inch, height=0.5 * inch, mask='auto')


        p.setFont('Helvetica-Bold', 12)
        p.drawString(details_x, details_y_start, "Dhaka Electric Supply Company Ltd")


        p.setFont('Helvetica', 10)
        details_y = details_y_start - 2 * line_height
        p.drawString(details_x, details_y, f"Date: {bill.date.strftime('%Y-%m-%d %H:%M:%S')}")
        p.drawString(details_x, details_y - line_height, f"Order No: {bill.id}")
        p.drawString(details_x, details_y - 2 * line_height, f"Name: {current_user.username}")

        costs_y = details_y - 4 * line_height
        p.drawString(details_x, costs_y, f"Energy Cost: {bill.amount}")
        footer_y = 0.75 * inch
        p.drawString(details_x, footer_y, "Powered by: System Automation Team")

        p.showPage()
        p.save()
        buffer.seek(0)
        return send_file(buffer, as_attachment=True, download_name=f'bill_{bill_id}.pdf', mimetype='application/pdf')

    except Exception as e:
        app.logger.error(f"Error generating PDF: {e}")
        flash("An error occurred while generating the PDF.", category='error')
        return redirect(url_for('customer'))


@login_manager.user_loader
def load_user(user_id):
    return User.query.get(int(user_id))


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


@app.route('/')
def index():
    return redirect(url_for('about'))


@app.route('/login', methods=['GET', 'POST'])
def login():
    error = None
    if request.method == 'POST':
        username = request.form['username']
        password = request.form['password']
        user = User.query.filter_by(username=username).first()

        if user and check_password_hash(user.password, password):
            login_user(user)
            next_page = request.args.get('next')

            if user.role == 'admin':
                return redirect(next_page or url_for('admin'))

            return redirect(next_page or url_for('customer'))

        else:
            flash("Invalid username or password!", category='error')

    return render_template('login.html', error=error)


@app.route('/logout')
@login_required
def logout():
    logout_user()
    return redirect(url_for('login'))


@app.route('/about')
def about():
    return render_template('about.html')


@app.route('/admin/delete_user/<int:user_id>', methods=['POST'])
@login_required
def delete_user(user_id):
    if current_user.role != 'admin':
        return 'Access Denied', 403
    user_to_delete = User.query.get(user_id)
    if user_to_delete:
        db.session.delete(user_to_delete)
        db.session.commit()
        flash('User deleted successfully', 'success')
    else:
        flash('User not found', 'error')
    return redirect(url_for('admin'))


@app.route('/admin', methods=['GET', 'POST'])
@login_required
def admin():
    if current_user.role != 'admin':
        flash('Access Denied', 'error')
        return redirect(url_for('login'))

    current_rate_obj = BillingRate.query.first()
    users = User.query.all()

    if request.method == 'POST':
        if 'rate' in request.form:
            try:
                new_rate = float(request.form['rate'])
                if current_rate_obj:
                    current_rate_obj.rate = new_rate
                else:
                    current_rate_obj = BillingRate(rate=new_rate)
                    db.session.add(current_rate_obj)

                db.session.commit()
                flash('Billing rate updated successfully', 'success')
            except ValueError:
                flash('Invalid input for rate', 'error')

    current_rate = current_rate_obj.rate if current_rate_obj else 0

    return render_template('admin.html', users=users, current_rate=current_rate)


@app.route('/admin/edit_user/<int:user_id>', methods=['GET', 'POST'])
@login_required
def edit_user(user_id):
    if current_user.role != 'admin':
        return 'Access Denied', 403
    user = User.query.get_or_404(user_id)

    if request.method == 'POST':
        user.email = request.form['email']
        user.address = request.form['address']
        user.phone = request.form['phone']
        db.session.commit()
        flash('User profile updated successfully', 'success')
        return redirect(url_for('admin'))

    return render_template('edit_user.html', user=user)


@app.route('/submit_complaint', methods=['GET', 'POST'])
@login_required
def submit_complaint():
    if current_user.role != 'admin':
        if request.method == 'POST':
            complaint_content = request.form.get('complaint')
            print("Complaint Content:", complaint_content)
            if complaint_content:
                new_complaint = Complaint(content=complaint_content, user_id=current_user.id)
                db.session.add(new_complaint)
                db.session.commit()
                flash('Complaint submitted successfully', 'success')
            else:
                flash('Complaint content cannot be empty.', 'error')
            return redirect(url_for('customer'))
        return render_template('submit_complaint.html')
    else:
        flash('Access Denied', 'error')
        return redirect(url_for('admin'))


@app.route('/view_complaints')
@login_required
def view_complaints():
    if current_user.role != 'admin':
        flash('Access Denied', 'error')
        return redirect(url_for('login'))

    complaints = Complaint.query.all()
    return render_template('view_complaints.html', complaints=complaints)


if __name__ == '__main__':
    # Populate
    with app.app_context():
        db.create_all()
        if not User.query.filter_by(username='admin').first():
            hashed_password = generate_password_hash('admin', method='scrypt')
            admin_user = User(username='admin', password=hashed_password, role='admin')
            db.session.add(admin_user)
            db.session.commit()

        if not BillingRate.query.first():
            initial_rate = BillingRate(rate=13.0)
            db.session.add(initial_rate)
            db.session.commit()

    app.run(debug=True)

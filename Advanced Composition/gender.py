import matplotlib.pyplot as plt
data = ['Female', 'Male', 'Female', 'Female', 'Male', 'Female', 'Male', 'Female', 'Female', 'Female', 'Female', 'Male', 'Male', 'Female', 'Male', 'Female', 'Female', 'Male', 'Male', 'Female', 'Male', 'Male']
counts = [data.count('Female'), data.count('Male')]
labels = ['Female', 'Male']
plt.pie(counts, labels=labels, autopct='%1.1f%%')
plt.savefig('gender.png', dpi=600, transparent=True, bbox_inches='tight')
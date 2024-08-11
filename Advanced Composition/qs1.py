import matplotlib.pyplot as plt
data = ["Sometimes", "Never", "Never", "Always", "Sometimes", "Sometimes", "Always", "Never", "No comments", "Sometimes", "Sometimes", "Sometimes", "Sometimes", "Never", "Never", "Sometimes", "Never", "No comments", "Sometimes", "Sometimes", "Always", "Sometimes"]
from collections import Counter
counter = Counter(data)
counts = list(counter.values())
labels = list(counter.keys())
plt.pie(counts, labels=labels, autopct='%1.1f%%')
plt.savefig('qs1.png', dpi=600, transparent=True, bbox_inches='tight')
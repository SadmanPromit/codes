import matplotlib.pyplot as plt
from collections import Counter
data = ["Always", "Sometimes", "Sometimes", "Sometimes", "Always", "Sometimes", "Always", "Never", "Sometimes", "Sometimes", "Sometimes", "Always", "Never", "Sometimes", "Always", "Always", "Sometimes", "Sometimes", "Sometimes", "Always", "Sometimes", "Sometimes"]
counter = Counter(data)
counts = list(counter.values())
labels = list(counter.keys())
plt.pie(counts, labels=labels, autopct='%1.1f%%')
plt.savefig('qs4.png', dpi=600, transparent=True, bbox_inches='tight')
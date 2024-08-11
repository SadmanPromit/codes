import matplotlib.pyplot as plt
from collections import Counter
data = ["Increasing rapidly", "Constant", "Increased", "Increasing rapidly", "Increasing rapidly", "Increased", "Increased", "Increasing rapidly", "Increased", "Increasing rapidly", "Increased", "Increasing rapidly", "Increased", "Increased", "Increased", "Increased", "Increased", "Increased", "Increasing rapidly", "Increasing rapidly", "Increasing rapidly", "Increasing rapidly"]
counter = Counter(data)
counts = list(counter.values())
labels = list(counter.keys())
plt.pie(counts, labels=labels, autopct='%1.1f%%')
plt.savefig('qs2.png', dpi=600, transparent=True, bbox_inches='tight')
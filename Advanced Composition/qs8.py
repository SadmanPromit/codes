import matplotlib.pyplot as plt
from collections import Counter
data = ["Sometimes", "Sometimes", "Always", "Sometimes", "Sometimes", "Sometimes", "Never", "Sometimes", 
        "Sometimes", "Always", "Sometimes", "Sometimes", "Sometimes", "Sometimes", "Sometimes", "Sometimes", 
        "Sometimes", "Sometimes", "Sometimes", "Sometimes", "Always"]
counter = Counter(data)
counts = list(counter.values())
labels = list(counter.keys())
plt.pie(counts, labels=labels, autopct='%1.1f%%')
plt.savefig('qs8.png', dpi=600, transparent=True, bbox_inches='tight')
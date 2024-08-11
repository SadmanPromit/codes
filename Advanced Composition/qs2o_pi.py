import matplotlib.pyplot as plt
from collections import Counter

data = {
    'More classwork': 40,
    'Be ethical': 35,
    'AI detector enforcement': 20,
    'Not sure': 5
}

counter = Counter(data)
counts = list(counter.values())
labels = list(counter.keys())

plt.pie(counts, labels=labels, autopct='%1.1f%%')
plt.savefig('qs2o_pi.png', dpi=600, transparent=True, bbox_inches='tight')
import matplotlib.pyplot as plt
from collections import Counter

data = {
    'Positive': 66.67,
    'Neutral': 9.52,
    'Negative': 23.81
}

counter = Counter(data)
counts = list(counter.values())
labels = list(counter.keys())

plt.pie(counts, labels=labels, autopct='%1.1f%%')
plt.savefig('qs1o_pi.png', dpi=600, transparent=True, bbox_inches='tight')
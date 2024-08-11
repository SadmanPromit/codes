import matplotlib.pyplot as plt
from collections import Counter
data = ["Strongly agree", "Yes", "Yes", "Strongly agree", "Strongly agree", "Yes", "Yes", "Strongly agree", "Strongly agree", "Neutral", "Strongly agree", "No", "Strongly agree", "Yes", "Neutral", "Neutral", "Neutral", "Neutral", "Strongly agree", "Yes", "Yes", "Strongly agree"]
counter = Counter(data)
counts = list(counter.values())
labels = list(counter.keys())
plt.pie(counts, labels=labels, autopct='%1.1f%%')
plt.savefig('qs3.png', dpi=600, transparent=True, bbox_inches='tight')
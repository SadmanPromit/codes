import matplotlib.pyplot as plt
from collections import Counter
data = ["Yes", "Strongly disagree", "Yes", "Yes", "No", "No", "Strongly agree", "Neutral", "Yes", "Strongly agree",
        "Strongly agree", "Strongly disagree", "Strongly disagree", "No", "No", "Yes", "Neutral", "Yes", "No", "Yes", "Neutral", "No"]
counter = Counter(data)
counts = list(counter.values())
labels = list(counter.keys())
plt.pie(counts, labels=labels, autopct='%1.1f%%')
plt.savefig('qs5.png', dpi=600, transparent=True, bbox_inches='tight')
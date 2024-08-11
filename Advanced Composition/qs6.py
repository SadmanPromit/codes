import matplotlib.pyplot as plt
from collections import Counter
data = ["Agree", "Disagree", "Strongly agree", "Strongly agree", "Agree", "Disagree", "Strongly agree", "Strongly agree",
        "Agree", "Strongly agree", "Strongly agree", "Disagree", "Disagree", "Disagree", "Neutral", "Agree", "Agree", 
        "Neutral", "Neutral", "Agree", "Agree", "Agree"]
counter = Counter(data)
counts = list(counter.values())
labels = list(counter.keys())
plt.pie(counts, labels=labels, autopct='%1.1f%%')
plt.savefig('qs6.png', dpi=600, transparent=True, bbox_inches='tight')
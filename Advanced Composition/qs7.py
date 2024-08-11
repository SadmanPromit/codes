import matplotlib.pyplot as plt
from collections import Counter
data = ["Agree", "Neutral", "Neutral", "Disagree", "Strongly agree", "Agree", "Agree", "Agree", "Strongly agree", 
        "Strongly agree", "Strongly agree", "Strongly agree", "Strongly agree", "Strongly agree", "Strongly agree", 
        "Agree", "Agree", "Agree", "Disagree", "Agree", "Neutral", "Agree"]
counter = Counter(data)
counts = list(counter.values())
labels = list(counter.keys())
plt.pie(counts, labels=labels, autopct='%1.1f%%')
plt.savefig('qs7.png', dpi=600, transparent=True, bbox_inches='tight')
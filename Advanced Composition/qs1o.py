import matplotlib.pyplot as plt
from wordcloud import WordCloud
from collections import Counter
text = """
Yes. Upto 50% of plagiarised assignment for unoriginal content derived from written articles.
No
Depends
No
Yes. It should cause marks deduction.
Depending on the extent of plagiarism e.g if a student copies 100% from AI then penalize them by giving no marks and so on
Of course they should be
Not sure About anything
Not very much
Nope, i Don't think so.
Sometimes
Yes
No comments
Yess, I think student should be penalized at a Highest State
Yes
yes because you cannot go online and just copy-paste your homework!
Yes, because afterward, they will have a chance to realise the importance of utilising their brain. However, it might be acceptable to use AI as long as AI ethics are maintained, and it may also depends.
it's should deduct 50% marks because of plagiarism and rest of the 50% should be given because they at least tried with AI.
No
not appropriate
Yes. Students don't use their own language because of AI
"""
counter = Counter(text.split())
wordcloud = WordCloud(width=800, height=400, max_words=200, background_color='white').generate_from_frequencies(frequencies=counter)
wordcloud.to_file('qs1o.png')
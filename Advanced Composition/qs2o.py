import matplotlib.pyplot as plt
from wordcloud import WordCloud
from collections import Counter
text = """
Presentation based on all written assignments and peer review.
No idea 
Class tests
Teachers as well as students should be provided with Turnitin account 
Students would face marks deduction if AI plagiarism is detected in their work.
Enforce rules against complete plagiarism using AI
Faculties should be very strict about this and should ensure no students atrempts it
Increase open book exams,presentation speech and lab work
Take more class works and group works
Teachers should not suggest ChatGPT in class & students should avoid this as much as possible 
Class practice 
Need creation AI plagiarism tools 
Make the students interested about their given topics and building a mind of doing research related to that specific topic
By generate new AI soft which can detect AI plagiarism 
class tests can be a great alternative to fight AI plagiarism. but yet homework or assignments provide enough time to think properly to solve any situation. I think universities or other educational institutions can provide multiple days to submit any creative assignment but students will have to come to their institutions to complete the assignments supervised by TAs
1. He/she should always be honest to himself/herself 
Teacher should not give a large home work. Homework should be short and based on everyone written home work teacher can take viva. 
Not being able to copyright from books or articles even though the writing itself has been published
Encourage faculty to not give boring assignments.
Use Advanced Plagiarism Detection Software, Promote Original Research
"""
counter = Counter(text.split())
wordcloud = WordCloud(width=800, height=400, max_words=200, background_color='white').generate_from_frequencies(frequencies=counter)
wordcloud.to_file('qs2o.png')
# minify_html: v1 © 2024 Sadman Sakib Khan Promit
import htmlmin

html = """
just html
"""
minified = htmlmin.minify(html, remove_empty_space = True)
with open("index_mini.html", "w") as file:
    file.write(minified)
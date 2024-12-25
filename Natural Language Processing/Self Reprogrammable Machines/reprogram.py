# reprogram: v2 © 2024 Sadman Sakib Khan Promit
from pygments.lexers import PythonLexer
from pygments.token import Token
from pygments import lex

def py_regex(text):
    lexer = PythonLexer()
    python_code = []
    for line in text.splitlines(keepends = True):
        tokens = list(lex(line, lexer))
        if any(
            t[0] in {
                Token.Keyword,
                Token.Name.Function,
                Token.Name.Class,
                Token.Literal,
                Token.Operator,
                Token.Name
            }
            for t in tokens
        ):
            python_code.append(line)
        elif line.strip():
            python_code.append(line)
    return python_code

if __name__ == "__main__":
    try:
        with open("70Binfer_log.txt", "r", encoding = "utf-8") as file:
            program = file.read()
            py_code = py_regex(program)
            print(f"source: {py_code}")
            exec("".join(py_code))
    except Exception as e:
        pass
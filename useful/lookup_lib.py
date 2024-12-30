# lookup_lib: v2 © 2024 Sadman Sakib Khan Promit
import os

lookup = input("lookup: ")
exec("import " + lookup)
exec("print(os.path.dirname(" + lookup + ".__file__))")
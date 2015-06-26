
import sys
from cx_Freeze import setup, Executable

includes = ["pygame", "sys",]

base = None
if sys.platform == "win32":
	base = "Win32GUI"

setup( name = "Yusha",
	   version = "0.0.1",
	   options = {"build_exe" : {"includes" : includes }},
	   executables = [Executable("print.py", base=base)])

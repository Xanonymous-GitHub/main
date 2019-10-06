application_title="Xanonymous_PC_Test"
main_python_file="program.py"
import sys
from cx_freeze import setup, Executable
base=None
if sys.platform == "win32":
  base="Win32GUI"
includes =["atexit","re"]
setup(
  name=application_title,
  version="1.0",
  description="Xanonymous_PC_Test",
  options={"build_exe":{"includes":includes}},
  executables=[Executable(main_python_file,base=base)]
  )

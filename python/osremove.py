import os
cur_path=os.path.dirname(__file__)
os.system('cls')
os.system('mkdir dir2')
os.system('copy osremove.py dir2\copyfile.py')
file=cur_path+'dir2\copyfile.py'
os.system('notepad '+file)

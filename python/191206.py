import random as R
print(''.join(map(str,R.sample([chr(x) for x in range(32,127)],R.randint(8,12)))))
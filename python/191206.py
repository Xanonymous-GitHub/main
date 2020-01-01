import random as R
print(''.join(R.sample([chr(x) for x in range(32, 127)], R.randint(8, 12))))

字典=list()
for x in range(32, 127):
    字典.append(chr(x))
幾個字 = R.randint(8, 12)
挑出的字 = R.sample(字典, 幾個字)
print(''.join(挑出的字))
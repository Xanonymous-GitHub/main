import time,random as R
data=list(map(int,input().split()))
R.seed(time.time())
god_choice=sorted(R.sample([x+1 for x in range(38)],6))
my_choice=list()
for x in data:
    if x in god_choice:my_choice.append(x)
print('lottery:',' '.join(map(str,god_choice)))
print('winning:',' '.join(map(str,my_choice)))
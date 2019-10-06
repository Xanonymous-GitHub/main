#間隔判斷
str_=input()
data=list(str_.lower())
k=input().lower()
point=0
result=[0]
far=0
for x in range(len(data)):
    if data[x]==(k):
        point=x
        break;
while True:
    if (point==len(data)-1):break;
    else:
        if(data[point+1]==k):
            point+=1
            result.append(far+1)
            far=0
        else:
            far+=1
            point+=1
if (result==[0]):print(0)
else:
    for x in range(len(result)-2):print(result[x+1],' ',end='')
    print(result[len(result)-1])

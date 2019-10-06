n=int(input())
data=list(input())
act=list()
num=list()
tmp=list()
nummode=False
minusmode=False
data.append(' ' if len(data)!=0 else '')
for x in range(len(data)):
    if data[x]=='':break
    if data[x]==' ':
        nummode=False
        if minusmode==True:
            num.append(int(''.join(str(e) for e in tmp))*-1)
            minusmode=False
        else:
            num.append(int(''.join(str(e) for e in tmp)))
        tmp.clear()
        continue
    if nummode==False:
        act.append(data[x])
        nummode=True
        continue
    if nummode==True:
        if data[x]=='-':
            minusmode=True
            continue
        tmp.append(int(data[x]))
act=act[::-1]
num=num[::-1]
for x in range(len(act)):
    if act[x]=='+':n-=num[x]
    if act[x]=='-':n+=num[x]
    if act[x]=='*':n/=num[x]
    if act[x]=='/':n*=num[x]
print(int(n))

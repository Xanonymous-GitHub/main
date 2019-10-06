#列出從1到n每個數的3n+1數列並求出其中的哪個數(未必唯一)的數列最長
def caculation(n,k):
    print(int(n),end=',' if n!=1 else '\n',sep='')
    if n==1:result.append(k);return
    if n%2!=0:n=3*n+1
    else:n/=2
    return caculation(n,k+1)
result=list()
for x in range(int(input())):
    print('*',x+1,'=> ',sep='',end='')
    caculation(x+1,1)
for x in range(len(result)):
    if result[x]==max(result):print(x+1,end=',')
print('amount=',max(result),sep='')

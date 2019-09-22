def cal(n,data):
    for x in range(1,n+1):
        if (n%x==0):
            tmp=data[:x]
            for y in range(x,n,x):
                if data[y:y+x]!=tmp:break
                if(y+x>=n):return x
    return n
n=int(input())
data=list(input())
print(cal(n,data))
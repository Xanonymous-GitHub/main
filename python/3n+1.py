while True:
    try:s=input()
    except:break
    def cal(n,k):
        if n==1:return k
        return cal(3*n+1,k+1) if n%2 else cal(n/2,k+1)
    i,j=sorted(map(int,s.split()))
    data=list()
    for x in range(i,j+1):data.append(cal(x,1))
    print(max(data))
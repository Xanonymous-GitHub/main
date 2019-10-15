while True:
    try:s=input()
    except:break
    def cal(n,k):
        if n==1:return k
        return cal(3*n+1,k+1) if n%2 else cal(n/2,k+1)
    [i,j]=list(map(int,s.split()))
    print(i,j,end=' ')
    if i>j:i,j=j,i
    data=list()
    for x in range(i,j+1):data.append(cal(x,1))
    print(max(data))
    print('qwdqwddwdqwdqwdqwdqwdqwdqwdqwdqwdqwdqwdqwdqqwdqwdqwdqwdqwdqwdqwqdqwwdqw')

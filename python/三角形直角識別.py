#三角形擲筊識別
n=int(input())
result=list()
for x in range (n):
    data=list(map(int,input().split()))
    data.sort()
    if (data[0]+data[1]>data[2]):
        verticle=set(data)
        if(len(verticle)<=2):result.append('1 1')
        else:result.append('1 0')
    else:result.append('0')
for x in range(len(result)):print(result[x])

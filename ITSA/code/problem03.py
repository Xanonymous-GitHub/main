n=int(input())
for x in range(n):
    fake_n=input()
    del fake_n
    data=list(map(int,input().split()))
    mytype=list(set(data))
    result=list()
    for y in mytype:result.append(data.count(y))
    print(max(result))
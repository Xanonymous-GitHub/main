n, k = map(int, input().split())
d = list(map(int, input().split()))
f = list(map(int, input().split()))
for t in f:
    l, r = 1, n
    m = (r+l)//2
    while(True):
        if(t == d[m-1]):
            print(m)
            break
        elif(t > d[m-1]):
            l = m+1
        else:
            r = m-1
        m = (r+l)//2
        if(l >= r)and(t != d[m-1]):
            print(0)
            break

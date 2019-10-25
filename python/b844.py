n, q = map(int, input().split())
datas = sorted(list(map(int, input().split())))
a_sks = list(map(int, input().split()))
for ask in a_sks:
    l, r = 1, n
    m = (r+l)//2
    while(r-l):
        if(r < l):
            break
        if (m < 1):
            break
        if(m > n):
            break
        if(ask >= datas[m-1]):
            l = m+1
        else:
            r = m-1
        m = (r+l)//2
        
    if(datas[l-1] > ask):
        l -= 1
    if(l % 2):
        print(1)
    else:
        print(0)
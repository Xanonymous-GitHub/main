n,m=map(int,input().split())
kill=list(map(int,input().split()))
man=[x for x in range(1,n+1)]
for x in kill:
    if (x in man):
        if (man.index(x)<len(man)-1):
            print(man[man.index(x)+1])
            man.pop(man.index(x)+1)
        else:print('0u0 ...... ?')
    else:print('0u0 ...... ?')
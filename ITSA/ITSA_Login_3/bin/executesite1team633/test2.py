n=int(input())
b=n-1
for x in range(n):
    print(' '*b+'*'*(x+1),sep='')
    b-=1
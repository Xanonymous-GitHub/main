n = int(input())
restrict = list(map(int, input().split()))
step = 0
pos = 0
end = n-1
while(pos < n-1):
    if(pos+2 <= n-1):
        if not(restrict[pos+2]):
            step += 1
            pos += 2
            continue
    if(pos+1 <= n-1):
        if not(restrict[pos+1]):
            step += 1
            pos += 1
            continue
print(step)

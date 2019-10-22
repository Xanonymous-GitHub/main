import sys
sys.setrecursionlimit(10**9)


def findtop(data, pos, l, start):
    if data[pos][0] == 0:
        if lengh[start] < l:
            lengh[start] = l
        return
    else:
        for x in range(data[pos][0]):
            findtop(data, data[pos][x+1]-1, l+1, start)


n = int(input())
data = list()
lengh = [0]*n
for x in range(n):
    data.append(list(map(int, input().split())))
for x in range(n):
    findtop(data, x, 0, x)
print(lengh.index(max(lengh))+1, '\n', sum(lengh), sep='')

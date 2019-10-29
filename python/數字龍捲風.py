n = int(input())
way = int(input())
data = list()
s = int(n/2)
t = int(n/2)
for x in range(n):
    data.append(list(input().split()))
print(data[s][t], end='')


def run(amount, way):
    global s, t
    for x in range(amount):
        if way == 0:
            t -= 1
        if way == 1:
            s -= 1
        if way == 2:
            t += 1
        if way == 3:
            s += 1
        print(data[s][t], end='')


for x in range(n-1):
    if way == 0:
        run(x+1, 0)
        run(x+1, 1)
        way = 2
        continue
    if way == 1:
        run(x+1, 1)
        run(x+1, 2)
        way = 3
        continue
    if way == 2:
        run(x+1, 2)
        run(x+1, 3)
        way = 0
        continue
    if way == 3:
        run(x+1, 3)
        run(x+1, 0)
        way = 1
        continue
run(n-1, way)

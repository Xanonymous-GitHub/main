n = int(input())
data = list(map(int, input().split()))
tmp = list()
result = int()
for x in range(len(data)):
    if not(data[x] in tmp):
        tmp.append(data[x])
    else:
        tmp.pop(tmp.index(data[x]))
        result += 1
print(result)

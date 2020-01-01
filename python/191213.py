line = list()
with open("index.txt") as f:
    for x in f:
        tmp = x.replace("\n", "").split(":")
        line.append([tmp[0], list(map(int, tmp[1].split()))])
result = [[] for x in range(6)]
for x in line:
    for y in x[1]:
        result[y-1].append(x[0])
for x in result:
    print(" ".join(x))
t = int(input())


def dunbi(data): return int((data[3]/data[2])*data[3])


def duncha(data): return int((data[3]-data[2])+data[3])


data = list()
for x in range(t):
    data.append(list(map(int, input().split())))
for x in range(t):
    if (data[x][1]-data[x][0]) == (data[x][2]-data[x][1]):
        if (data[x][2]-data[x][1]) == (data[x][3]-data[x][2]):
            for y in range(4):
                print(data[x][y], end=' ')
            print(duncha(data[x]))
    if (data[x][1]/data[x][0]) == (data[x][2]/data[x][1]):
        if (data[x][2]/data[x][1]) == (data[x][3]/data[x][2]):
            for y in range(4):
                print(data[x][y], end=' ')
            print(dunbi(data[x]))

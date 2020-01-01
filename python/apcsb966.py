while True:
    try:
        n = int(input())
    except:
        break
    data = list()
    maax = list()
    miin = list()
    for x in range(n):
        data.append(list(map(int, input().split())))
    for x in range(n):
        maax.append(data[x][1])
        miin.append(data[x][0])
    result = [0]*(max(maax)-min(miin))
    for x in range(n):
        for y in range(maax[x]-miin[x]):
            result[miin[x]-min(miin)+y] = 1
    print(result.count(1))

def sliper(tdata):
    result=list()
    for x in range(len(tdata[0])):
        tmp=list()
        for y in range(len(tdata)):tmp.append(tdata[y][x])
        result.append(tmp);del tmp
    result.reverse()
    return result
while True:
    try:line=input()
    except:break
    [r,c,m]=map(int,(line.split()));del m
    data=[list(map(int,input().split())) for x in range(r)]
    operate=input().split();operate.reverse()
    for x in operate:
        if int(x)==0:data=sliper(data)
        if int(x)==1:data.reverse()
    print(len(data),len(data[0]))
    for x in range(len(data)):
        for y in range(len(data[0])-1):print(data[x][y],'',end='')
        print(data[x][len(data[0])-1])

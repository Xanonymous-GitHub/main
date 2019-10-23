while True:
    try:
        line = input()
    except:
        break
    # get user data
    # get original password => psd.
    psd = list(map(int,list(line)))
    # get n
    n = 5
    # get wrong password
    data = list()
    for x in range(n):
        data.append(list(map(int,list(input()))))
    # print the result.
    # tmp=psd
    tmp = []
    tmp = psd.copy()
    for x in range(n):
        a = 0
        b = 0
        psd = tmp.copy()
        # judge whether The value of the number is correct and is in the correct position first (A).
        for y in range(len(psd)):
            if(data[x][y] == psd[y]):
                data[x][y] = -1
                psd[y] = -1
                a += 1
        # judge whether The value of the word is correct, but not in the correct position. (B)
        for y in range(len(psd)):
            if((data[x][y] != -1)and(data[x][y] != psd[y])and(data[x][y]in psd)):
                b += 1
        print(a, 'A', b, 'B', sep='')

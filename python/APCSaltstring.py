def Caculate(_str, N):
    if len(list(_str)) == 1:
        return 1
    result = list()
    for x in range(len(_str)):
        _str[x] = _str[x].isupper()
    count = ['']*(len(_str)-(N-1))
    for x in range(len(_str)-(N-1)):
        temp = 0
        for y in range(N):
            temp += int(_str[x+y])
        if not(temp % N):
            count[x] = int(temp/N)
    for x in range(N):
        pretemp = ''
        howmany = 0
        for y in range(int((len(count)-(x+1))/N)):
            temp = ''
            left = count[y*N+x]
            right = count[(y+1)*N+x]
            temp += str(left)
            temp += str(right)
            if (not(count[y*N+x] == ''))and(not(count[(y+1)*N+x] == ''))and(not(left == right)):
                if howmany == 0:
                    howmany = 1
                    result.append(N)
                elif (list(temp) == list(reversed(pretemp))):
                    howmany += 1
            elif (not(count[y*N+x] == ''))or(not(count[(y+1)*N+x] == '')):
                if howmany == 0:
                    result.append(N)
                elif not(howmany == 0):
                    result.append((howmany+1)*N)
                howmany = 0
            elif not(howmany == 0):
                result.append((howmany+1)*N)
            pretemp = temp
        if not(howmany == 0):
            result.append((howmany+1)*N)
    result.sort(reverse=True)
    if (result == []):
        return 0
    else:
        return result[0]


print('大學程式設計先修檢測A.P.C.S.-171028交錯字串Alternating Strings-Xanonymous (多測資)')
while True:
    try:
        line = input()
    except:
        break
    N = int(line)
    _str = input()
    print(Caculate(list(_str), N))
    print()

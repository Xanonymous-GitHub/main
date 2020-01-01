def recursion(a, b, n):
    if len(result) == n:
        totals.append(result)
        print(result)
        return
    for x in range(a, b+1, 1):
        result.append(x)
        recursion(x+1, b, n)
        result.remove(x)


while True:
    print('>>>>>>>>>>>>>>>   combination   <<<<<<<<<<<<<<<')
    [b, n] = map(int, input('#_C_<m n>=: ').split())
    if n > b-n:
        n = b-n
    result = []
    totals = []
    recursion(1, b, n)
    print('-------------------------------------------')
    print('Total:', len(totals), '\n')

# 計算範圍內所有連續自然數的最小公倍數,版本181108
print('----Least Common Multiple Within Range, MadeBy Xanonymous.----', end='')
while True:
    print('\n>>> ', end='')
    [a, b] = sorted(map(int, input().split()))
    if (a <= 0)or(b <= 0):
        print('Violated.')
        continue
    under = list()
    degree = list()
    for x in range(a, b+1, 1):
        tmp = x
        current = 1
        while tmp != 1:
            count = 0
            current += 1
            while tmp % current == 0:
                count += 1
                tmp /= current
            if current in under:
                if degree[under.index(current)] < count:
                    degree[under.index(current)] = count
            else:
                under.append(current)
                degree.append(count)
    result = 1
    for x in range(len(under)):
        result *= under[x]**degree[x]
    print(result, end='\n<<<\n')

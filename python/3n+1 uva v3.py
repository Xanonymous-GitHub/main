import sys
while True:
    try:
        i, j = map(int, input().split())
    except:
        break
    if i > j:
        i, j = j, i
    m = [0, 0, 0, 1]
    sys.stdout.write("[%s]" % (" " * 40))
    sys.stdout.flush()
    sys.stdout.write("\b" * (40+1))
    for x in range(i, j+1):
        m = [x, 0, m[2], m[3]]
        while True:
            m[1] += 1
            if m[0] == 1:
                break
            m[0] = ((m[0]*3+1)if m[0] % 2 != 0 else(m[0]/2))
        if m[1] > m[2]:
            m[2] = m[1]
            m[3] = x
        sys.stdout.write("-")
        sys.stdout.flush()
    print(m[3], '>>>', m[2])

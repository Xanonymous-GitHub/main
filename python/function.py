data = list(input())
l = len(data)


def f(x, n):
    global data
    x *= 2
    data.pop(n+1)
    data[n] = x


def g(x, y, n):
    global data
    x = 3*x+2*y
    for x in range(2):
        data.pop(n+1)
    data[n] = x


def h(x, y, z, n):
    global data
    x = 6*x+3*y-2*z+1
    for x in range(3):
        data.pop(n+1)
    data[n] = x


for x in range(l-1, -1, -1):
    if data[x] == 'f'or'g'or'h':
        if data[x] == 'f':
            f(int(data[x+1]), x)
        if data[x] == 'g':
            g(int(data[x+1]), int(data[x+2]), x)
        if data[x] == 'h':
            h(int(data[x+1]), int(data[x+2]), int(data[x+3]), x)
    else:
        continue
print(int(data[0]))

# e331
def caculate(X, Y, l, u, n):
    result = int()
    X.sort()
    Y.sort(reverse=True)
    for x in range(n):
        if (((X[x]+Y[x]) >= l) and ((X[x]+Y[x]) <= u)):
            result += ((X[x]+Y[x])-l)
        elif ((X[x]+Y[x]) > u):
            result += u
    return result


while True:
    # get user data
    try:
        line = input()
    except:
        break
    t = int(line)
    for x in range(t):
        n, l, u, k = map(int, input().split())
        X = list(map(int, input().split()))
        Y = list(map(int, input().split()))
        # get ban list accroding to k
        ban = list()  # ban is a Two-dimensional array.
        for x in range(k):
            ban.append(map(int, input().split()))
        # caculate the data and print the result.
        print(caculate(X, Y, l, u, n))

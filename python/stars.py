while True:
    line = input()
    if line == "":
        break
    n = int(line)
    for x in range(n):
        print(" "*(n-x-1), "*"*(2*x+1))
    for v in range(n-1):
        print(" "*(v+1), "*"*(2*(n-v)-3))

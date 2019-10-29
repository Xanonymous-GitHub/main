data = list(map(int, input().split()))
tmp = 0
max_ = 0
for x in range(len(data)):
    if tmp > max_:
        max_ = tmp
    if tmp+data[x] > 0:
        tmp += data[x]
    else:
        tmp = data[x]
print(max_)


'''

3
10
1 2 2 3 3 3 4 5 5 6
12
1 1 1 2 2 3 4 7 8 8 9 9
18
1 1 1 2 2 3 4 4 4 4 4 5 6 6 7 8 8 9
'''

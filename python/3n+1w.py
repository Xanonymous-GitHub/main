def kioro(num):  # 判斷奇數偶數
    if(num % 2) == 0:
        return 1
    else:
        return 0


def count_(num):  # 計算3n+1的次數
    len_ = 0
    while num != 1:
        if(kioro(num) == 0):
            num = num*3+1
            len_ += 1
        else:
            num = num//2
            len_ += 1
    return len_+1


def findmax(x, y):  # 取得數據之中的計算結果的最大值
    print(x, y, end=" ")
    if x > y:
        x, y = y, x
    max_ = 0
    for k in range(x, y+1, 1):
        if count_(k) > max_:
            max_ = count_(k)
    print(max_)
    return


while True:  # 多測資
    try:
        line = input()
    except:
        break
    data = list(map(int, line.split()))
    findmax(data[0], data[1])

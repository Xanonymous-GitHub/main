i, j = map(int, input().split())  # 分隔同行輸入
lenth = list()  # 儲存長度數列
print(i, j)
if i > j:
    i, j = j, i  # 若i較大 前後交換
for x in range(i, j):  # 有限迴圈
    data = list()  # 3n+1數列
    # data.append(x)
    print(x)
    while x != 1:  # 算出數列
        if x % 2 == 0:
            x = x/2
            data.append(x)
        else:
            x = x*3+1
            data.append(x)
    lenth.append(len(data))  # 將長度加入長度數列
print(max(lenth))  # 找最大

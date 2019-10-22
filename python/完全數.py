'''>>> Xanonymous Official Python coding performance,All codes were completed. <<<'''
import sys
sys.setrecursionlimit(1000000)  # 為了能夠使用下方的Recursion而加入


# 練習：求1~1000中所有能被3整除的數(1行即可,以逗號分隔)
for h in range(1000):
    print(h+1, end=',') if not((h+1) % 3) else print(end='')


'''作業:寫一程式計算2到1000間所有完全數並列印出來'''

print('\n\n完全數Recursion版輸出:\n')


# ---僅2行的Recursion版本--------------
def x(p, q, r): return r if q == 1 else x(
    p, q-1, r+(p/q) if not(p % q) else r+0)


for i in range(999):
    print(i+2, '是完全數') if x(i+2, i+2, 0) == i+2 else print(end='')
# -------------------------------------


print('\n', '完全數標準版輸出:\n', sep='')


# ----標準版本(老師網站填空的解答)----
for i in range(2, 1000, 1):
    sum = 0
    for j in range(1, i, 1):
        if i % j == 0:
            sum = sum+j
    if sum == i:
        print(sum, '是完全數')
# --------------------------------

import urllib.request
import os
urllib.request.urlretrieve(
    'https://onedrive.live.com/download?cid=3DD03CC92A52BF65&resid=3DD03CC92A52BF65%2155482&authkey=APvq6-yYHNmBe0U', 'code.txt')
print(open('code.txt').read())
print('>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>')
print('*實際測試程式執行結果為: ', end='')
n = 2  # 定義變數n初值為2(最小質數)
'''Program Start.'''
while True:  # 無窮迴圈
    result = list()  # 建立一個空的清單來存放因數
    ''''''
    for x in range(1, n+1, 1):  # 重複判斷n次
        if n % x == 0:
            result.append(x)  # 如果目前的x值是n的因數
        # 那麼，就將此因數存放至result清單中
    ''''''
    if len(result) == 30:  # 如果存放的因數是30個
        print(n, sum(result))  # 那麼，就顯示出此數字n
        # 以及目前result清單中的所有因數和
        break  # 停止無窮迴圈，程式結束
    n += 1  # n加一，下一個循環
    del result  # 刪掉result清單
print('\n請比對此答案是否正確無誤。')
os.remove('code.txt')
while True:
    True

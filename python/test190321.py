data, n = [0], float(input('請輸入第1筆資料：'))
while n != -1:
    data.append(n)
    n = float(input('請輸入第'+str(len(data))+'筆資料：'))
print('總分：', sum(data), '\n', '平均：', float(
    sum(data)/(len(data)-1) if len(data) != 1 else sum(data)), sep='')
input()

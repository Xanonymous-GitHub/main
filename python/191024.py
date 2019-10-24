def X(a, b, c): return [sum((x**2) for x in range(a, b+1, c))]
a = int(input('請輸入第1個數字:'))
b = int(input('請輸入第2個數字:'))
print('=>\n數字 {} 加到 數字 {} 的平方總和為 {}'.format(a, b, X(a, b, 1)[0]))
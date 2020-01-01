result=list()
for x in range(100):
    for y in range(100):
        if abs(2**x-3**y)==665:
            result.append(str(x+','+y))
        else:
            print(x,y,end='')
result

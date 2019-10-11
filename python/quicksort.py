def qs(data):
    if len(data)>1:
        big,small,center=list(),list(),list()
        for x in data:
            if x>data[0]:big.append(x)
            if x==data[0]:center.append(x)
            if x<data[0]:small.append(x)
        return qs(small)+center+qs(big)
    else:return data
print(qs(list(map(int,input().split()))))
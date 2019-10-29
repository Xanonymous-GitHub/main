d = list()
for x in range(8):
    t = int(input())
    if t <= 100:
        d.append(t)
b = sum(d)/len(d)
print(b)
m = int()
for x in range(len(d)):
    m += d[x]**2
print((m/len(d)-b**2)**(1/2))

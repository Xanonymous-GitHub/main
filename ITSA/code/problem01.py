r=float(input())
n=int(input())
p=float(input())
result=float()
for x in range(n):
    result+=p
    result+=result*r
print(int(result))
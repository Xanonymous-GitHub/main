import math
n=int(input())
p=[10,9,8,7,6,5,4,3,2,1,0]
for x in range(n):
    point=list(map(float,input().split()))
    x=float(abs(point[0]-10))
    y=float(abs(point[1]-10))
    distance=float()
    distance=(x*x+y*y)**(1/2)
    if(int(distance)<=10):
        print(p[int(distance)])
    else:print(0)
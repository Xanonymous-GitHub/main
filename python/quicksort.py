def qs(data):
    #find the low & high
    low,high=1,len(data)-1
    #low=>from left,the first num which smaller than data[0]
    while (data[low]>=data[0])and(low<len(data)-1):low+=1
    #high=>from right,the first num which bigger than data[0]
    while (data[high]<=data[0])and(high>0):high-=1
    if low>high:data[low],data[high]=data[high],data[low]
    else:
        data[0],data[low]=data[low],data[0]
        #left branch
        qs(data[:low])
        #right branch
        qs(data[low:])
    return
data=list(map(int,input().split()))
qs(data)
print()
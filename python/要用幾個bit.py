while True:
    try:i=input()
    except:break
    data=int(i)
    n=0
    if(data>0):
        while ((2**n)-1<=data):n+=1
        print(n+1)
    if(data<0):
        while ((-2)**n>=data):n+=1
        print(n+1)

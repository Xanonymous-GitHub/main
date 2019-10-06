while True:
        # > The problem requires multiple test materials.
    try:i,j=map(int,input().split())
        # > i,j is the range of data entered by user.
    except:break
        # > Stop the program when the input is over.
    def lenghgenerater(n,step):
        while True:
                # > start to caculate the 3n+1 of n.
            step+=1
                # > Recording steps.
            if n==1:return step
                # > Stop calculation until the calculated value is equal to 1.
            n=(3*n+1 if n%2 !=0 else n/2)
                # > If the number is odd, multiply by 3 and add 1 else divide by 2.
    lengh=list()
    print(i,j,end=' ')
    if i>j:i,j=j,i
    for x in range(i,j+1):lengh.append(lenghgenerater(x,-1))
    print(max(lengh))

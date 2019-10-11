def qs(data):
    if data==[]:return []
    SFR=len(data)-1
    BFL=0
    while(BFL!=SFR):
        while(SFR>0 and data[SFR]>=data[0]):SFR-=1
        while(BFL!=SFR and BFL<len(data)-1 and data[BFL]<=data[0]):BFL+=1
        if(BFL!=SFR):data[SFR],data[BFL]=data[BFL],data[SFR]
    data[0],data[BFL]=data[BFL],data[0]
    return qs(data[:BFL])+[data[BFL]]+qs(data[BFL+1:])
print(qs(list(map(int,input().split()))))
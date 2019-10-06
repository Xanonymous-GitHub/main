def Caculate (_str,N):
    if len(list(_str))==1:return 1
    result=list()
    for x in range(len(_str)):_str[x]=_str[x].isupper()
    #轉換成大寫都是true
    count=['not']*(len(_str)-(N-1))#創造一個陣列
    #search for first alt str
    for x in range(len(_str)-(N-1)):#分割判斷
        temp=0
        for y in range(N):temp+=int(_str[x+y])        
        if not(temp % N):count[x]=int(temp/N)#temp是N的倍數
    #判斷的頭，共有N個頭,(len(count)-1)/2
    howmany=0 #暫時放這裡
    for x in range(N):
        pretemp=''
        howmany=0
        for y in range(int((len(count)-(x+1))/N)):
            temp=''
            left=count[y*N+x]
            right=count[(y+1)*N+x]
            temp+=str(left)
            temp+=str(right)
            if (not(count[y*N+x]=='not'))and(not(count[(y+1)*N+x]=='not'))and(not(left==right)):
                if howmany==0:
                    howmany=1
                    result.append(N)
                elif (list(temp)==list(reversed(pretemp))):howmany+=1
            elif (not(count[y*N+x]=='not'))or(not(count[(y+1)*N+x]=='not')):
                if howmany==0:result.append(N)
                else:
                    if not(howmany==0):result.append((howmany+1)*N)
                howmany=0
            else:
                if not(howmany==0):result.append((howmany+1)*N)
            pretemp=temp
        if not(howmany==0):result.append((howmany+1)*N)
    result.sort(reverse=True)
    if (result==[]):return 0
    else:return result[0]
N=int(input())#每幾個一數?
_str=input()# user's input
print(Caculate(list(_str),N))#result


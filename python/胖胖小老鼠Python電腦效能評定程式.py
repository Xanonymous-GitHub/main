import time
import math
from random import randint
while True:
  print("=======Xanonymous 胖胖小老鼠Python電腦效能評定程式 Build_180823A_3.7.0 =======")
  try:line=input("\n指定負載係數(建議1~50，數字越高越準確)? ->:")
  except:break;
  n=int(line)
  speed=0#float(input("速度? ->:"))#,評定電腦性能一律開到最高速
  num=100000#int(input("幾組? ->:")),預設100000組
  line=0
  list_p=list()
  i=0
  total=0
  variance=0
  numinwhile=0
  getn=0
  perfect=True
  print("即將開始測試電腦性能，請勿控制電腦並耐心等候直到結束......")
  for k in range(9,0,-1):
    time.sleep(0.5)
    if k%3==0:
      print(k//3,end=" ")
    else:
      print(". ",end="")
  times=0.0
  timeo=0.0
  times=time.time()
  for x in range(0,num,1):
    while numinwhile<n:
      timeo=time.time()
      if float(timeo-times)>30:
        perfect=False
        numinwhile=n+1
      time.sleep(speed)
      list_p.append(str(randint(10,99))+"")
      print(list_p[i],end="",sep="")
      total+=int(list_p[i])
      i+=1
      line+=1
      if line > n-1:
        line=0
        list_p.sort()
        for k in range(1,n+1,1):
          print(list_p[k-1],end="",sep="")
          variance+=(int(list_p[k-1])-total//n)**2
        print(total//n,end="",sep="")
        print(round(math.sqrt(variance//n),(n//2)),end="",sep="")#標準差
        list_p.clear()
        i=0
        average=0
        variance=0
        total=0
      numinwhile+=1
    numinwhile=0
    timeo=time.time()
  if perfect==True:
    print("\n==========================================================================")
    print("\n\n\n您的電腦目前的性能指數為",int((num*n)//round(float(timeo-times),5)),"@",n,"Build_180821A3.7.0\n\n\n")
    print("==========================================================================")
  else:
    print("\n==========================================================================")
    print("\n\n\n您的電腦不支援如此龐大的負載係數!請降低後再試一次!","Build_180821A\n\n\n")
    print("==========================================================================")
  

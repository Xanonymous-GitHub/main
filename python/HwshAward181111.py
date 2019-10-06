'''
This prgram is made by 林天佑,20181111. All rights reserved.
"#"字號後方之紅色文字為註解，非程式碼。
''''''
#科學報第十一期有獎徵答題目
#本期的有獎徵答主角：數學因數。
#(1)求有 30 個正因數的最小正整數？(2)承(1)此數所有正因數的和?
'''''''''
n=2   #定義變數n初值為2(最小質數)
'''Program Start.'''
while True: #無窮迴圈
    result=list()   #建立一個空的清單來存放因數
    ''''''
    for x in range(1,n+1,1):    #重複判斷n次
        if n%x==0:result.append(x)  #如果目前的x值是n的因數
        #那麼，就將此因數存放至result清單中
    ''''''
    if len(result)==30: #如果存放的因數是30個
        print(n,sum(result))    #那麼，就顯示出此數字n
                #以及目前result清單中的所有因數和
        break;  #停止無窮迴圈，程式結束
    n+=1#n加一，下一個循環
    del result  #刪掉result清單
'''Program Stop.'''

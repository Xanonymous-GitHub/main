import time,random as R
def main():
    #接收輸入資料並以空格分開再轉換為int型別存為list
    data=list(map(int,input().split()))
    #根據現在時間重製亂數種子
    R.seed(time.time())
    #在1～38中，選取6個不重複的結果，除存到god_choice串列中，並順便排序(由小到大)
    god_choice=sorted(R.sample([x+1 for x in range(38)],6))
    #建立空串列來儲存中獎的號碼
    my_choice=list()
    for x in data:
        #從輸入的號碼串列依序比對
        #如果發現輸入的號碼在god_choice裡面，表示中獎(那個號碼)，就把這個號碼放到my_choice中
        if x in god_choice:my_choice.append(x)
    #印出結果，先印出項目文字，再印出以空格分開的(int轉str類型)的每一項串列元素
    print('lottery:',' '.join(map(str,god_choice)))
    print('winning:',' '.join(map(str,my_choice)))
if __name__=='__main__':main()#如果不是被當成模組就執行
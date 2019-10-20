import time,random as R
#在1～38中，選取6個不重複的結果，並順便排序(由小到大)
def god_choice():return sorted(R.sample([x+1 for x in range(38)],6))
def my_choice(data,god_number):
    result=list()
    for x in data:
        #從輸入的號碼串列依序比對
        #如果發現輸入的號碼在god_number裡面，表示中獎(那個號碼)，就把這個號碼放到result中
        if x in god_number:result.append(x)
    return sorted(result)
def main():
    #接收輸入資料並以空格分開再轉換為int型別存為list
    data=list(map(int,input().split()))
    #根據現在時間重製亂數種子
    R.seed(time.time())
    #取得神選數字(開獎號碼)
    got_number=god_choice()
    #印出結果，先印出項目文字，再印出以空格分開的(int轉str類型)的每一項串列元素
    print('lottery:',' '.join(map(str,got_number)))
    print('winning:',' '.join(map(str,my_choice(data,got_number))))
if __name__=='__main__':main()#如果不是被當成模組就執行main
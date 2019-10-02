def prime(m,c):#用來判斷是否是質數的函式
	while(m-c):#若c還沒有跟n一樣大就執行
		#如果m被任何一個非1的數整除就退出函式
		if (m%c==0):return
		c+=1#下一個除數
	#如果m不能被所有小於自己但不是1的數整除
	#那麼m就是個質數，輸出m
	print(m)
def main():
	n=int(input())#接收使用者輸入並轉換為整數型別
	#測試從2到n-1的所有整數是否為質數，prime(被測數,被測數之最小待測非1因數)
	for x in range(2,n):prime(x,2)
#分辨程式是被當成模組還是被直接執行，若是直接執行則開始main函式
if __name__=='__main__':main()
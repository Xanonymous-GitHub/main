# p9取5示範
# 箱子選數字
count=int()#計數器
def division(db,c,m):#遞迴,db=範圍,c=5個相異箱子集合,m=還剩幾個箱子可裝
    global count#放入計數器
    if m==0:#當c中的箱子都滿時
        print(c,end='')#輸出c中的所有箱子
        count+=1#計數器+1
        return#停止裝箱
    for x in db:
        c.append(x)#c中的箱子(依序)挑選一個數字
        db.remove(c[-1])#因為那個數字被挑了所以從範圍中清掉
        #>>> 遞迴前
        division(db,c,m-1)#'''遞迴丟出，下一個人去做吧'''
        #<<< 遞迴後(完全回復所有操作)
        db.append(c[-1])#加回剛剛被清掉的數字到範圍中
        db.sort()#由於是加在最後,還沒完全回復,所以用排序來做最終復原
        c.pop()#清掉放入c中的某個箱子的那個數字

db=[0,1,2,3,4,5,6,7,8,9]
division(db,[],5)
print(count)
input()

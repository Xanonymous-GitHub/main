import random as R  # random名字太長，自訂名稱為'R'


def output(i, S, H, D, C):
    print('S ', end='')  # 輸出花色代表字母
    for x in range(13):
        # 針對花色S來看，如果那張牌被發到編號i的玩家
            # 就輸出這張牌的數字
        if S[x][1] == i:
            print(S[x][0], end='', sep='')
    print()  # 換行
    print('H ', end='')  # 輸出花色代表字母
    for x in range(13):
        # 針對花色H來看，如果那張牌被發到編號i的玩家
            # 就輸出這張牌的數字
        if H[x][1] == i:
            print(H[x][0], end='', sep='')
    print()  # 換行
    print('D ', end='')  # 輸出花色代表字母
    for x in range(13):
        # 針對花色D來看，如果那張牌被發到編號i的玩家
            # 就輸出這張牌的數字
        if D[x][1] == i:
            print(D[x][0], end='', sep='')
    print()  # 換行
    print('C ', end='')  # 輸出花色代表字母
    for x in range(13):
        # 針對花色C來看，如果那張牌被發到編號i的玩家
            # 就輸出這張牌的數字
        if C[x][1] == i:
            print(C[x][0], end='', sep='')
    print()  # 換行


def main():  # 程式進入點
    card = list('A23456789TJQK')  # 撲克牌樣板串列
    area = ['North:', 'East:', 'South:', 'West:']  # 玩家名字
    # S,H,D,C分別代表著4個不同的花色
    # 每個花色有13張
    # 每張牌都要發
    # 所以，用1～4代表這張牌要發給誰，每張牌都隨機儲存著這個數字
    # 每個花色串列會有13項，每一項包含兩個資訊：數字和隨機號碼(發給誰)
    # 大概可以寫成這樣：[[數字,發給誰],[數字,發給誰],[數字,發給誰],[數字,發給誰]....]
    # 存取內容時就像這樣：花色[(第幾號內容，第一項是0不是1)][(該項目的哪一項，第一項是0不是1)]
    # [[]for x in range()]的寫法相當於(假設something是個空串列長這樣:[])
    # for x in range():
    # <Something>.append([])
    S = [[]for x in range(13)]
    H = [[]for x in range(13)]
    D = [[]for x in range(13)]
    C = [[]for x in range(13)]
    # 用for迴圈來位每張牌發配隨機數字
    # append()方法可以把東西塞入串列的最後方
    for i in range(13):
        # SHDC四個串列原本是空的([[],[],[],[],[],[],[],[],[],[],[],[],[]])
        # 迴圈會把牌的數字和要發給誰的號碼一起放到花色串列裡
        S[i].append(card[i])  # 放數字
        S[i].append(R.randint(1, 4))  # 隨機放入1～4的某個數字
        H[i].append(card[i])  # 放數字
        H[i].append(R.randint(1, 4))  # 隨機放入1～4的某個數字
        D[i].append(card[i])  # 放數字
        D[i].append(R.randint(1, 4))  # 隨機放入1～4的某個數字
        C[i].append(card[i])  # 放數字
        C[i].append(R.randint(1, 4))  # 隨機放入1～4的某個數字
    # 用迴圈輸出結果
    for x in range(4):
        print(area[x])  # 輸出玩家名稱
        # output函式會傳送一個數字和四條已經發好的花色牌串列
        # 數字代表現在要輸出誰的牌
        output(x+1, S, H, D, C)  # x從0開始數，所以記得要加一


if __name__ == '__main__':
    main()  # 如果這檔案不是被import就執行main

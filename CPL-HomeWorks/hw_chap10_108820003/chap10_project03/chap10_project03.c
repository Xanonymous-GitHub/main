/*****************************************************************/
/* Class: Computer Programming, Fall 2019                        */
/* Author: 林天佑                                                 */
/* ID: 108820003                                                 */
/* Date: 2019.11.17                                              */
/* Purpose: 程式碼我一定要全部自己寫，寧願因此被扣分！                  */
/* Purpose: 別擔心。我依然按照著題目的要求在寫，只是過程不同而已。        */
/* GitHub:  https://github.com/Xanonymous-GitHub/main/tree/HW    */
/*****************************************************************/

//@->注意，本題寫法與10_2完全不同，且使用5x2陣列來儲存手牌。

#include <stdio.h>
#include <string.h>

int card[5][2] = {0};
int num = 0;    //紀錄目前已經讀取了幾張合法牌
int result = 0; //紀錄結果種類

typedef struct card_counter {
    int pairs[2][2]; //{{是否達標,值},{是否達標,值}}
    int three[2];    //{延續數量},延續值}
    int straight[2]; //{上次判斷的值,符合條件數量}
    int flush[2];    //{上次判斷的值,符合條件數量}
} counter;

int read_cards() {
    int i, continue_flag = 0;
    memset(card, 0, sizeof(card)); //清空手牌
    num = 0;                       //手牌為0張
    result = 0;                    //預設為High card
    while (num < 5) {              //拿5張
        char tmp[2];               //暫存數字及花色的陣列
        printf("Enter a card: ");  //顯示輸入訊息
        scanf("%s", tmp);          //讀取輸入

        if (tmp[0] == '0') //若為0則停止程式執行
        {
            return 0; //回傳false結束main函式
        }

        if ((tmp[0] - '0' <= 9) && (tmp[0] - '0' >= 2)) {
            //假設為合法輸入，若為數字，將該字元轉為數字，以符合card陣列格式。
            tmp[0] -= '1';
        } else {
            //假設為合法輸入，若為英文字母，將該字元轉為數字，以符合card陣列格式。
            switch (tmp[0]) {
            case 't':
            case 'T':
                tmp[0] = 9;
                break;
            case 'j':
            case 'J':
                tmp[0] = 10;
                break;
            case 'q':
            case 'Q':
                tmp[0] = 11;
                break;
            case 'k':
            case 'K':
                tmp[0] = 12;
                break;
            case 'a':
            case 'A':
                tmp[0] = 0;
                break;
            default:
                //非法輸入，顯示錯誤訊息，重新要求用戶輸入
                printf("Bad card; ignored.\n");
                continue;
            }
        }

        //判斷花色，將該字元轉為數字，以符合card陣列格式。
        switch (tmp[1]) {
        case 'c':
        case 'C':
            tmp[1] = 0;
            break;
        case 'd':
        case 'D':
            tmp[1] = 1;
            break;
        case 'h':
        case 'H':
            tmp[1] = 2;
            break;
        case 's':
        case 'S':
            tmp[1] = 3;
            break;
        default:
            //非法輸入，顯示錯誤訊息，重新要求用戶輸入
            printf("Bad card; ignored.\n");
            continue;
        }

        for (i = 0; i < num; i++) {
            if ((card[i][0] == tmp[0]) && (card[i][1] == tmp[1])) {
                //重複輸入，顯示錯誤訊息，重新要求用戶輸入
                printf("Duplicate card; ignored.\n");
                continue_flag = 1; //標記將要重新要求輸入
                break;
            }
        }
        if (continue_flag) //若標記將要重新要求輸入
        {
            continue_flag = 0; //還原標記
            continue;          //要求重新輸入
        }

        card[num][0] = tmp[0]; //填入牌陣列
        card[num][1] = tmp[1]; //填入牌陣列
        num++;                 //手排數+1
    }
    return 1; //正確拿5張，回傳true
}
int analyze_hand() {
    //先將手牌整理好(此處選用"選擇排序法")
    int base, min, count;

    for (base = 0; base < 5 - 1; base++) //判斷到倒數第一位
    {
        min = base;                                //預設最小值是在基底
        for (count = base + 1; count < 5; count++) //開始判斷基底後的所有
        {
            if (card[count][0] < card[min][0]) //如果這項小於基底
            {
                min = count; //將最小項位置設定到這個位置
            }
        }
        /*
            找到後，將最小數與基底交換
        */
        int tmp = card[min][0];
        card[min][0] = card[base][0];
        card[base][0] = tmp;

        tmp = card[min][1];
        card[min][1] = card[base][1];
        card[base][1] = tmp;
    }
    /*
        定義物件c:
        pairs預設兩個(儲存槽)都沒有(空)
        three預設已經連續1個數字
        straight預設前一項是-1，0組符合結果
        flush預設前一項是-1，0組符合結果
    */
    counter c = {{{0, -1}, {0, -1}}, {1, -1}, {-1, 0}, {-1, 0}};

    for (base = 0; base < 5; base++) //依序尋訪手牌
    {
        //判斷順，連續五張數字連續叫做順，包括10JQKA，但不包括JQKA2,QKA23,KA234
        if ((c.straight[0] == -1) || (c.straight[0] == card[base][0] - 1) || ((c.straight[0] == 0) && card[base][0] == 9)) {
            /*
                達成以下任一條件就將順的成功延續筆數加：
                1.尚未判斷任何牌
                2.當前判斷牌數字是上一次判斷的牌的數字+1
                3.上次判斷的是A(ace)，且現在判斷的是T(10)
            */
            c.straight[0] = card[base][0];
            c.straight[1]++;
        } else {
            c.straight[0] = -1;
            c.straight[1] = 0;
        }

        //判斷同花，連續五張花色一樣叫做同花
        if ((c.flush[0] == -1) || (c.flush[0] == card[base][1])) {
            /*
                達成以下任一條件就將順的成功延續筆數加：
                1.尚未判斷任何牌
                2.當前判斷牌花色等於上一次判斷的牌的花色
            */
            c.flush[0] = card[base][1];
            c.flush[1]++;
        } else {
            c.flush[0] = -1;
            c.flush[1] = 0;
        }

        if (((c.three[0] == 1) || (c.three[0] == 2)) && (c.three[1] == card[base][0])) {
            //判斷是否有3張數字一樣的牌，如果已經連續1張或2張數字一樣，就再看看會不會再度連續，如果是，連續數+1
            c.three[0]++;
        } else if (c.three[0] != 3) {
            //如果沒連續到，就重置three狀態為已經連續了1張(當下這張)
            c.three[0] = 1;
            c.three[1] = card[base][0];
        }

        if (!(c.pairs[0][0])) //若pairs儲存槽A為尚未達標
        {
            if (c.pairs[0][1] == card[base][0]) //若儲存槽A的值為現在判斷的牌的數字
            {
                c.pairs[0][0] = 1; //設定儲存槽A為已達標
            } else                 //否則將儲存槽A之值設為當前的牌的數字
            {
                c.pairs[0][1] = card[base][0];
            }
        } else if (!(c.pairs[1][0])) //若pairs儲存槽A為達標且pairs儲存槽B為尚未達標
        {
            if (c.pairs[1][1] == card[base][0]) //若儲存槽B的值為現在判斷的牌的數字
            {
                c.pairs[1][0] = 1; //設定儲存槽B為已達標
            } else                 //否則將儲存槽B之值設為當前的牌的數字
            {
                c.pairs[1][1] = card[base][0];
            }
        }
    }
    if ((c.flush[1] == 5) && (c.straight[1] == 5)) {
        //如果產生同花且產生順，那就是同花順
        result = 8;
        return 0;
    } else if (c.flush[1] == 5) {
        //只有同花
        result = 5;
    } else if (c.straight[1] == 5) {
        //只有順
        result = 4;
    }
    if (c.pairs[0][0]) //若pairs儲存槽A為已達標
    {
        if (c.pairs[1][0]) //若pairs儲存槽B為已達標
        {
            if (c.pairs[0][1] == c.pairs[1][1]) //若儲存槽AB之值相等
            {
                result = 7; //four of a kind
                return 0;
            }
            result = 2; //否則為two pairs
        } else          //否則為 pair
        {
            result = 1;
        }
    }
    if (c.three[0] == 3) //如果three紀錄表示有3張牌數字一樣
    {
        if (c.pairs[0][0]) //若pairs儲存槽A為已達標
        {
            result = 6; //葫蘆，3配2，即full house
        } else {
            result = 3; //僅3張數字一樣
        }
    }
    return 0;
}
int print_result() {
    //依照收到的結果輸出對應的文字，僅此而已
    switch (result) {
    case 1:
        printf("Pair\n\n");
        break;
    case 2:
        printf("Two pairs\n\n");
        break;
    case 3:
        printf("Three of a kind\n\n");
        break;
    case 4:
        printf("Straight\n\n");
        break;
    case 5:
        printf("Flush\n\n");
        break;
    case 6:
        printf("Full house\n\n");
        break;
    case 7:
        printf("Four of a kind\n\n");
        break;
    case 8:
        printf("Straight flush\n\n");
        break;
    default:
        printf("High card\n\n");
        break;
    }
    return 0;
}
int main(int argc, char *argv[]) {
    for (; read_cards();) {
        //如果read_cards回傳結束訊息(即0)，則停止for迴圈
        analyze_hand(); //呼叫分析手牌程式
        print_result(); //呼叫輸出結果程式
    }
    return 0;
}
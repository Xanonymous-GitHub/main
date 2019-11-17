/*****************************************************************/
/* Class: Computer Programming, Fall 2019                        */
/* Author: 林天佑                                                 */
/* ID: 108820003                                                 */
/* Date: 2019.11.17                                              */
/* Purpose: Be the best student.                                 */
/* GitHub:  https://github.com/Xanonymous-GitHub/main/tree/HW    */
/*****************************************************************/
#include <stdio.h>
#include <string.h>
/*
    card:儲存牌的陣列，其格式如下：
    x    0 1 2 3 4 5 6 7 8 9 10 11 12
         a 2 3 4 5 6 7 8 9 t  j  q  k
    y    0 1 2 3
         c d h s
*/
int card[13][4] = {0};
int num = 0;    //紀錄目前已經讀取了幾張合法牌
int result = 0; //紀錄結果種類
typedef struct card_counter
{
    //判斷物件，共4屬性，其意義如下：
    int pairs;       //有幾個對(不會出現兩個重複的對)
    int three_pairs; //旗標，是否出現三個一樣數字的牌
    int straight[2]; //{上次判斷的值,符合條件數量}
    int flush[2];    //{上次判斷的值,符合條件數量}
} counter;
int read_cards()
{
    memset(card, 0, sizeof(card)); //清空手牌
    num = 0;                       //手牌為0張
    result = 0;                    //預設為High card
    while (num < 5)
    {                             //拿5張
        char tmp[2];              //暫存數字及花色的陣列
        printf("Enter a card: "); //顯示輸入訊息
        scanf("%s", tmp);         //讀取輸入
        if (tmp[0] == '0')        //若為0則停止程式執行
        {
            return 0; //回傳false結束main函式
        }
        if ((tmp[0] - '0' <= 9) && (tmp[0] - '0' >= 2))
        {
            //假設為合法輸入，若為數字，將該字元轉為數字，以符合card陣列格式。
            tmp[0] -= '1';
        }
        else
        {
            //假設為合法輸入，若為英文字母，將該字元轉為數字，以符合card陣列格式。
            switch (tmp[0])
            {
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
        switch (tmp[1])
        {
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
        if (card[tmp[0]][tmp[1]])
        {
            //重複輸入，顯示錯誤訊息，重新要求用戶輸入
            printf("Duplicate card; ignored.\n");
            continue;
        }
        else
        {
            //正確且不重複的輸入，將該牌在card中標記為存在。
            card[tmp[0]][tmp[1]] = 1;
            num++; //手排數+1
        }
    }
    return 1; //正確拿5張，回傳true
}
int analyze_hand()
{
    int i, j;
    /*
        定義物件c:
        pairs預設0個
        three_pairs預設沒有
        straight預設前一項是-1，0組符合結果
        flush預設前一項是-1，0組符合結果
    */
    counter c = {0, 0, {-1, 0}, {-1, 0}};
    for (i = 0; i < 13; i++)
    {
        int tmp = 0; //紀錄該數字有幾個花色被拿在手上
        for (int j = 0; j < 4; j++)
        {
            tmp += card[i][j]; //牌數+1
        }
        if (tmp == 4) //若該數字有4個花色被拿在手上
        {
            result = 7; //直接設定結果為Four of a kind
            return 0;   //停止計算
        }
        else if (tmp == 3) //若該數字有3個花色被拿在手上
        {
            c.three_pairs = 1; //出現三個一樣數字的牌
        }
        else if (tmp == 2) //若該數字有2個花色被拿在手上
        {
            c.pairs++; //對數+1
        }
        else if (tmp) //若該數字只有1個花色被拿在手上
        {
            int tmp_j = 0; //暫存該數字被唯一拿在手上的花色位置的變數
            while (!(card[i][tmp_j++]))
                ; //找到是哪個花色拿在手上

            /*
                判斷順，連續五張數字連續叫做順，包括10JQKA，但不包括JQKA2,QKA23,KA234
            */
            if ((c.straight[0] == -1) || (c.straight[0] == i - 1) || ((c.straight[0] == 0) && i == 9))
            {
                /*
                    達成以下任一條件就將順的成功延續筆數加：
                    1.尚未判斷任何牌
                    2.當前判斷牌數字是上一次判斷的牌的數字+1
                    3.上次判斷的是A(ace)，且現在判斷的是T(10)
                */
                c.straight[0] = i;
                c.straight[1]++;
            }

            //判斷同花，連續五張花色一樣叫做同花
            if ((c.flush[0] == -1) || (c.flush[0] == tmp_j))
            {
                /*
                    達成以下任一條件就將順的成功延續筆數加：
                    1.尚未判斷任何牌
                    2.當前判斷牌花色等於上一次判斷的牌的花色
                */
                c.flush[0] = tmp_j;
                c.flush[1]++;
            }
        }
    }
    //開始設定結果
    if (c.three_pairs == 1)
    {
        //如果有三張數字一樣的牌，就有兩種可能
        if (c.pairs)
        {
            //葫蘆，3配2，即full house
            result = 6;
        }
        else
        {
            //僅3張數字一樣
            result = 3;
        }
        return 0;//由於不可能發生其他結果，所以立即跳出
    }
    if (c.pairs > 0)//如果"有"對子
    {
        result = c.pairs;//直接設定結果為"幾"個對子
    }
    if ((c.flush[1] == 5) && (c.straight[1] == 5))
    {
        //如果產生同花且產生順，那就是同花順
        result = 8;
    }
    else if (c.flush[1] == 5)
    {
        //只有同花
        result = 5;
    }
    else if (c.straight[1] == 5)
    {
        //只有順
        result = 4;
    }
    return 0;//結束判斷
}
int print_result()
{
    //依照收到的結果輸出對應的文字，僅此而已
    switch (result)
    {
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
int main(int argc, char *argv[])
{
    for (; read_cards();)
    {
        //如果read_cards回傳結束訊息(即0)，則停止for迴圈
        analyze_hand();//呼叫分析手牌程式
        print_result();//呼叫輸出結果程式
    }
    return 0;
}
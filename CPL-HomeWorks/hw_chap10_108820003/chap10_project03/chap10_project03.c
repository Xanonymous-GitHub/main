/*****************************************************************/
/* Class: Computer Programming, Fall 2019                        */
/* Author: 林天佑                                                 */
/* ID: 108820003                                                 */
/* Date: 2019.                                              */
/* Purpose: Be the best student.                                 */
/* GitHub:  https://github.com/Xanonymous-GitHub/main/tree/HW    */
/*****************************************************************/
#include <stdio.h>
#include <string.h>

int num = 0;    //紀錄目前已經讀取了幾張合法牌
int result = 0; //紀錄結果種類
int read_cards()
{
    int i, continue_flag = 0;
    int card[5][2] = {0};
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
        for (i = 0; i < num; i++)
        {
            if ((card[i][0] == tmp[0]) && (card[i][1] == tmp[1]))
            {
                //重複輸入，顯示錯誤訊息，重新要求用戶輸入
                printf("Duplicate card; ignored.\n");
                continue_flag = 1;
                break;
            }
        }
        if (continue_flag)
        {
            continue_flag = 0;
            continue;
        }
        card[num][0] = tmp[0];
        card[num][1] = tmp[1];
        num++; //手排數+1
    }
    return 1; //正確拿5張，回傳true
}
int analyze_hand()
{
    
    return 0;
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
        analyze_hand(); //呼叫分析手牌程式
        print_result(); //呼叫輸出結果程式
    }
    return 0;
}
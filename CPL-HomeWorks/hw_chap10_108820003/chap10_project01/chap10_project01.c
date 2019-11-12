/*****************************************************************/
/* Class: Computer Programming, Fall 2019                        */
/* Author: 林天佑                                                 */
/* ID: 108820003                                                 */
/* Date: 2019.11.13                                              */
/* Purpose: Be the best student.                                 */
/* GitHub:  https://github.com/Xanonymous-GitHub/main/tree/HW    */
/*****************************************************************/
#include <stdio.h>
#define MAX_LEN 100 //定義stack大小
int push(char *data, int *top, char obj, int *special_situation)
{
    /*  Stack::push,將新資料放至堆疊頂端
        *data:資料陣列(指標)
        *top:頂端位置(指標)
        obj:新資料
        *special_situation:旗標變數，判定是否發生overflow或underflow
    */
    if (*top >= MAX_LEN - 1) //如果頂端已達到stack大小或超過
    {
        printf("Stack overflow\n"); //輸出堆疊溢出訊息
        *special_situation = 1;     //標記發生特殊狀況
        return 0;
    }
    data[++(*top)] = obj; //將新物件放至堆疊頂端
    return 1;
}
char pop(char *data, int *top, int *special_situation)
{
    /*  Stack::pop,將頂層資料取出
        *data:資料陣列(指標)
        *top:頂端位置(指標)
        obj:新資料
        *special_situation:旗標變數，判定是否發生overflow或underflow
    */
    if (*top < 0) //如果為空堆疊
    {
        printf("Stack underflow\n"); //輸出空堆疊訊息
        *special_situation = 1;      //標記發生特殊狀況
        return '\0';                 //回傳非括號之任意字元
    }
    return data[(*top)--]; //回傳自堆的頂端取下的項並將頂層位置往下設定
}
int main(int argc, char *argv[])
{
    printf("Enter parentheses and/or braces : "); //顯示輸入訊息
    /*
        Top:頂端位置
        result:旗標變數，判定結果
        special_situation:旗標變數，判定是否發生overflow或underflow
        Stack:堆疊本體
        c:目前所讀取之字元
    */
    int Top = -1, result = 1, special_situation = 0;
    char Stack[MAX_LEN], c;
    while (result && !(special_situation) && (c = getchar()) != '\n')
    {
        /*
            當以下條件成立時，就向後讀取字元並進行判斷
            1.目前為止括號均有左右對應(包含無)
            2.未發生特殊狀況
            3.未達到字元結束(即換行符號)
        */
        if (c == '(' || c == '{') //若此字元為左系列括號
        {
            push(&Stack[0], &Top, c, &special_situation); //將此字元嘗試放至堆疊頂端
        }
        else if (c == '}' || c == ')') //若此字元為右系列括號
        {
            switch (c) //判斷是哪種括號
            {
            case '}':
                if (pop(&Stack[0], &Top, &special_situation) != '{')
                {
                    //如果取下堆疊頂層物件後，發現並非對稱括號
                    result = 0; //標記左右對應失敗
                }
                break;
            case ')':
                if (pop(&Stack[0], &Top, &special_situation) != '(')
                {
                    //如果取下堆疊頂層物件後，發現並非對稱括號
                    result = 0; //標記左右對應失敗
                }
                break;
            }
        }
    }
    if (!(special_situation)) //如果未發生特殊狀況
    {
        if (result && Top == -1) //如果左右對應成功(堆疊為空)
        {
            printf("Parentheses/braces are nested properly\n"); //顯示表示左右對應成功訊息
        }
        else
        {
            printf("Parentheses/braces are NOT nested properly\n"); //顯示表示左右對應不成功訊息
        }
    }
    return 0;
}
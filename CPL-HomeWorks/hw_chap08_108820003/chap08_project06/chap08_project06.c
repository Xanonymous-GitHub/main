/*****************************************************************/
/* Class: Computer Programming, Fall 2019                        */
/* Author: 林天佑                                                 */
/* ID: 108820003                                                 */
/* Date: 2019.10.29                                              */
/* Purpose: Be the best student.                                 */
/* GitHub:  https://github.com/Xanonymous-GitHub/main/tree/HW    */
/*****************************************************************/
#include <stdio.h>
#define upper_distance 'a' - 'A'//大小寫之間的距離
int main(int argc, char *argv[])
{
    char data[32767];//用來儲存輸入的資料
    int pos = 0;//現在正在處理data中的哪一個字元
    printf("Enter message: ");//顯示輸入訊息
    fgets(data, sizeof(data), stdin);//直接取得整行輸入資料
    printf("In B1FF-speak: ");//顯示輸出訊息
    while (data[pos]!='\n')//當還沒遇到換行符號時就繼續判斷
    {
        if ((data[pos] - 'a') <= 25 && (data[pos] - 'a') >= 0)//如果該字元是屬於英文字母且小寫
        {
            data[pos] -= upper_distance;//就換成大寫，減掉和大寫之間的距離
        }
        switch (data[pos])//判斷資料中的每個字元，依照題目意思置換字元
        {
        case 'A':
            printf("4");
            break;
        case 'B':
            printf("8");
            break;
        case 'E':
            printf("3");
            break;
        case 'I':
            printf("1");
            break;
        case 'O':
            printf("0");
            break;
        case 'S':
            printf("5");
            break;
        default://如果不是題目規定的字元，就輸出原資料
            printf("%c", data[pos]);
            break;
        }
        pos++;//位置後移
    }
    printf("!!!!!!!!!!\n");//補上10個驚嘆號
    return 0;
}
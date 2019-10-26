/*****************************************************************/
/* Class: Computer Programming, Fall 2019                        */
/* Author: 林天佑                                                 */
/* ID: 108820003                                                 */
/* Date: 2019.10.19                                              */
/* Purpose: Be the best student.                                 */
/* GitHub:  https://github.com/Xanonymous-GitHub/main/tree/HW    */
/*****************************************************************/
#include <stdio.h>
int main(int argc, char *argv[])
{
    char input[10000];                  //存放用戶輸入
    int pos = 0;                        //代表現在判斷點
    printf("Enter phone number: ");     //顯示輸入提示訊息
    fgets(input, sizeof(input), stdin); //讀取整行文字包含空白及換行
    while (input[pos])                  //當尚未判斷到'\0'就繼續執行
    {
        int tmp = input[pos] - 'A'; //tmp存放該字元與A的距離
        /*
            耍詐，Q被跳過，因此需要手動避免這個問題。
        */
        if (tmp <= 25 && tmp >= 0)
        {
            if (tmp > 15)
                printf("%d", (--tmp) / 3 + 2);
            else
                printf("%d", tmp / 3 + 2);
        }
        else
            printf("%c", input[pos]);
        pos++; //移動至下一個判斷點
        
    }
    return 0;
}
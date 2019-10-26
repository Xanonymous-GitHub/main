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
        if (tmp <= 25 && tmp >= 0)  //若該字元之ASCII與第一大寫英文字母對減之範圍仍在英文字母總數之內，則該數為英文字母。
        {
            /*
                英文字母對應數字的規則基本上是每三個一數，且按照順序排列，
                第一組對應數字為2，往後遞增，因此可以使用ASCII位置整除3加2的方式得到組別序
                那麼就可以直接輸出組別序。
            */
            if (tmp > 15)
                //耍詐，Q被跳過，因此需要手動避免這個問題。
                //若發現該英文字元為Q後的一項(包含Q)，則輸出往前位移一位的答案(把Q排除)
                printf("%d", (--tmp) / 3 + 2);
            else
                printf("%d", tmp / 3 + 2); //正常情況下的輸出
        }
        else //若該字元並非英文字母，則維持原樣輸出
            printf("%c", input[pos]);
        pos++; //移動至下一個判斷點
    }
    return 0;
}
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
    int result = 0, pos = 0;          //result儲存母音數量，pos代表現在判定到哪個位置
    char data[1000];                  //存放用戶輸入
    printf("Enter a sentence: ");     //顯示輸入提示訊息
    fgets(data, sizeof(data), stdin); //讀取整行，包含空白和換行
    while (data[pos])                 //當尚未判斷到'\0'就繼續執行
    {
        //如果現在這個字是個母音，就把結果+1
        if (data[pos] == 'a' || data[pos] == 'A' || data[pos] == 'e' || data[pos] == 'E' || data[pos] == 'i' || data[pos] == 'I' || data[pos] == 'o' || data[pos] == 'O' || data[pos] == 'u' || data[pos] == 'U')
            result++;
        pos++; //移動至下一個判斷點
    }
    printf("Your sentence contains %d vowels.\n", result); //輸出結果
    return 0;
}
/*****************************************************************/
/* Class: Computer Programming, Fall 2019                        */
/* Author: 林天佑                                                 */
/* ID: 108820003                                                 */
/* Date: 2019.12.08                                              */
/* Purpose: Be the best student.                                 */
/* GitHub:  https://github.com/Xanonymous-GitHub/main/tree/HW    */
/*****************************************************************/
#include <stdio.h>
#define MAXLEN 10000 //定義最大長度
int main(int argc, char *argv[]) {
    printf("Enter a message: ");//顯示輸出訊息
    int i = 0;//宣告迭代變數
    char c[MAXLEN];//宣告字元陣列(字串)
    while ((c[i++] = getchar()) != '\n');//讀取輸入
    printf("Reversal is: ");//顯示輸出訊息
    for (i -= 2; i + 1; i--)printf("%c",c[i]);//輸出相反
    printf("\n");//換行
    return 0;
}
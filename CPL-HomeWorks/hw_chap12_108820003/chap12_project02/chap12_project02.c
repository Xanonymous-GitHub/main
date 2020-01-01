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
    printf("Enter a message: "); //顯示輸出訊息
    int i = 0, j, k = 1, l = 0;  //宣告迭代變數
    char c[MAXLEN], cc[MAXLEN];  //宣告字元陣列(字串)
    while ((c[i++] = getchar()) != '\n'); //讀取輸入
    for (j = i - 2; j + 1; j--)c[j] += (c[j] - 'a' < 0) ? ('a' - 'A') : 0;//轉成小寫
    for (j = i - 2; j + 1; j--)sprintf(&cc[l++], "%c", c[j]); //輸出相反
    for (j = 0; j < i - 1; j++)//比較字串
    if (c[j] != cc[j])k = 0;//不一樣就拉倒
    if (k)printf("Palindrome\n");//是回文
    else printf("Not a Palindrome\n");//不是回文
    return 0;
}
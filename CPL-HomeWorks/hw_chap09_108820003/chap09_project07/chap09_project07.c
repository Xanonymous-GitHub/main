/*****************************************************************/
/* Class: Computer Programming, Fall 2019                        */
/* Author: 林天佑                                                 */
/* ID: 108820003                                                 */
/* Date: 2019.11.07                                              */
/* Purpose: Be the best student.                                 */
/* GitHub:  https://github.com/Xanonymous-GitHub/main/tree/HW    */
/*****************************************************************/
#include <stdio.h>
int power(int base, int n) //遞迴函式
{
    if (n == 0)
    {
        return 1; //零次方
    }
    if (n == 1)
    {
        return base; //1次方
    }
    if (n % 2)
    {
        return base * power(base, n - 1); //奇數次方
    }
    else
    {
        return power(base, n / 2) * power(base, n / 2); //偶數次方
    }
}
int main(int argc, char *argv[])
{
    int x, n;                                  //宣告變數
    printf("For x^n, enter x: ");              //輸入訊息
    scanf("%d", &x);                           //輸入
    printf("Enter n: ");                       //輸入訊息2
    scanf("%d", &n);                           //輸入2
    printf("%d^%d = %d\n", x, n, power(x, n)); //輸出
    return 0;
}
/*****************************************************************/
/* Class: Computer Programming, Fall 2019                        */
/* Author: 林天佑                                                 */
/* ID: 108820003                                                 */
/* Date: 2019.11.07                                              */
/* Purpose: Be the best student.                                 */
/* GitHub:  https://github.com/Xanonymous-GitHub/main/tree/HW    */
/*****************************************************************/
#include <stdio.h>
double myPow(int base, int p)
{
    //由於gcc編譯器編譯pow()函式時須加入-lm參數太過麻煩，因此自製次方函數。
    double result = 1; //初始值
    if (p >= 0)
    {
        //如果次方數為正或0，則用乘法
        for (int i = 0; i < p; i++)
            result *= base;
    }
    else
    {
        //如果次方數為負數，則用除法
        for (int i = 0; i > p; i--)
            result /= base;
    }
    return result;
}
double polynomial(int x)
{ //計算方程式
    return 3 * myPow(x, 5) + 2 * myPow(x, 4) - 5 * myPow(x, 3) - 1 * myPow(x, 2) + 7 * myPow(x, 1) - 6;
}
int main(int argc, char *argv[])
{
    int x;
    printf("Enter a integer: ");                //顯示輸入訊息
    scanf("%d", &x);                            //讀取資料
    printf("Result: %d\n", (int)polynomial(x)); //輸出結果
    return 0;
}
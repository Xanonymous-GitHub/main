/*****************************************************************/
/* Class: Computer Programming, Fall 2019                        */
/* Author: 林天佑                                                 */
/* ID: 108820003                                                 */
/* Date: 2019.10.25                                              */
/* Purpose: Be the best student.                                 */
/* GitHub:  https://github.com/Xanonymous-GitHub/main/tree/HW    */
/*****************************************************************/
#include <stdio.h>
int main(int argc, char *argv[])
{
    int n = 0;                            //被算數
    printf("Enter a positive integer: "); //顯示提示輸入訊息
    scanf("%d", &n);                      //取得被算數
    short _short = 1;                     //建立短整數
    int _int = 1;                         //建立整數
    long _long = 1;                       //建立長整數
    long long _long_long = 1;             //建立超長整數
    float _float = 1;                     //建立單精度浮點數
    double _double = 1;                   //建立雙精度浮點數
    long double _long_double = 1;         //建立長雙精度浮點數
    for (int i = 2; i <= n; i++)          //計算階乘
    {
        _short *= (short)i;             //轉換型別，增加階乘
        _int *= (int)i;                 //轉換型別，增加階乘
        _long *= (long)i;               //轉換型別，增加階乘
        _long_long *= (long long)i;     //轉換型別，增加階乘
        _float *= (float)i;             //轉換型別，增加階乘
        _double *= (double)i;           //轉換型別，增加階乘
        _long_double *= (long double)i; //轉換型別，增加階乘
    }
    //輸出所有結果
    printf("Factorial of %d (short)      : %hd\n", n, _short);
    printf("Factorial of %d (int)        : %d\n", n, _int);
    printf("Factorial of %d (long)       : %ld\n", n, _long);
    printf("Factorial of %d (long long)  : %lld\n", n, _long_long);
    printf("Factorial of %d (float)      : %f\n", n, _float);
    printf("Factorial of %d (double)     : %lf\n", n, _double);
    printf("Factorial of %d (long double): %Lf\n", n, _long_double);
    return 0;
}
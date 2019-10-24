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
    int n = 0;
    printf("Enter a positive integer: ");
    scanf("%d", &n);
    short _short = 1;
    int _int = 1;
    long _long = 1;
    long long _long_long = 1;
    float _float = 1;
    double _double = 1;
    long double _long_double = 1;
    for (int i = 2; i <= n; i++)
    {
        _short *= (short)i;
        _int *= (int)i;
        _long *= (long)i;
        _long_long *= (long long)i;
        _float *= (float)i;
        _double *= (double)i;
        _long_double *= (long double)i;
    }
    printf("Factorial of %d (short)      : %hd\n", n, _short);
    printf("Factorial of %d (int)        : %d\n", n, _int);
    printf("Factorial of %d (long)       : %ld\n", n, _long);
    printf("Factorial of %d (long long)  : %lld\n", n, _long_long);
    printf("Factorial of %d (float)      : %f\n", n, _float);
    printf("Factorial of %d (double)     : %lf\n", n, _double);
    printf("Factorial of %d (long double): %Lf\n", n, _long_double);
    return 0;
}
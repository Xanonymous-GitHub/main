#include <stdio.h>
int main(int argc, char *argv[])
{
    int a, b, remainder;
    scanf("%d%d", &a, &b);
    while (b != 0)
    {
        remainder = b;
        b = a % b;
        a = remainder;
    }
    printf("%d", a);
    return 0;
}
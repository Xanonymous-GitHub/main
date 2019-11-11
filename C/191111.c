#include <stdio.h>
int foo()
{
    static int i = 0;
    i++;
    return i;
}

int main()
{
   printf("%d",i);
    return 0;
}
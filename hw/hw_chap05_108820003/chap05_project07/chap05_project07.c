/*****************************************************************/
/* Class: Computer Programming, Fall 2019                        */
/* Author: 林天佑                                                 */
/* ID: 108820003                                                 */
/* Date: 2019.09.23                                              */
/* Purpose: Be the best student.                                 */
/* GitHub:  https://github.com/Xanonymous-GitHub/main/tree/HW    */
/*****************************************************************/
#include<stdio.h>
int main(int argc,char* argv[]){
    printf("Enter four intergers: ");
    int b=-32767,s=32767,n=0;
    for (int i = 0; i < 4; i++)
    {
        scanf("%d",&n);
        if (n>b)b=n;
        if (n<s)s=n;
    }
    printf("Largest: %d\nSmallest: %d\n",b,s);
    return 0;
}
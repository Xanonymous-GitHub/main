/*****************************************************************/
/* Class: Computer Programming, Fall 2019                        */
/* Author: 林天佑                                                 */
/* ID: 108820003                                                 */
/* Date: 2019.10.01                                              */
/* Purpose: Be the best student.                                 */
/* GitHub:  https://github.com/Xanonymous-GitHub/main/tree/HW    */
/*****************************************************************/
#include<stdio.h>
int main(int argc,char* argv[]){
    double input=1.2E-38,max=1.2E-38;
    char tmp[100];
    int pos=0;
    while (input)
    {
        printf("Enter a number: ");
        scanf("%lf",&input);
        if (input>max)
        {
            max=input;
            sprintf(tmp,"%lf",max);
            //printf("%s",tmp);
        }
    }
    printf("The largest number entered was %lf",max);
    //how to get the .* amount??
    return 0;
}
/*****************************************************************/
/* Class: Computer Programming, Fall 2019                        */
/* Author: 林天佑                                                 */
/* ID: 108820003                                                 */
/* Date: 2019.09.17                                              */
/* Purpose: Be the best student.                                 */
/* GitHub:  https://github.com/Xanonymous-GitHub/main/tree/HW    */
/*****************************************************************/
#include<stdio.h>
int main(int argc,char* argv[]){
    printf("Enter a two-digit number: ");
    int data;
    scanf("%d",&data);
    /*
        取得該十位數除以十的餘數再乘以十作為新數字的十位數，
        並將原本的十位數字除以十的商作為新數字的個位數，完成位數交換動作。
        原十位數除以十的餘:data%10
        原十位數除以十的商:data/10 
    */
    printf("%d\n",(data%10)*10+data/10);
    return 0;
}
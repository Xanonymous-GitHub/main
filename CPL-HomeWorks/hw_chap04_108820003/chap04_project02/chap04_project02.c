/*****************************************************************/
/* Class: Computer Programming, Fall 2019                        */
/* Author: 林天佑                                                 */
/* ID: 108820003                                                 */
/* Date: 2019.09.19                                              */
/* Purpose: Be the best student.                                 */
/* GitHub:  https://github.com/Xanonymous-GitHub/main/tree/HW    */
/*****************************************************************/
#include<stdio.h>
int main(int argc,char* argv[]){
    printf("Enter a three-digit number: ");
    int data;
    scanf("%d",&data);
    /*
        取得該百位數除以十的餘數再乘以一百作為新數字的百位數，
        取得該百位數除以一百的餘數再除以十得到商，乘以十後作為新數字的十位數，
        並將原本的百位數字除以一百的商作為新數字的個位數，完成位數交換動作。
        原百位數除以十的餘:data%10
        原百位數除以一百的餘再除以十的商:data%100)/10
        原百位數除以一百的商:data/100
    */
    printf("The reversal is: %d\n",(data%10)*100+((data%100)/10)*10+data/100);
    return 0;
}
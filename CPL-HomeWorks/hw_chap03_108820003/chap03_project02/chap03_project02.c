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
    int item_number,y,m,d;
    float unit_price;
    //show a message that tells user there is the input place.
    printf("Enter item number: ");
    //get the data that user inputed.
    scanf("%d",&item_number);
    //show a message that tells user there is the input place.
    printf("Enter unit price: ");
    //get the data that user inputed.
    scanf("%f",&unit_price);
    //show a message that tells user there is the input place.
    printf("Enter purchase date (mm/dd/yyyy): ");
    //get the data that user inputed.
    scanf("%02d/%02d/%d",&m,&d,&y);
    //output the result.
    printf("Item\tUnit\t\tPurchase\n");
    printf("\tPrice\t\tDate\n");
    printf("%d\t$ %.2f\t%02d/%02d/%d\n",item_number,unit_price,m,d,y);
    return 0;
}
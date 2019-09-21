/*****************************************************************/
/* Class: Computer Programming, Fall 2019                        */
/* Author: 林天佑                                                 */
/* ID: 108820003                                                 */
/* Date: 2019.09.17                                              */
/* Purpose:                                                      */
/* Change History:                                               */
/*****************************************************************/
#include<stdio.h>
int main(int argc,char* argv[]){
    //init three variable.
    int y,m,d;
    //show a message that tells user there is the input place.
    printf("Enter a date (mm/dd/yyy): ");
    //get the data that user inputed.
    scanf("%d/%d/%d",&m,&d,&y);
    //print out the result.
    //Note that if the day or month entered by the user is a single digit, the program must output a two-digit number containing 0.
    //so I use the "%02d" format type.
    printf("You entered the date %d%02d%02d\n",y,m,d);
    return 0;
}
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
    //show a message that tells user there is the input place.
    printf("Enter phone number [(xxx) xxx-xxxx]: ");
    //init three variables to store the user datas
    int a,b,c;
    //get the data that user inputed.
    scanf("(%d) %d-%d",&a,&b,&c);
    //output the result.
    printf("You entered %d.%d.%d",a,b,c);
    return 0;
}
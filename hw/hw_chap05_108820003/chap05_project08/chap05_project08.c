/*****************************************************************/
/* Class: Computer Programming, Fall 2019                        */
/* Author: 林天佑                                                 */
/* ID: 108820003                                                 */
/* Date: 2019.                                             */
/* Purpose: Be the best student.                                 */
/* GitHub:  https://github.com/Xanonymous-GitHub/main/tree/HW    */
/*****************************************************************/
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
int main(int argc,char* argv[]){
    struct tm tmdate ={0};
    printf("Enter a 24-hour time:　");
    char data;
    while(scanf("%c",&data)==1)
    printf("%c",data);
    return 0;
}
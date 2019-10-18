/*****************************************************************/
/* Class: Computer Programming, Fall 2019                        */
/* Author: 林天佑                                                 */
/* ID: 108820003                                                 */
/* Date: 2019.10.19                                              */
/* Purpose: Be the best student.                                 */
/* GitHub:  https://github.com/Xanonymous-GitHub/main/tree/HW    */
/*****************************************************************/
#include<stdio.h>
int main(int argc,char* argv[]){
    char input[10000];
    int pos=0;
    printf("Enter phone number: ");
    fgets(input, sizeof(input), stdin);
    while(input[pos]){
        int tmp=input[pos]-'A';
        if(tmp<=25 && tmp>=0)printf("%d",tmp/3+2);
        else printf("%c",input[pos]);
        pos++;
    }
    return 0;
}
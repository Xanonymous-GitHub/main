/*****************************************************************/
/* Class: Computer Programming, Fall 2019                        */
/* Author: 林天佑                                                 */
/* ID: 108820003                                                 */
/* Date: 2019.10.21                                              */
/* Purpose: Be the best student.                                 */
/* GitHub:  https://github.com/Xanonymous-GitHub/main/tree/HW    */
/*****************************************************************/
#include <stdio.h>
#include <string.h>
int main(int argc, char *argv[])
{
    char first[100], last[100];
    printf("Enter a first and last name: ");
    scanf("%s %s", first, last);
    printf("%s, %c.\n", last, first[0]);
    return 0;
}
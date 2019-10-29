/*****************************************************************/
/* Class: Computer Programming, Fall 2019                        */
/* Author: 林天佑                                                 */
/* ID: 108820003                                                 */
/* Date: 2019.10.29                                              */
/* Purpose: Be the best student.                                 */
/* GitHub:  https://github.com/Xanonymous-GitHub/main/tree/HW    */
/*****************************************************************/
#include <stdio.h>
#define upper_distance 'a' - 'A'
int main(int argc, char *argv[])
{
    char data[32767];
    int pos = 0;
    printf("Enter message: ");
    fgets(data, sizeof(data), stdin);
    printf("In B1FF-speak: ");
    while (data[pos]!='\n')
    {
        //printf("%d",upper_distance);
        if ((data[pos] - 'a') <= 25 && (data[pos] - 'a') >= 0)
        {
            data[pos] -= upper_distance;
        }
        switch (data[pos])
        {
        case 'A':
            printf("4");
            break;
        case 'B':
            printf("8");
            break;
        case 'E':
            printf("3");
            break;
        case 'I':
            printf("1");
            break;
        case 'O':
            printf("0");
            break;
        case 'S':
            printf("5");
            break;
        default:
            printf("%c", data[pos]);
            break;
        }
        pos++;
    }
    printf("!!!!!!!!!!\n");
    return 0;
} //Hey dude, C is rilly cool
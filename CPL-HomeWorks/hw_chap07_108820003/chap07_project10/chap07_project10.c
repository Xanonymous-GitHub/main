/*****************************************************************/
/* Class: Computer Programming, Fall 2019                        */
/* Author: 林天佑                                                 */
/* ID: 108820003                                                 */
/* Date: 2019.10.19                                              */
/* Purpose: Be the best student.                                 */
/* GitHub:  https://github.com/Xanonymous-GitHub/main/tree/HW    */
/*****************************************************************/
#include <stdio.h>
int main(int argc, char *argv[])
{
    int result = 0, pos = 0;
    char data[1000];
    printf("Enter a sentence: ");
    fgets(data, sizeof(data), stdin);
    while (data[pos])
    {
        if (data[pos] == 'a' || data[pos] == 'A' || data[pos] == 'e' || data[pos] == 'E' || data[pos] == 'i' || data[pos] == 'I' || data[pos] == 'o' || data[pos] == 'O' || data[pos] == 'u' || data[pos] == 'U')
        {
            result++;
        }
        pos++;
    }
    printf("Your sentence contains %d vowels.\n", result);
    return 0;
}
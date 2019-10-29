/*****************************************************************/
/* Class: Computer Programming, Fall 2019                        */
/* Author: 林天佑                                                 */
/* ID: 108820003                                                 */
/* Date: 2019.10.29                                              */
/* Purpose: Be the best student.                                 */
/* GitHub:  https://github.com/Xanonymous-GitHub/main/tree/HW    */
/*****************************************************************/
#include <stdio.h>
int main(int argc, char *argv[])
{
    char data[1000][1000], end = '\0';
    int pos = 0;
    printf("Enter a sentence: ");
    while (1)
    {
        int tmp_pos = 0, _break = 0;
        scanf("%s", &data[pos][0]);
        while (data[pos][tmp_pos])
        {
            if (data[pos][tmp_pos] == '?' || data[pos][tmp_pos] == '!' || data[pos][tmp_pos] == '.')
            {
                end = data[pos][tmp_pos];
                data[pos][tmp_pos] = '\0';
                _break = !_break;
                break;
            }
            tmp_pos++;
        }
        if (_break)
            break;
        pos++;
    }
    printf("Reversal of sentence: ");
    while (pos > 0)
    {
        printf("%s ", data[pos--]);
    }
    printf("%s", data[pos]);
    printf("%c\n", end);
    return 0;
}
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
    int data[7][7] = {0}, row[7] = {0}, col[7] = {0};
    for (int i = 0; i < 5; i++)
    {
        printf("Enter row %d: ", i + 1);
        for (int j = 0; j < 5; j++)
        {
            scanf("%d", &data[i][j]);
        }
    }
    for (int i = 0; i < 5; i++)
    {
        int tmpr = 0, tmpc = 0;
        for (int j = 0; j < 5; j++)
        {
            tmpr += data[i][j];
            tmpc += data[j][i];
        }
        row[i] = tmpr;
        col[i] = tmpc;
    }
    printf("\n");
    printf("Row totals: ");
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", row[i]);
    }
    printf("\n");
    printf("Column totals: ");
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", col[i]);
    }
    printf("\n");
    return 0;
}
/*****************************************************************/
/* Class: Computer Programming, Fall 2019                        */
/* Author: 林天佑                                                 */
/* ID: 108820003                                                 */
/* Date: 2019.12.20                                              */
/* Purpose: Be the best student.                                 */
/* GitHub:  https://github.com/Xanonymous-GitHub/main/tree/HW    */
/*****************************************************************/
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[]) {
    int sum = 0; //定義加總為零
    for (; argc - 1;)
    sum += atoi(argv[--argc]); //將神之指令轉成數字加入加總變數
    printf("%d\n", sum);           //列出加總
    return 0;
}
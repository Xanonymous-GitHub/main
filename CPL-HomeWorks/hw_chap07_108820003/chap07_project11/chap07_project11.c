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
    char first[100], last[100];              //建立兩個字元陣列，分別是儲存姓，名
    printf("Enter a first and last name: "); //顯示提示輸入訊息
    scanf("%s %s", first, last);             //以空白分割讀取姓名
    printf("%s, %c.\n", last, first[0]);     //交換順序後輸出(後者僅頭文字)
    return 0;
}
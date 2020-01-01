/*****************************************************************/
/* Class: Computer Programming, Fall 2019                        */
/* Author: 林天佑                                                 */
/* ID: 108820003                                                 */
/* Date: 2019.12.20                                              */
/* Purpose: Be the best student.                                 */
/* GitHub:  https://github.com/Xanonymous-GitHub/main/tree/HW    */
/*****************************************************************/
#include <stdio.h>
int main(int argc, char *argv[]) {
    int m, d, y;//變數宣告
    //宣告月份
    const char *mm[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    printf("Enter a date (mm/dd/yyyy):");//顯示輸入訊息
    scanf("%d/%d/%d", &m, &d, &y);//讀取輸入
    printf("You entered the date %s %.2d, %d\n", mm[(m - 1) % 12], d, y);//顯示答案
    return 0;
}
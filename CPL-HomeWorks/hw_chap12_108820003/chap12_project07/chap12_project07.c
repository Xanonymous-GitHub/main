/*****************************************************************/
/* Class: Computer Programming, Fall 2019                        */
/* Author: 林天佑                                                 */
/* ID: 108820003                                                 */
/* Date: 2019.12.08                                              */
/* Purpose: Be the best student.                                 */
/* GitHub:  https://github.com/Xanonymous-GitHub/main/tree/HW    */
/*****************************************************************/
#include <stdio.h>
int main(int argc, char *argv[]) {
    printf("Enter 10 numbers: ");                           //顯示輸出訊息
    int i, ii[10], *iii = ii, iiiii = -32767, iiii = 32767; //建立變數
    for (i = 0; i < 10; i++) {                              //跑
        scanf("%d", &ii[i]);                                //讀
        if (*(iii + i) > iiiii)iiiii = ii[i]; //比大
        if (*(iii + i) < iiii)iiii = ii[i]; //比小
    }
    printf("Largest: %d\n", iiiii); //輸出大
    printf("Smallest: %d\n", iiii); //輸出小
    return 0;
}
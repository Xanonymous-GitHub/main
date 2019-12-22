/*****************************************************************/
/* Class: Computer Programming, Fall 2019                        */
/* Author: 林天佑                                                 */
/* ID: 108820003                                                 */
/* Date: 2019.12.22                                              */
/* Purpose: Be the best student.                                 */
/* GitHub:  https://github.com/Xanonymous-GitHub/main/tree/HW    */
/*****************************************************************/
#include "quicksort.h"
#include <stdio.h>
#define HOWMANY 10 //定義輸入筆數
int main(int argc, char *argv[]) {
    int data[HOWMANY] = {0}, i;                         //建立資料陣列
    printf("Enter %d numbers to be sorted: ", HOWMANY); //顯示輸入訊息
    for (i = 0; i < HOWMANY; i++)
        scanf("%d", &data[i]);       //取得欲排序之數字資料
    quicksort(data, 0, HOWMANY - 1); //以快速排序法排序資料
    printf("In sorted order: ");     //顯示輸出訊息
    for (i = 0; i < HOWMANY; i++)
        printf("%d ", data[i]); //輸出資料陣列
    printf("\n");               //換行
    return 0;
}
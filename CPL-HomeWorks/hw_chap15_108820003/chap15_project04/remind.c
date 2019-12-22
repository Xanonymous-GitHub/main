/*****************************************************************/
/* Class: Computer Programming, Fall 2019                        */
/* Author: 林天佑                                                 */
/* ID: 108820003                                                 */
/* Date: 2019.12.22                                              */
/* Purpose: Be the best student.                                 */
/* GitHub:  https://github.com/Xanonymous-GitHub/main/tree/HW    */
/*****************************************************************/
#include "readline.h"
#include <stdio.h>
#include <string.h>
#define MAX_REMIND 50
#define MSG_LEN 60
int main(int argc, char *argv[]) {
    char reminders[MAX_REMIND][MSG_LEN + 3]; //建立記事資料陣列
    char day_str[3], msg_str[MSG_LEN + 1];   //建立日期和資料陣列
    int day, i, j, num_remind = 0;           //建立計數變數
    for (;;) {
        if (num_remind == MAX_REMIND) { //超過上限，顯示警告
            printf("--No space left --\n");
            break;
        }
        printf("Enter day and remineder: "); //顯示輸入訊息
        scanf("%2d", &day);                  //取得日期
        if (day == 0) {                      //若為0則代表結束輸入
            break;
        }
        sprintf(day_str, "%2d", day); //將日期存入日期資料陣列
        read_line(msg_str, MSG_LEN);  //呼叫讀取函式，將結果存入資料陣列
        for (i = 0; i < num_remind; i++) {
            if (strcmp(day_str, reminders[i]) < 0) {
                break; //在資料庫中尋找第一個日期是比當前讀取日期還大的資料，以i保留該位置
            }
        }
        for (j = num_remind; j > i; j--) {
            //以插入點為起始點，將整串資料庫每一筆資料向後挪移
            strcpy(reminders[j], reminders[j - 1]);
        }
        strcpy(reminders[i], day_str); //插入日期資料
        strcat(reminders[i], msg_str); //插入訊息資料
        num_remind++;                  //計數器+1
    }
    printf("\nDay Reminder\n"); //顯示輸出訊息
    for (i = 0; i < num_remind; i++) {
        printf(" %s\n", reminders[i]); //輸出資料
    }
    return 0;
}
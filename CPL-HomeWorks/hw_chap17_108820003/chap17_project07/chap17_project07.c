/*****************************************************************/
/* Class: Computer Programming, Winter 2020                        */
/* Author: 林天佑                                                 */
/* ID: 108820003                                                 */
/* Date: 2020.01.01                                              */
/* Purpose: Be the best student.                                 */
/* GitHub:  https://github.com/Xanonymous-GitHub/main/tree/HW    */
/*****************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_REMIND 20
#define MSG_LEN 50
struct vstring { //定義結構
    int len;
    char chars[];
};

int read_line(char *str, int n) { //讀取字
    int ch, i = 0;
    while ((ch = getchar()) != '\n') {
        if (i < n) {
            str[i++] = ch;
        }
    }
    str[i] = '\0';
    return i;
}
int main(int argc, char *argv[]) {
    struct vstring *reminders[MAX_REMIND]; //記事字串陣列
    char day_str[3], msg_str[MSG_LEN + 1]; //緩存字串陣列
    int day, i, j, num_remind = 0;         //宣告緩存的控制結構變數
    for (;;) {
        if (num_remind == MAX_REMIND) {       //達到上限
            printf(" -- No space left --\n"); //警告
            break;                            //停
        }
        printf("Enter day and reminder : "); //提示輸入
        scanf("%2d", &day);                  //取字
        if (day == 0) {                      //收到停止訊息
            break;                           //停
        }
        sprintf(day_str, "%2d", day); //將日期丟入陣列
        read_line(msg_str, MSG_LEN);  //讀取字
        for (i = 0; i < num_remind; i++) {
            if (strcmp(day_str, reminders[i]->chars) < 0) {
                break; //在日期陣列裡面找到第一個比剛才輸入的日期大的日期的位置(i)
            }
        }
        for (j = num_remind; j > i; j--) {
            reminders[j] = reminders[j - 1]; //挪出空位
        }
        //調整存放新內容位置的大小
        reminders[i] = (struct vstring *)malloc(sizeof(struct vstring) + 2 + strlen(msg_str));
        if (reminders[i] == NULL) {
            printf(" -- No space left --\n");
            break;
        }
        //紀錄長度
        reminders[i]->len = 2 + strlen(msg_str);
        memcpy(reminders[i]->chars, day_str, 2);                   //寫入日期
        memcpy(reminders[i]->chars + 2, msg_str, strlen(msg_str)); //於後方接著寫入記事
        num_remind++;
    }
    printf("\nDay Reminder\n"); //提示訊息
    for (i = 0; i < num_remind; i++) {
        printf(" %*s\n", reminders[i]->len, reminders[i]->chars); //列出結果
    }
    return 0;
}
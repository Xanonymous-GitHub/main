/*****************************************************************/
/* Class: Computer Programming, Fall 2019                        */
/* Author: 林天佑                                                 */
/* ID: 108820003                                                 */
/* Date: 2019.12.29                                              */
/* Purpose: Be the best student.                                 */
/* GitHub:  https://github.com/Xanonymous-GitHub/main/tree/HW    */
/*****************************************************************/
#include <stdio.h>
#define x ^=
#define m1 s1.m
#define d1 s1.d
#define y1 s1.y
#define m2 s2.m
#define d2 s2.d
#define y2 s2.y
struct
{
    int m;
    int d;
    int y;
}s1,s2;

int main(int argc, char *argv[]) {                //
    printf("Enter first date (mm/dd/yy) : ");  //告知user要輸入什麼
    scanf("%d/%d/%d", &m1, &d1, &y1);          //存入第一筆日期資料
    printf("Enter second date (mm/dd/yy) : "); //告知user要輸入什麼
    scanf("%d/%d/%d", &m2, &d2, &y2);          //存入第二筆日期資料
    /*
        預設first date < second date
        從最大的開始比較如果first>second就交換
    */
    if (y1 > y2 || m1 > m2 || d1 > d2) {
        m1 x m2;
        m2 x m1;
        m1 x m2;
        d1 x d2;
        d2 x d1;
        d1 x d2;
        y1 x y2;
        y2 x y1;
        y1 x y2;
    }
    //輸出結果
    printf("%d/%d/%02d is earlier than %d/%d/%02d\n", m1, d1, y1, m2, d2, y2);
    return 0;
}
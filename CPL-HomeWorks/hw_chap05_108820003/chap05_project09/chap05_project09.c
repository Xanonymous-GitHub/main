/*****************************************************************/
/* Class: Computer Programming, Fall 2019                        */
/* Author: 林天佑                                                 */
/* ID: 108820003                                                 */
/* Date: 2019.09.27                                              */
/* Purpose: Be the best student.                                 */
/* GitHub:  https://github.com/Xanonymous-GitHub/main/tree/HW    */
/*****************************************************************/
#include<stdio.h>
#define x ^=
int main(int argc,char* argv[]){
    int m1,d1,y1,m2,d2,y2;//
    printf("Enter first date (mm/dd/yy) : ");//告知user要輸入什麼
    scanf("%d/%d/%d",&m1,&d1,&y1);//存入第一筆日期資料
    printf("Enter second date (mm/dd/yy) : ");//告知user要輸入什麼
    scanf("%d/%d/%d",&m2,&d2,&y2);//存入第二筆日期資料
    /*
        預設first date < second date
        從最大的開始比較如果first>second就交換
    */
    if (y1>y2 || m1>m2 || d1>d2){
        m1 x m2;m2 x m1;m1 x m2;
        d1 x d2;d2 x d1;d1 x d2;
        y1 x y2;y2 x y1;y1 x y2;
    }
    //輸出結果
    printf("%d/%d/%02d is earlier than %d/%d/%02d\n",m1,d1,y1,m2,d2,y2);
    return 0;
}
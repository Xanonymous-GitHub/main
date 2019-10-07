/*****************************************************************/
/* Class: Computer Programming, Fall 2019                        */
/* Author: 林天佑                                                 */
/* ID: 108820003                                                 */
/* Date: 2019.09.27                                              */
/* Purpose: Be the best student.                                 */
/* GitHub:  https://github.com/Xanonymous-GitHub/main/tree/HW    */
/*****************************************************************/
#include<stdio.h>
#define q *60+
int myAbs(int a){
    //自製絕對值函式
    if (a<0) return -a;
    return a;
}
//宣告起飛時間格式化字元陣列(字串)
char r1[]={'\0','\0',':','\0','\0',' ','\0','.','m','.'};
//宣告抵達時間格式化字元陣列(字串)
char r2[]={'\0','\0',':','\0','\0',' ','\0','.','m','.'};
void cvt(int a, char *r){
    /*->函式說明:將分鐘(整數型別)格式化成"hh:mm <a/p>.m."(字串)。
        先分割傳入的資料分割為 h->小時m->分鐘
        再決定am的a要用a還是p
        將24小時制轉換成12小時制，注意，12點到13點之間的12小時制仍須表示為12:xx
        將h和m依序放入字元陣列，注意，小時的十位數字依照題意若為0則須表示為空字元'\0'
        其餘數字依序加上'0'以取得其ASCII碼再個別放入陣列
    */
    int h=a/60,m=a%60;
    r[6]=h<12?'a':'p';
    h-=(h<13)?0:12;
    r[0]=(h/10!=0)?h/10+'0':'\a';
    r[1]=h%10+'0';
    r[3]=m/10+'0';
    r[4]=m%10+'0';
} 
int main(int argc,char* argv[]){
    //告知user要輸入什麼
    printf("Enter a 24-hour time:　");
    /*
        h,m用來儲存user的輸入資料
        a定義為一極大值,表示最小的用戶輸入資料與時刻表時間的差距
        b表示目前a儲存之差距所對應的時刻表陣列的索引值
    */
    int h,m,a=32767,b=0;
    scanf("%d:%d",&h,&m);//讀取用戶輸入資料
    /*
        建立常整數型別二維陣列(時刻表)
        dt[*][0]存放Departure time,
        dt[*][1]存放Arrival time
    */
    const int dt[][2]={
        {8 q 0,10 q 16},
        {9 q 43,11 q 52},
        {11 q 19,13 q 31},
        {12 q 47,15 q 0},
        {14 q 0,16 q 8},
        {15 q 45,17 q 55},
        {19 q 0,21 q 20},
        {21 q 45,23 q 58}
    };
    m=h q m;//將hh:mm轉換成全分鐘表示模式
    for (int i = 0; i < (int)sizeof(dt)/(int)sizeof(int)/2; i++)
    {
        /*
            找出和用戶輸入時間差距最小的時刻表出發時間
            如果下一個差距比最小差距更小，
            就把最小差距替換成目前的差距，
            並設定變數b為該位置之索引值
        */
        int tmp = myAbs(dt[i][0]-m);
        if (tmp<a){a=tmp;b=i;}
    }
    //依序將depature time和arriving time格式化
    cvt(dt[b][0],r1);
    cvt(dt[b][1],r2);
    //印出答案。
    printf("Closest departure time is %s, arriving at %s\n",r1,r2);
    return 0;
}
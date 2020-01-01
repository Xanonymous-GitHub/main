/*****************************************************************/
/* Class: Computer Programming, Fall 2019                        */
/* Author: 林天佑                                                 */
/* ID: 108820003                                                 */
/* Date: 2019.11.23                                              */
/* Purpose: Be the best student.                                 */
/* GitHub:  https://github.com/Xanonymous-GitHub/main/tree/HW    */
/*****************************************************************/

//  ->   咦？這題之前不是要求要12小時制嗎....？
//  ->   2:52和2:53是個值得測試的時間點呢.....

#include <stdio.h>
#define q *60 +
/*
    建立常整數型別二維陣列(時刻表)
    dt[*][0]存放Departure time,
    dt[*][1]存放Arrival time
*/
const int dt[][2] = {
    {8 q 0, 10 q 16},
    {9 q 43, 11 q 52},
    {11 q 19, 13 q 31},
    {12 q 47, 15 q 0},
    {14 q 0, 16 q 8},
    {15 q 45, 17 q 55},
    {19 q 0, 21 q 20},
    {21 q 45, 23 q 58}};
int myAbs(int a) {
    //自製絕對值函式
    if (a < 0)
        return -a;
    return a;
}
void cvt(int a, char *r) {
    /*->函式說明:將分鐘(整數型別)格式化成"hh:mm <a/p>.m."(字串)。
        先分割傳入的資料分割為 h->小時m->分鐘
        再決定am的a要用a還是p
        將24小時制轉換成12小時制，注意，12點到13點之間的12小時制仍須表示為12:xx
        將h和m依序放入字元陣列，注意，小時的十位數字依照題意若為0則須表示為空字元'\0'
        其餘數字依序加上'0'以取得其ASCII碼再個別放入陣列
    但是    本題不使用12小時制，所以以上註解看看就好。
    */
    int h = a / 60, m = a % 60;
    // r[6] = h < 12 ? 'a' : 'p';
    // h -= (h < 13) ? 0 : 12;
    r[0] = (h / 10 != 0) ? h / 10 + '0' : '\a';
    r[1] = h % 10 + '0';
    r[3] = m / 10 + '0';
    r[4] = m % 10 + '0';
}
void find_closest_flight(int desired_time, char *departure_time, char *arrival_time) {
    /*
        a定義為一極大值,表示最小的用戶輸入資料與時刻表時間的差距
        b表示目前a儲存之差距所對應的時刻表陣列的索引值
    */
    int a = 32767, b = 0;
    for (int i = 0; i < (int)sizeof(dt) / (int)sizeof(int) / 2; i++) {
        /*
            找出和用戶輸入時間差距最小的時刻表出發時間
            如果下一個差距比最小差距更小，
            就把最小差距替換成目前的差距，
            並設定變數b為該位置之索引值
        */
        int tmp = myAbs(dt[i][0] - desired_time);
        if (tmp < a) {
            a = tmp;
            b = i;
        }
    }
    /*
        精隨概念:題目並未定義最接近之起飛時間是否為同一天，因此必須考慮與前一天最晚時間之距離。
        對折法：將最晚時間與換日時間點之距離對折至換日時間點之前，以負數表示。
    */
    int itmp = ((int)sizeof(dt) / (int)sizeof(int)) / 2 - 1;   //時刻表最晚時間之索引值
    int stmp = myAbs((dt[itmp][0] - (24 q 0)) - desired_time); //與對折時間點之距離
    if (stmp < a) {
        a = stmp;
        b = itmp;
    } //若更近，則使用此對折時間點(即為前日最後時間點)
    //依序將depature time和arriving time格式化
    cvt(dt[b][0], departure_time);
    cvt(dt[b][1], arrival_time);
}
static char r1[] = {'\0', '\0', ':', '\0', '\0'}; //宣告起飛時間格式化字元陣列(字串)
static char r0[] = {'\0', '\0', ':', '\0', '\0'}; //技術性阻止記憶體區段誤連
static char r2[] = {'\0', '\0', ':', '\0', '\0'}; //宣告抵達時間格式化字元陣列(字串)
int main(int argc, char *argv[]) {
    printf("Enter a 24-hour time : "); //告知user要輸入什麼
    //h,m用來儲存user的輸入資料
    int h, m;
    scanf("%d:%d", &h, &m); //讀取用戶輸入資料
    find_closest_flight(h q m, r1, r2);
    printf("Closest departure time is %s, arriving at %s\n", &r1[0], &r2[0]); //印出答案。
    return 0;
}
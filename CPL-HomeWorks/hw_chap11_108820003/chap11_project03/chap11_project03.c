/*****************************************************************/
/* Class: Computer Programming, Fall 2019                        */
/* Author: 林天佑                                                 */
/* ID: 108820003                                                 */
/* Date: 2019.11.23                                              */
/* Purpose: Be the best student.                                 */
/* GitHub:  https://github.com/Xanonymous-GitHub/main/tree/HW    */
/*****************************************************************/
#include <stdio.h>
int GCD(int a, int b) {
    //輾轉相除法(遞迴)
    if (!(a))
        return b;
    if (!(b))
        return a;
    return GCD(b, (a - b * (a / b)));
}
void a_unnecessary_function(int n, int d, int *r_n, int *r_d) {
    //取得最大公因數
    int gcd = GCD((d > n) ? d : n, (d < n) ? d : n); //gcd()函式被設定為第一個數要大於第二個數，故使用條件判斷來傳遞參數。
    //分子分母除以最大公因數就成為最簡分數。
    *r_n = n / gcd;
    *r_d = d / gcd;
}
int main(int argc, char *argv[]) {
    int c1 = 1, c2 = 1;            //c1是分子，c2是分母
    printf("Enter a fraction: "); //顯示輸入訊息
    scanf("%d/%d", &c1, &c2);      //取得輸入資料
    a_unnecessary_function(c1, c2, &c1, &c2);
    printf("In lowest terms: %d/%d\n", c1, c2); //輸出最簡分數與提示訊息。
    return 0;
}
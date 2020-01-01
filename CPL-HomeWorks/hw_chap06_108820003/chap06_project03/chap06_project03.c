/*****************************************************************/
/* Class: Computer Programming, Fall 2019                        */
/* Author: 林天佑                                                 */
/* ID: 108820003                                                 */
/* Date: 2019.10.09                                              */
/* Purpose: Be the best student.                                 */
/* GitHub:  https://github.com/Xanonymous-GitHub/main/tree/HW    */
/*****************************************************************/
#include<stdio.h>
int GCD(int a,int b){
    //輾轉相除法(遞迴)
    if(!(a))return b;
    if(!(b))return a;
    return GCD(b,(a-b*(a/b)));
}
int main(int argc,char* argv[]){
    int c1=1,c2=1,gcd=0;//c1是分子，c2是分母，gcd儲存最大公因數
    printf("Enter a fraction : ");//顯示輸入訊息
    scanf("%d/%d",&c1,&c2);//取得輸入資料
    /*
        gcd()函式被設定為第一個數要大於第二個數，故使用條件判斷來傳遞參數。
    */
    gcd=GCD((c2>c1)?c2:c1,(c2<c1)?c2:c1);//取得最大公因數
    //分子分母除以最大公因數就成為最簡分數。
    printf("In lowest terms : %d/%d\n",c1/gcd,c2/gcd);//輸出最簡分數與提示訊息。
    return 0;
}
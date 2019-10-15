/*****************************************************************/
/* Class: Computer Programming, Fall 2019                        */
/* Author: 林天佑                                                 */
/* ID: 108820003                                                 */
/* Date: 2019.10.12                                              */
/* Purpose: Be the best student.                                 */
/* GitHub:  https://github.com/Xanonymous-GitHub/main/tree/HW    */
/*****************************************************************/
#include<stdio.h>
double ngia(int n){
    //計算某數的n階乘
    long result=1;//定義一將要被乘的變數
    for (int i = 1; i < n+1; i++)result*=i;//開始乘，每次乘數+1
    return result;//返回答案
}
int main(int argc,char* argv[]){
    /* <原題意要求>
    printf("Enter a number: ");//提示輸入訊息
    int n=0;//除存輸入資料
    double e=1;//定義除存結果的變數，並已經+1
    scanf("%d",&n);//接收輸入
    */
    int n=10;//教授強制規定n==10
    double e=1;//定義除存結果的變數，並已經+1
    for (int i = n; i > 0; i--){
        e+=1/ngia(i);//每次加入i階分之一
    }
    //printf("The e value of input is %.50lf\n",e);
    printf("Approximation of e: %f\n",e);
    /*  
        limit(x->無窮):1+1/1!+1/2!+.....1/x!近似於以下數字
        2.71828182845904553488480814849026501178741455078125 
        該數字就是題目的極限答案(double的極限位數)，因此預設輸出50位數的小數點。
        但
        教授要求了QQ
        不准輸出double的極限位數(50位)，所以用f而已
    */
    return 0;
}
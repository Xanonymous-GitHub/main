/*****************************************************************/
/* Class: Computer Programming, Fall 2019                        */
/* Author: 林天佑                                                 */
/* ID: 108820003                                                 */
/* Date: 2019.09.19                                              */
/* Purpose: Be the best student.                                 */
/* GitHub:  https://github.com/Xanonymous-GitHub/main/tree/HW    */
/*****************************************************************/
#include<stdio.h>
#include<math.h>
double myPow(int base,int p){
    //由於gcc編譯器編譯pow()函式時須加入-lm參數太過麻煩，因此自製次方函數。
    double result=1;//初始值
    if(p>=0){
        //如果次方數為正或0，則用乘法
        for (int i = 0; i < p; i++)result*=base;
    }else{
        //如果次方數為負數，則用除法
        for (int i = 0; i > p; i--)result/=base;
    }
    return result;
}
int main(int argc,char* argv[]){
    /*
        data->原始資料(使用者輸入)
        result->結果資料(Dec to Oct)
        i->一個遞增數，用來紀錄現在是要乘以10的幾次方。
    */
    int data=0,result=0,i=0;
    printf("Enter a number between 0 and 32767: ");
    scanf("%d",&data);
    /*
        本程式使用長除法進行計算，不斷的將被除數除以8，取其餘數依序作為新8進位數的數。
        例如：第一餘數即為新8進位數的個位數，在繼續除以8的第二餘數即為十位數。
        當被除數<除數時，停止運算。
    */
    while (data>=8){
        /*
            x^y => pow([x],[y])=__float__ (@math.h)
            將餘數依序乘以10的i次方，i從0開始遞增，
            即10^0=1,10^1=10,10^2=100,......
            如此即可用餘數構成一新的整數(即本題所求)。
        */
        result+=(data%8)*((int)myPow(10,i++));
        //新增餘數後，必須將data實際的除以8，以交給下一個while使用。
        data/=8;
    }
    /*
        最後輸出結果時，仍須計入最終餘數(data)，由於data是最後的餘數，
        因此要在答案最左邊位數新增一位數，並放入data。
        本次為最後計算，因此i無須繼續遞增。
    */
    printf("In octal, your number is: %05d\n",result+data*((int)myPow(10,i)));    
    return 0;
}
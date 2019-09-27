/*****************************************************************/
/* Class: Computer Programming, Fall 2019                        */
/* Author: 林天佑                                                 */
/* ID: 108820003                                                 */
/* Date: 2019.09.23                                              */
/* Purpose: Be the best student.                                 */
/* GitHub:  https://github.com/Xanonymous-GitHub/main/tree/HW    */
/*****************************************************************/
#include<stdio.h>
int main(int argc,char* argv[]){
    //告知user要輸入什麼
    printf("Enter four intergers: ");
    int b=-32767,s=32767,n=0;
    /*
        建立變數，b用以除存最大數，初始為最小值
        s除存最小數，初始為最大值
        n暫存輸入的4組數字
    */
    for (int i = 0; i < 4; i++)
    {
        scanf("%d",&n);//讀取1個整數
        /*
            如果讀取到的數字比先前最大數字還要大
            就把最大數改成目前讀取的數
            最小數同理
        */
        if (n>b)b=n;
        if (n<s)s=n;
    }
    //輸出結果
    printf("Largest: %d\nSmallest: %d\n",b,s);
    return 0;
}
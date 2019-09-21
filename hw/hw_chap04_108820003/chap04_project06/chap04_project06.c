/*****************************************************************/
/* Class: Computer Programming, Fall 2019                        */
/* Author: 林天佑                                                 */
/* ID: 108820003                                                 */
/* Date: 2019.09.17                                              */
/* Purpose: Be the best student.                                 */
/* GitHub:  https://github.com/Xanonymous-GitHub/main/tree/HW    */
/*****************************************************************/
#include<stdio.h>
#include<stdlib.h>
int main(int argc,char* argv[]){
    /*
        i->遞增變數，用來紀錄現在getchar()讀取到第幾個字。
        a->原資料的第1,3,5,7,9,11位數。(second sum)
        b->原資料的第2,4,6,8,10,12位數。(first sum)
        q->旗標變數
        data->存放當前讀取的字元。
    */
    int i=0,a=0,b=0,q=0;
    char data;
    printf("Enter the first 12 digits of an EAN: ");
    while (i++<12){
        //getchar()會一次讀取一個字元給data。
        data=getchar();
        //atoi(const char*) 會將傳入的指標字元變數之值轉換為整數型別。
        if(q) b+=atoi(&data);
        else a+=atoi(&data);
        q=!q;
    }
    printf("Check digit: %d\n",9-(3*b+a-1)%10);
    return 0;
}
/*****************************************************************/
/* Class: Computer Programming, Fall 2019                        */
/* Author: 林天佑                                                 */
/* ID: 108820003                                                 */
/* Date: 2019.10.12                                              */
/* Purpose: Be the best student.                                 */
/* GitHub:  https://github.com/Xanonymous-GitHub/main/tree/HW    */
/*****************************************************************/
#include<stdio.h>
int main(int argc,char* argv[]){
    printf("Enter a integer : ");//提示輸入訊息
    long long data=0;//除存輸入資料
    scanf("%lld",&data);//接收輸入
    printf("Digits reversed : ");//輸出提示訊息
    do{
        /*
            原資料除以10的餘數就是該數的最末位數，依序輸出到CLI(Command Line Interface)，將逆向重組。
            取得餘數後，將原資料更改為本身除以10的商，即可達到有如刪除末位之效果。
            當原數字最高位變成新數字最末位輸出後，原資料再次更改為本身除以10的商，會得到0。
        */
        printf("%lld",data%10);//輸出原資料除以10的餘數
        data/=10;//將原資料更改為本身除以10的商
    }while(data);//若資料尚未變成0則繼續執行操作。
    return 0;
}
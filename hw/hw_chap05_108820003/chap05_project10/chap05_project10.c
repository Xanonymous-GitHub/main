/*****************************************************************/
/* Class: Computer Programming, Fall 2019                        */
/* Author: 林天佑                                                 */
/* ID: 108820003                                                 */
/* Date: 2019.09.27                                              */
/* Purpose: Be the best student.                                 */
/* GitHub:  https://github.com/Xanonymous-GitHub/main/tree/HW    */
/*****************************************************************/
#include<stdio.h>
int main(int argc,char* argv[]){
    printf("Enter a two-digit number: ");//告知user要輸入什麼
    int d,e=1;//e為旗標變數
    char s='\0';//s為分類結果
    scanf("%d",&d);//存入變數
    if(d<0||d>100)e=!e;//判斷是否超出範圍
    else{
        switch (d/10)
        {
            case 10:
                s='A';
                break;
            case 9:
                s='A';
                break;
            case 8:
                s='B';
                break;
            case 7:
                s='C';
                break;
            case 6:
                s='D';
                break;
            default:
                s='F';
                break;
        }
    }
    if(e)printf("Letter grade: %c\n",s);//正常輸出結果
    if(!(e))printf("Wrong score!\n");//錯誤訊息
    return 0;
}
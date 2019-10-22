//*****************************************************************/
/* Class: Computer Programming, Fall 2019                        */
/* Author: 林天佑                                                 */
/* ID: 108820003                                                 */
/* Date: 2019.10.12                                              */
/* Purpose: Be the best student.                                 */
/* GitHub:  https://github.com/Xanonymous-GitHub/main/tree/HW    */
/*****************************************************************/
#include <stdio.h>
#define len 1000
char data[len];
int main(int argc,char* argv[]) {
		printf("Enter a integer : ");//提示輸入訊息
		scanf("%s",data);//讀取輸入
		printf("Digits reversed : \n");//輸出提示訊息
		for(int i=len-1;i>=0;i--)//逆向迴圈
                printf("%c",data[i]);//逆向輸出
		printf("\n");//換行
    return 0;
}

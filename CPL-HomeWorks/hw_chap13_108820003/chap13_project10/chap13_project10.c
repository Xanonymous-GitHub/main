/*****************************************************************/
/* Class: Computer Programming, Fall 2019                        */
/* Author: 林天佑                                                 */
/* ID: 108820003                                                 */
/* Date: 2019.12.20                                              */
/* Purpose: Be the best student.                                 */
/* GitHub:  https://github.com/Xanonymous-GitHub/main/tree/HW    */
/*****************************************************************/
#include <stdio.h>
#include <string.h>
char *reverse_name(char *name) {
    char *x = name - 1;//建立空白指標
    while (*(++x) != ' ');//定位到空白處
    *x = 0;//切割
    while (*(++x) == ' ');//定位到下一個字元起始位置
    return x;//傳回該位置
}
int main(int argc, char *argv[]) {
    char name[1000] = {'\0'};//建立字元陣列                
    printf("Enter a first and last name: ");//顯示輸出訊息
    fgets(name, sizeof(name), stdin);//取得用戶輸入
    int len = strlen(name);//取得字串長度
    if (name[len - 1] == '\n') name[len - 1] = 0;//除掉換行符號
    printf("%s, %c.\n", reverse_name(name), *name > 96 ? *name - 32 : *name);//顯示結果
    return 0;
}
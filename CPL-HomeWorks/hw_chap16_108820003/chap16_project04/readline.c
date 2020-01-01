#include "readline.h"
#include <ctype.h>
#include <stdio.h>
int read_line(char str[], int n) {//實做界面
    int ch, i = 0;
    while (isspace(ch = getchar()));//抓到空格
    while (ch != '\n' && ch != EOF) {//直到換行或結束檔案資料流
        if (i < n) {//若小於上限
            str[i++] = ch;//灌入字元
        }
        ch = getchar();//取下一個
    }
    str[i] = '\0';//末尾切斷
    return i;//返回長度
}
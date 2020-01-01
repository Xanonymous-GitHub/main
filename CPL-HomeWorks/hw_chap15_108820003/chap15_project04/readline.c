#include <stdio.h>
int read_line(char str[], int n) {
    int ch, i = 0;//建立字元暫存變數
    while ((ch = getchar()) != '\n') {//在換行前不斷讀取字元
        if (i < n) {//在尚未超過上限前進行讀取
            str[i++] = ch;//讀取
        }
    }
    str[i] = '\0';//切斷末尾
    return i;//技術性返回
}
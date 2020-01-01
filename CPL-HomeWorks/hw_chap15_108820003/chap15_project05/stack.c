#include <stdio.h>
#include <stdlib.h>
#define MAX_LEN 100 //定義stack大小
int push(int *data, int *top, int obj) {
    /*  Stack::push,將新資料放至堆疊頂端
        *data:資料陣列(指標)
        *top:頂端位置(指標)
        obj:新資料
    */
    if (*top >= MAX_LEN - 1) //如果頂端已達到stack大小或超過
    {
        printf("\nExpression is too complex\n"); //輸出堆疊溢出訊息
        exit(0);                               //程式停止
    }
    data[++(*top)] = obj; //將新物件放至堆疊頂端
    return 1;
}
int pop(int *data, int *top) {
    /*  Stack::pop,將頂層資料取出
        *data:資料陣列(指標)
        *top:頂端位置(指標)
    */
    if (*top < 0) //如果為空堆疊
    {
        printf("\nNot enough operends in expression\n"); //輸出空堆疊訊息
        exit(0);                                       //程式停止
    }
    return data[(*top)--]; //回傳自堆的頂端取下的項並將頂層位置往下設定
}
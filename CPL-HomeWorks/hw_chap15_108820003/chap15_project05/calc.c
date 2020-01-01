/*****************************************************************/
/* Class: Computer Programming, Fall 2019                        */
/* Author: 林天佑                                                 */
/* ID: 108820003                                                 */
/* Date: 2019.12.22                                              */
/* Purpose: Be the best student.                                 */
/* GitHub:  https://github.com/Xanonymous-GitHub/main/tree/HW    */
/*****************************************************************/
#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#define MAX_LEN 100 //定義stack大小
#define PUSH push(&Stack[0], &Top, c - '0')
#define POP pop(&Stack[0], &Top)

int main(int argc, char *argv[]) {
    while (1) {
        /*
            Top:頂端位置
            Stack:堆疊本體
            c:目前所讀取之字元
            tmp:暫存pop出的值
        */
        int Top = -1, tmp = 0;
        int Stack[MAX_LEN];
        char c;
        printf("Enter an RPN expression : "); //顯示輸入訊息
        while (1) {
            scanf(" %c", &c); //讀取輸入
            switch (c) {      //判定輸入
            case 1 + '0':
            case 2 + '0':
            case 3 + '0':
            case 4 + '0':
            case 5 + '0':
            case 6 + '0':
            case 7 + '0':
            case 8 + '0':
            case 9 + '0':
            case 0 + '0':
                PUSH; //放入堆疊
                break;
            case '+':
                //將末兩元素相加後放入堆疊
                push(&Stack[0], &Top, (POP + POP));
                break;
            case '-':
                //將末兩元素相減後放入堆疊
                tmp = POP;
                push(&Stack[0], &Top, (POP - tmp));
                break;
            case '*':
                //將末兩元素相乘後放入堆疊
                push(&Stack[0], &Top, (POP * POP));
                break;
            case '/':
                //將末兩元素相除後放入堆疊
                tmp = POP;
                push(&Stack[0], &Top, (POP / tmp));
                break;
            case '=':                                      //如果結束運算
                printf("Value of expression : %d\n", POP); //取出堆疊頂層結果
                printf("Enter an RPN expression : ");      //再次顯示輸入訊息，進入下回合
                Top = -1;                                  //堆疊清空
                break;
            default:     //如果輸入詭異字元
                exit(0); //程式停止
                break;
            }
        }
    }
    return 0;
}
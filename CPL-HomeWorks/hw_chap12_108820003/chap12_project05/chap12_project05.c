/*****************************************************************/
/* Class: Computer Programming, Fall 2019                        */
/* Author: 林天佑                                                 */
/* ID: 108820003                                                 */
/* Date: 2019.12.08                                              */
/* Purpose: Be the best student.                                 */
/* GitHub:  https://github.com/Xanonymous-GitHub/main/tree/HW    */
/*****************************************************************/
#include <stdio.h>
#define STR_ANOUNT 1000 //英文單字數量限制
#define STR_LENTH 1000  //每個單字字母數限制
int main(int argc, char *argv[]) {
    /*
        data[][]儲存資料，假設輸入不超過STR_ANOUNT個英文單字，且每個單字不超過STR_LENTH個字母
        end 儲存末尾標記符號，根據題意，?!.三個是結束符號
        pos紀錄現在判斷到第幾個"單字"
    */
    char data[STR_ANOUNT][STR_LENTH], end = '\0';
    char *p = *data;
    int pos = 0;
    printf("Enter a sentence: "); //顯示輸入訊息
    while (1)                     //不斷嘗試
    {
        //tmp_pos紀錄現在判斷到這個單字中的第幾個字母
        //_break旗標變數，若找到末尾標記則標示為可停止尋找
        int tmp_pos = 0, _break = 0;
        scanf("%s", p+(pos*STR_LENTH)); //以"單字"為單位存入陣列
        while (*(p + (pos * STR_LENTH)+tmp_pos))   //不斷重複，直到找到'\0'
        {
            if (*(p + (pos * STR_LENTH) + tmp_pos) == '?' || *(p + (pos * STR_LENTH) + tmp_pos) == '!' || *(p + (pos * STR_LENTH) + tmp_pos) == '.') {
                /*
                    如果發現末尾標記，則
                    1.以end變數儲存末尾標記
                    2.將末尾標記處換為空(即'\0')
                    3.標記為可停止尋找
                */
                end = *(p + (pos * STR_LENTH) + tmp_pos);
                *(p + (pos * STR_LENTH) + tmp_pos) = '\0';
                _break = !_break;
                break;
            }
            tmp_pos++; //若該字元非末尾標記，則移動至該單字的下一個字母
        }
        if (_break) //如果標記為可停止尋找
            break;  //跳出吃字
        pos++;      //否則將單字位置移到下一個點，準備接收下一個英文單字
    }
    printf("Reversal of sentence: "); //輸出提示訊息
    while (pos > 0)                   //當pos大於0就繼續跑，刻意少輸出一個單字
    {
        //依序將資料以"單字"為單位逆向輸出並以一個空格分開
        printf("%s ", (p + ((pos--) * STR_LENTH)));
    }
    printf("%s", (p + (pos * STR_LENTH))); //僅輸出最後單字，後面無空格
    printf("%c\n", end);     //最後補上末尾標記字元
    return 0;
}
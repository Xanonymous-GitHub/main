/*****************************************************************/
/* Class: Computer Programming, Fall 2019                        */
/* Author: 林天佑                                                 */
/* ID: 108820003                                                 */
/* Date: 2019.11.06                                              */
/* Purpose: Be the best student.                                 */
/* GitHub:  https://github.com/Xanonymous-GitHub/main/tree/HW    */
/*****************************************************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_INPUT_LENGTH 100 //最大輸入數字筆數
int *selection_sort(int *data, int size)
{
    /*
        base:選擇排序的最前項
        min:最小值的索引值
        count:當前判斷的位置
    */
    int base, min, count;
    for (base = 0; base < size - 1; base++) //判斷到倒數第一位
    {
        min = base;                                   //預設最小值是在基底
        for (count = base + 1; count < size; count++) //開始判斷基底後的所有項
        {
            if (*(data + count) < *(data + min)) //如果這項小於基底
            {
                min = count; //將最小項位置設定到這個位置
            }
        }
        /*
            找到後，將最小數與基底交換
        */
        int tmp = *(data + min);
        *(data + min) = *(data + base);
        *(data + base) = tmp;
    }
    return data; //傳回記憶體位址
}
int main(int argc, char *argv[])
{
    printf("Enter list of integers to be sorted: "); //顯示輸入訊息
    /*
        size:輸入的資筆數
        data:儲存輸入的數字們
    */
    int size = 0, data[MAX_INPUT_LENGTH];
    char c;
    while ((size < MAX_INPUT_LENGTH) && ((c = getchar()) != '\n')) //限制不要讀取超過筆數限制且非最後項
    {
        ungetc(c, stdin);           //退回預判字元到標準輸入流
        scanf("%d", &data[size++]); //從stdin讀取一個數字
    }
    int *result = selection_sort(&data[0], size); //建立指標，指向選擇排序後的回傳位址
    printf("Sorted list: ");                      //顯示輸出訊息
    for (int i = 0; i < size - 1; i++)            //將結果輸出但保留最後位
    {
        printf("%d ", result[i]);
    }
    printf("%d\n", result[size - 1]); //輸出最後位並換行，避免多餘空格
    return 0;
}
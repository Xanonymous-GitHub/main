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
// >>>use_recursive_to_get_selection_sort_is_stupid<<<
// >>>use_recursive_to_get_selection_sort_is_stupid<<<
// >>>use_recursive_to_get_selection_sort_is_stupid<<<
// >>>use_recursive_to_get_selection_sort_is_stupid<<<
// >>>use_recursive_to_get_selection_sort_is_stupid<<<
// >>>use_recursive_to_get_selection_sort_is_stupid<<<
// >>>use_recursive_to_get_selection_sort_is_stupid<<<
// >>>use_recursive_to_get_selection_sort_is_stupid<<<
// >>>use_recursive_to_get_selection_sort_is_stupid<<<
// >>>use_recursive_to_get_selection_sort_is_stupid<<<
// >>>use_recursive_to_get_selection_sort_is_stupid<<<
// >>>use_recursive_to_get_selection_sort_is_stupid<<<
// int *selection_sort(int *data, int size)
// {
//     /*
//         base:選擇排序的最前項
//         min:最小值的索引值
//         count:當前判斷的位置
//     */
//     int base, min, count;
//     for (base = 0; base < size - 1; base++) //判斷到倒數第一位
//     {
//         min = base;                                   //預設最小值是在基底
//         for (count = base + 1; count < size; count++) //開始判斷基底後的所有項
//         {
//             if (*(data + count) < *(data + min)) //如果這項小於基底
//             {
//                 min = count; //將最小項位置設定到這個位置
//             }
//         }
//         /*
//             找到後，將最小數與基底交換
//         */
//         int tmp = *(data + min);
//         *(data + min) = *(data + base);
//         *(data + base) = tmp;
//     }
//     return data; //傳回記憶體位址
// }
int selection_sort(int data[MAX_INPUT_LENGTH], int n)
{               // >>>use_recursive_to_get_selection_sort_is_stupid<<<
    if (n == 1) //剩下一項時表示排序結束，將函式停止
    {
        return 0;
    }
    int max = n - 1,i;                //定義基底是函數最後項
    for (i = 0; i < n - 1; i++) //在頭到尾前一項執行判斷
    {
        if (data[i] > data[max]) //如果某項大於當前最大項
        {
            max = i; //該項成為最大項
        }
    }
    //將最大項與基底交換
    int tmp = data[n - 1];
    data[n - 1] = data[max];
    data[max] = tmp;
    return selection_sort(data, n - 1); //遞迴發出，呼叫下一個執行階段
}
int main(int argc, char *argv[])
{
    printf("Enter list of integers to be sorted: "); //顯示輸入訊息
    /*
        size:輸入的資筆數
        data:儲存輸入的數字們
    */
    int size = 0, data[MAX_INPUT_LENGTH],i;
    char c;
    while ((size < MAX_INPUT_LENGTH) && ((c = getchar()) != '\n')) //限制不要讀取超過筆數限制且非最後項
    {
        ungetc(c, stdin);           //退回預判字元到標準輸入流
        scanf("%d", &data[size++]); //從stdin讀取一個數字
    }
    selection_sort(data, size);        //以使用遞迴的選擇排序法排序陣列(不建議)
    printf("Sorted list: ");           //顯示輸出訊息
    for (i = 0; i < size - 1; i++) //將結果輸出但保留最後位
    {
        printf("%d ", data[i]);
    }
    printf("%d\n", data[size - 1]); //輸出最後位並換行，避免多餘空格
    return 0;
}
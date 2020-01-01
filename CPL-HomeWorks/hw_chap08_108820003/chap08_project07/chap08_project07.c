/*****************************************************************/
/* Class: Computer Programming, Fall 2019                        */
/* Author: 林天佑                                                 */
/* ID: 108820003                                                 */
/* Date: 2019.10.29                                              */
/* Purpose: Be the best student.                                 */
/* GitHub:  https://github.com/Xanonymous-GitHub/main/tree/HW    */
/*****************************************************************/
#include <stdio.h>
int main(int argc, char *argv[])
{
    /*
        data[][]儲存用戶輸入資料
        row[]儲存每個row的橫向加總
        col[]儲存每個col的縱向加總
    */
    int data[7][7] = {0}, row[7] = {0}, col[7] = {0};
    //第一步，獲取輸入資料
    for (int i = 0; i < 5; i++)
    {
        printf("Enter row %d: ", i + 1); //依照行數顯示輸入訊息
        for (int j = 0; j < 5; j++)
        {
            scanf("%d", &data[i][j]); //取得一筆資料
        }
    }
    //第二步，計算加總
    for (int i = 0; i < 5; i++)
    {
        /*
            tmpr儲存該row的加總
            tmpc儲存該col的加總
        */
        int tmpr = 0, tmpc = 0;
        for (int j = 0; j < 5; j++)
        {
            /*
                tmpr以橫向方式加總
                tmpc以縱向方式加總
                同時進行，彼此不打架
            */
            tmpr += data[i][j];
            tmpc += data[j][i];
        }
        //加總後將結果放入陣列
        row[i] = tmpr; //將該行橫向加總放入用來儲存每行加總的陣列
        col[i] = tmpc; //將該列縱向加總放入用來儲存每列加總的陣列
    }
    printf("Row totals: "); //顯示輸出訊息
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", row[i]); //輸出每行加總
    }
    printf("\n");              //依照題意換行
    printf("Column totals: "); //顯示輸出訊息
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", col[i]); //輸出每列加總
    }
    printf("\n"); //依照題意換行
    return 0;
}
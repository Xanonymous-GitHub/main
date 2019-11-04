/*****************************************************************/
/* Class: Computer Programming, Fall 2019                        */
/* Author: 林天佑                                                 */
/* ID: 108820003                                                 */
/* Date: 2019.11.04                                              */
/* Purpose: Be the best student.                                 */
/* GitHub:  https://github.com/Xanonymous-GitHub/main/tree/HW    */
/*****************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
char my_map[10][10]; //總地圖陣列
int getmap()         //取得亂數地圖的函式
{
    char now = 65;//現在要填入的英文字母，預設為A
    int posx = 0, posy = 0;//儲存上一個填寫的位置(分別為x,y)
    memset(my_map, 46, sizeof(my_map));//清空地圖
    for (int i = 0; i < 26; i++)//共26英文字母要填入
    {
        int a = 0, b = 0, c = 0, d = 0;//旗標變數，分別代表4個不同方向，若為0表示尚未嘗試填入。
        if (!(i))//若第一次填
        {
            my_map[0][0] = now++;//在0,0填入A並將now+1
            continue;//跳離迴圈並繼續
        }
        int putted = 1; //旗標變數，若1表示尚未填字母
        while (putted)  //當尚未填字母
        {
            if ((a + b + c + d) == 4)
            { //如果4方位都試過，表示該操作失敗，需完全重來，跳離函式
                return 0;//傳回失敗
            }
            int tmp = (rand() % (4)) + 1;//產生1-4的亂數
            switch (tmp)//依照亂數決定欲嘗試之方位
            {
            case 1:
                if ((!(a)) && (posx + 1 < 10) && (my_map[posx + 1][posy] == 46))
                {
                    /*
                        達到以下條件就往下填字母：
                        1.未被嘗試
                        2.那個位置未超出地圖範圍
                        3.那個位置是空的
                    */
                    my_map[++posx][posy] = now++;//填入字母
                    putted = !putted;//標記為已填過
                }
                else//若不可填入
                {
                    a = 1;//將該方位標記為已試過
                }
                break;
            case 2:
                if ((!(b)) && (posx - 1 >= 0) && (my_map[posx - 1][posy] == 46))
                {
                    /*
                        達到以下條件就往上填字母：
                        1.未被嘗試
                        2.那個位置未超出地圖範圍
                        3.那個位置是空的
                    */
                    my_map[--posx][posy] = now++; //填入字母
                    putted = !putted;             //標記為已填過
                }
                else //若不可填入
                {
                    b = 1; //將該方位標記為已試過
                }
                break;
            case 3:
                if ((!(c)) && (posy + 1 < 10) && (my_map[posx][posy + 1] == 46))
                {
                    /*
                        達到以下條件就往右填字母：
                        1.未被嘗試
                        2.那個位置未超出地圖範圍
                        3.那個位置是空的
                    */
                    my_map[posx][++posy] = now++; //填入字母
                    putted = !putted;             //標記為已填過
                }
                else //若不可填入
                {
                    c = 1; //將該方位標記為已試過
                }
                break;
            case 4:
                if ((!(d)) && (posy - 1 >= 0) && (my_map[posx][posy - 1] == 46))
                {
                    /*
                        達到以下條件就往左填字母：
                        1.未被嘗試
                        2.那個位置未超出地圖範圍
                        3.那個位置是空的
                    */
                    my_map[posx][--posy] = now++; //填入字母
                    putted = !putted;             //標記為已填過
                }
                else //若不可填入
                {
                    d = 1; //將該方位標記為已試過
                }
                break;
            }
        }
    }
    return 1;//若完整填到z則回報為完整地圖
}
int main(int argc, char *argv[])
{
    srand((unsigned)time(NULL));//產生亂數種子
    while (1)//不斷嘗試
    {
        if (getmap())
        {
            break;//直到拿到a-z的完整地圖跳出嘗試
        }
    }
    //格式化輸出地圖
    for (int i = 0; i < 10; i++)//行
    {
        for (int j = 0; j < 9; j++)//列
        {
            printf("%c ", my_map[i][j]);//輸出地圖值
        }
        printf("%c\n", my_map[i][9]);//尾部加換行
    }
    return 0;
}
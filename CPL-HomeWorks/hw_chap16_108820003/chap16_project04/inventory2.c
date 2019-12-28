/*****************************************************************/
/* Class: Computer Programming, Fall 2019                        */
/* Author: 林天佑                                                 */
/* ID: 108820003                                                 */
/* Date: 2019.12.29                                              */
/* Purpose: Be the best student.                                 */
/* GitHub:  https://github.com/Xanonymous-GitHub/main/tree/HW    */
/*****************************************************************/
#include "readline.h"
#include <stdio.h>
#define NAME_LEN 25
#define MAX_PARTS 100
struct part {//init DB
    int number;
    char name[NAME_LEN + 1];
    float price;
    int on_hand;
} inventory[MAX_PARTS];
int num_parts = 0;
int find_part(int number) {//尋找在DB中的項目
    int i;
    for (i = 0; i < num_parts; i++) {
        if (inventory[i].number == number) {//如果找到
            return i;//回傳位置
        }
    }
    return -1;
}
void insert(void) {//新增項目至DB
    int part_number;
    if (num_parts == MAX_PARTS) {//檢查上限
        printf("Database is full; can't add more parts.\n");
        return;//超出上限
    }
    printf("Enter part number :");//提示訊息
    scanf("%d", &part_number);//讀取
    if (find_part(part_number) >= 0) {//如果找到
        printf("Part already exists.\n");//表示存在
        return;
    }
    inventory[num_parts].number = part_number;//設定資料庫屬性
    printf("Enter part name : ");//提示訊息
    read_line(inventory[num_parts].name, NAME_LEN);//讀取
    printf("Enter prise : ");//提示訊息
    scanf("%f", &inventory[num_parts].price);//讀取
    printf("Enter quantity on hand : ");//提示訊息
    scanf("%d", &inventory[num_parts].on_hand);//讀取
    num_parts++;//總數加一
}
void search(void) {
    int i, number;
    printf("Enter part number : ");//提示訊息
    scanf("%d", &number);//讀取
    i = find_part(number);//取得位置
    if (i >= 0) {//如果找到
        printf("Part name : %s\n", inventory[i].name);//顯示資料
        printf("Quantity on hand : %d\n", inventory[i].on_hand);//顯示資料
        printf("Price : $%.2f\n", inventory[i].price);//顯示資料
    } else {
        printf("Part not found.\n");//表示不存在
    }
}
void change(void) {
    int i, number;
    float new_price;
    printf("Enter part number : ");//提示訊息
    scanf("%d", &number);//讀取
    i = find_part(number);//取得位置
    if (i >= 0) {//如果找到
        printf("Enter new price : ");//提示訊息
        scanf("%f", &new_price);//讀取
        inventory[i].price = new_price;//設定資料
    } else {
        printf("Part not found.\n");//表示不存在
    }
}
void update(void) {
    int i, number, change;
    printf("Enter part number : ");//提示訊息
    scanf("%d", &number);//讀取
    i = find_part(number);//取得位置
    if (i >= 0) {//如果找到
        printf("Enter change in quantity on hand : ");//提示訊息
        scanf("%d", &change);//讀取
        inventory[i].on_hand = change;//設定資料
    } else {
        printf("Part not found.\n");//表示不存在
    }
}
void print(void) {
    int i;
    printf("Part number \t Part Name \t\t"
           "Price \t\t Quantity on Hand\n");//項目欄位
    for (i = 0; i < num_parts; i++) {
        //資料欄位
        printf("%7d \t %-25s$%2.2f \t %9d\n", inventory[i].number, inventory[i].name, inventory[i].price, inventory[i].on_hand);
    }
}
int main(int argc, char *argv[]) {
    char code;
    for (;;) {
        //直到q
        printf("Enter operation code : ");//提示訊息
        scanf(" %c", &code);//讀取
        while (getchar() != '\n');//抓到換行
        switch (code) {//判斷命令
            case 'i':
                insert();//插
                break;
            case 's':
                search();//搜
                break;
            case 'c':
                change();//改
                break;
            case 'u':
                update();//改2
                break;
            case 'p':
                print();//秀
                break;
            case 'q':
                return 0;//停
            default:
                printf("illegal code\n");//錯
        }
        printf("\n");//新行
    }
    return 0;
}
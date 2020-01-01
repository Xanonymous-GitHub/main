/*****************************************************************/
/* Class: Computer Programming, Winter 2019                        */
/* Author: 林天佑                                                 */
/* ID: 108820003                                                 */
/* Date: 2019.12.29                                              */
/* Purpose: Be the best student.                                 */
/* GitHub:  https://github.com/Xanonymous-GitHub/main/tree/HW    */
/*****************************************************************/
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#define NAME_LEN 25
#define MAX_PARTS 100
struct part { //init DB
    int number;
    char name[NAME_LEN + 1];
    float price;
    int on_hand;
    struct part *next;
};
struct part *inventory;

int num_parts = 0;
int read_line(char str[], int n) { //實做界面
    int ch, i = 0;
    while (isspace(ch = getchar()))
        ;
    while (ch != '\n' && ch != EOF) {
        if (i < n) {
            str[i++] = ch;
        }
        ch = getchar();
    }
    str[i] = '\0';
    return i;
}
struct part *find_part(int number) { //尋找在DB中的項目
    struct part *p = inventory;
    while (p != NULL && number > p->number)
        p = p->next;
    if (p != NULL && number == p->number) {
        return p;
    }
    return NULL;
}
void insert(void) { //新增項目至DB
    struct part *cur, *prev, *new_node;
    new_node = (struct part *)malloc(sizeof(struct part));
    new_node->next = NULL;
    if (new_node == NULL) {
        printf("Database is full; can't add more parts.\n");
        return;
    }
    printf("Enter part number: ");
    scanf("%d", &new_node->number);
    for (cur = inventory, prev = NULL; cur != NULL && new_node->number > cur->number; prev = cur, cur = cur->next)
        ;
    if (cur != NULL && new_node->number == cur->number) {
        printf("Part already exists.\n");
        free(new_node);
        return;
    }
    printf("Enter part name: ");
    read_line(new_node->name, NAME_LEN);
    printf("Enter quantity on hand: ");
    scanf("%d", &new_node->on_hand);
    if (cur == inventory) {
        inventory = new_node;
    } else {
        new_node->next = cur;
        prev->next = new_node;
    }
}
void search(void) {
    int number;
    struct part *p;
    printf("Enter part number: ");
    scanf("%d", &number);
    p = find_part(number);
    if (p != NULL) {
        printf("Part name: %s\n", p->name);
        printf("Quantity on hand: %d\n", p->on_hand);
    } else {
        printf("Part not found");
    }
}
void update(void) {
    int number, change;
    struct part *p;
    printf("Enter part number:　");
    scanf("%d", &number);
    p = find_part(number);
    if (p != NULL) {
        printf("Enter change in quantity on hand:　");
        scanf("%d", &change);
        p->on_hand = change;
    } else {
        printf("Part not found.\n");
    }
}
void print(void) {
    struct part *p;
    printf("Part Number    Part Name    Quantity on hand\n");
    for (p = inventory; p != NULL; p = p->next) {
        printf("%7d         %-25s%11d\n", p->number, p->name, p->on_hand);
    }
}
void erase(void) {
    /*
        [prev]-->>NONE.
        [current]-->>[head]@"inventory"
    */
    struct part *prev, *current = inventory;
    int n;
    printf("Enter part number: ");
    scanf("%d", &n);
    /*
        when [current]-->>NULL(the next node of inventory's tail),
        or the current node's "number" equal to n,
        it stop.
    */
    while ((current != NULL) && (current->number != n)) {
        prev = current;//the previous pointer now point to the origin position.
        current = current->next;//the point named current now moved to the next position.
    }
    if (current != NULL) { //if the current pointer not out of inventory's tail
        if (current == inventory) {
            /*
                if the inventory has only one node,
                or the current pointer is at the first node of inventory,
                just need to move the [head] to it's next position.
                that is equal to delete the first node of the linked list.
            */
            inventory = inventory->next;
        } else {
            /*
                if the current pointer os not at the first node,
                let the previous pointer point to the next node of current node,
                so the current is now ignored.

                            |>[current]<|
                [previous]>>>>>>>>>>>>>>>>>>[current.next]

            */
            prev->next = current->next;
        }
        /*
            so now,the position of current pointer is not need to use.
            we can release it's memory space now.
        */
        free(current);
    } else {
        /*
            the current is out of inventory's tail,
            that means there's nothing match in the custom database.
        */
        printf("Part number %d not found in database\n", n);
    }
}
int main(int argc, char *argv[]) {
    char code;
    for (;;) {
        //直到q
        printf("Enter operation code : "); //提示訊息
        scanf(" %c", &code);               //讀取
        while (getchar() != '\n')
            ;           //抓到換行
        switch (code) { //判斷命令
        case 'i':
            insert(); //插
            break;
        case 's':
            search(); //搜
            break;
        case 'u':
            update(); //改2
            break;
        case 'p':
            print(); //秀
            break;
        case 'e':
            erase();
            break;
        case 'q':
            return 0; //停
        default:
            printf("illegal code\n"); //錯
        }
        printf("\n"); //新行
    }
    return 0;
}
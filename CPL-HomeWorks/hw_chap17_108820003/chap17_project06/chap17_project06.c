/*****************************************************************/
/* Class: Computer Programming, Winter 2019                        */
/* Author: 林天佑                                                 */
/* ID: 108820003                                                 */
/* Date: 2019.12.31                                              */
/* Purpose: Be the best student.                                 */
/* GitHub:  https://github.com/Xanonymous-GitHub/main/tree/HW    */
/*****************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_WORDS 50
#define WORD_LEN 20
int read_line(char *str, int n) {
    int ch, i = 0;
    while ((ch = getchar()) != '\n') {
        if (i < n) {
            str[i++] = ch;
        }
    }
    str[i] = '\0';
    return i;
}
int compare_strings(const void *p, const void *q) {
    return strcmp(*(char **)p, *(char **)q);
}
int main(int argc, char *argv[]) {
    char *words[MAX_WORDS], word[WORD_LEN + 1];
    int i, num_words = 0;
    for (;;) { //不斷執行
        if (num_words == MAX_WORDS) {
            //沒字，停
            printf(" -- No space left --\n");
            break;
        }
        printf("Enter a word : "); //提示輸入
        read_line(word, WORD_LEN); //讀字
        if (strlen(word) == 0) {
            break; //沒字，停
        }
        //動態配置記憶體
        words[num_words] = (char *)malloc(strlen(word) + 1);
        if (words[num_words] == NULL) {
            printf(" -- No space left --\n");
            break;
        }
        //組合字
        strcpy(words[num_words], word);
        num_words++;
    }
    //排序
    qsort(words, num_words, sizeof(char *), compare_strings);
    printf("\nIn sorted order :"); //提示訊息

    for (i = 0; i < num_words; i++) {
        printf(" %s", words[i]); //輸出單字
    }
    printf("\n"); //換行
    return 0;
}
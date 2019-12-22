/*****************************************************************/
/* Class: Computer Programming, Fall 2019                        */
/* Author: 林天佑                                                 */
/* ID: 108820003                                                 */
/* Date: 2019.12.22                                              */
/* Purpose: Be the best student.                                 */
/* GitHub:  https://github.com/Xanonymous-GitHub/main/tree/HW    */
/*****************************************************************/
#include "line.h"
#include "word.h"
#include <string.h>
#define MAX_WORD_LEN 20
int main(int argc, char *argv[]) {
    char word[MAX_WORD_LEN + 2];
    clear_line();
    for (;;) {
        read_word(word, MAX_WORD_LEN + 1); //讀字
        if (strlen(word) == 0) {
            flush_line(); //沒字，停
            return 0;
        }
        if (strlen(word) + 1 > space_remaining()) {
            write_line(); //寫字
            clear_line(); //擦字
        }
        add_word(word); //加字
    }
    return 0;
}
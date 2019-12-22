/*****************************************************************/
/* Class: Computer Programming, Fall 2019                        */
/* Author: 林天佑                                                 */
/* ID: 108820003                                                 */
/* Date: 2019.                                              */
/* Purpose: Be the best student.                                 */
/* GitHub:  https://github.com/Xanonymous-GitHub/main/tree/HW    */
/*****************************************************************/
#include "line.h"
#include "word.h"
#include <string.h>
#define MAX_WORD_LEN 20
int main(int argc, char *argv[]) {
    char word[MAX_WORD_LEN + 2];
    int word_len;
    clear_line();
    for (;;) {
        read_word(word, MAX_WORD_LEN + 1);
        word_len = strlen(word);
        if (word_len == 0) {
            flush_line();
            return 0;
        }
        if (word_len > MAX_WORD_LEN)
            word[MAX_WORD_LEN] = '*';
        if (word_len + 1 > space_remaining()) {
            write_line();
            clear_line();
        }
        add_word(word);
    }
    return 0;
}
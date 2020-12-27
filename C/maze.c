/** @author
 * Xanonymous™ © 2020
 **/

#include <stdio.h>
#include <stdlib.h>

/** @attention
 * define the expected max positive range of column and row.
 * if the data is not in this range, just change here to expand them.
*/
#define INT u_int8_t
#define DIE "No Way"

typedef struct Position {
    INT row;
    INT col;
} position;

typedef struct HistoryStack {
    INT maxsize;
    int8_t top;
    position *items;
} h_stack;

h_stack *new_stack(INT capacity) {
    // init a h_stack memory.
    h_stack *new_stack_pt = (h_stack *) malloc(sizeof(h_stack));

    // init the new h_stack's properties.
    new_stack_pt->maxsize = capacity;
    new_stack_pt->top = -1;
    new_stack_pt->items = (position *) calloc(capacity, sizeof(position));

    return new_stack_pt;
}

u_int8_t is_empty(h_stack *s) {
    return s->top < 0;
}

u_int8_t is_full(h_stack *s) {
    return s->top >= s->maxsize;
}

void push(h_stack *s, position pos) {
    if (is_full(s)) exit(EXIT_FAILURE);
    s->items[++s->top] = pos;
}

position pop(h_stack *s) {
    if (is_empty(s)) exit(EXIT_FAILURE);
    return s->items[s->top--];
}

int main(void) {
    // get row_size and col_size.
    int row_size = 0, col_size = 0;
    scanf("%d%*[ ]%d", &row_size, &col_size);

    // get maze.
    INT **maze = (INT **) calloc(row_size, sizeof(INT *));
    int i = 0;
    for (; i < row_size; i++) {
        maze[i] = (INT *) calloc(col_size, sizeof(INT));
        scanf("%s", maze[i]);
    }

    // init history h_stack, ans route and pos position.
    h_stack *history = new_stack(row_size * col_size);
    position pos;

    // set position to bottom left.
    pos.row = row_size - 1;
    pos.col = 0;

    // create a complete flag.
    u_int8_t no_way = 0;

    do {
        // mark previous point as passed point to ans map.
        maze[pos.row][pos.col] = '2';

        // check N
        if (pos.row - 1 >= 0 && maze[pos.row - 1][pos.col] == '0') {
            push(history, pos);
            maze[pos.row--][pos.col] = '2';
            continue;
        }

        // check E
        if (pos.col + 1 < col_size && maze[pos.row][pos.col + 1] == '0') {
            push(history, pos);
            maze[pos.row][pos.col++] = '2';
            continue;
        }

        // check S
        if (pos.row + 1 < row_size && maze[pos.row + 1][pos.col] == '0') {
            push(history, pos);
            maze[pos.row++][pos.col] = '2';
            continue;
        }

        // check W
        if (pos.col - 1 >= 0 && maze[pos.row][pos.col - 1] == '0') {
            push(history, pos);
            maze[pos.row][pos.col--] = '2';
            continue;
        }

        // if history is not empty here, it means the path was a dead end.
        if (!is_empty(history)) {
            maze[pos.row][pos.col] = '1';
            pos = pop(history);
            continue;
        }

        // mark as no-way.
        no_way = 1;
        break;
    } while (pos.row != 0 || pos.col != col_size - 1);

    // print answer.
    if (!no_way) {
        // mark final point to a passed point.
        maze[0][col_size - 1] = '2';

        // mark all obstacles('1') to zero('0').
        int j;
        for (i = 0; i < row_size; i++) {
            for (j = 0; j < col_size; j++) {
                if (maze[i][j] == '1') {
                    maze[i][j] = '0';
                }
            }
        }

        // print final map.
        for (i = 0; i < row_size; i++) {
            printf("%s\n", maze[i]);
        }
        
    } else {
        printf(DIE);
    }

    // reduce maze.
    for (i = 0; i < row_size; i++) {
        free(maze[i]);
    }
    free(maze);

    return 0;
}

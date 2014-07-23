#include <ncurses.h>

#include "fileOperations.h"
#include "fileStructs.h"
#include "outputOperations.h"

void
writeBufferedFileToWindow(WINDOW *window, BufferedFile *bf) {
    int row, col, y, x, ch;
    char *bufferIndex = bf->buffer;
    ch = *bufferIndex;
    getmaxyx(stdscr, row, col);

    while (ch != '\0') {
        getyx(stdscr, y, x);
        if (y == row - 1) {
            printw("<-Press Any Key->");
            refresh();
            getch();
            clear();
            move(0, 0);
        } else {
            printw("%c", ch);
        }
        ch = *(++bufferIndex);
    }
    getch();
}

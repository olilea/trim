#include <ncurses.h>

#include "fileOperations.h"
#include "file.h"
#include "outputOperations.h"

void
writeBufferedFileToWindow(TWINDOW *twin, BufferedFile *bf) {
    WINDOW *window = twin->window;
    int winRows = twin->rows;
    int y, x, ch;
    char *bufferIndex = bf->buffer;
    ch = *bufferIndex;
    wmove(window, 0, 0);

    while (ch != '\0') {
        getyx(window, y, x);
        if (y != winRows - 1) {
            wprintw(window, "%c", ch);
        } else {
            break;
        }
        ch = *(++bufferIndex);
    }
}

void
showBufferedFile(TWINDOW *twin, BufferedFile *bf) {
    WINDOW *window = twin->window;
    int winRows = twin->rows;
    int y, x, ch;
    char *bufferIndex = bf->buffer;
    ch = *bufferIndex;
    unsigned int lines = 0;
    wmove(window, 0, 0);

    while (ch != '\0') {
        if (ch == 'LF') {
            lines++;
        }
        getyx(window, y, x);
        if (y != winRows - 1) {
            wprintw(window, "%c", ch);
        }
        ch = *(++bufferIndex);
    }
    wmove(window, 0, 0);
    wrefresh(window);
    addLineCount(lines);
}

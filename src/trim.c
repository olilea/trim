#include <stdlib.h>
#include <string.h>
#include <ncurses.h>
#include <signal.h>

#include "global.h"
#include "tests.h"
#include "outputOperations.h"
#include "fileStructs.h"
#include "fileOperations.h"
#include "trim.h"

#include "curses/window.h"

// As defined in global.h with extern visibility
volatile int rows;
volatile int cols;

WINDOW *trimWindow;
WINDOW *commandlineWindow;

void
deinitCurses(void) {
    endwin();                       /* End curses mode                      */
}

void
initMainWindows(void) {

    trimWindow = createNewWin(rows, cols, 0, 0);
    commandlineWindow = createNewWin(COMMANDLINE_HEIGHT, cols, rows - COMMANDLINE_HEIGHT, 0);
}

void
initCurses(void) {

    initscr();                      /* Starts curses mode                   */
    raw();                          /* Line buffering disabled and control
                                     * signals disabled                     */
    keypad(stdscr, TRUE);           /* We get F1, F2 etc...                 */
    noecho();                       /* Don't echo() while we do getch       */

    getmaxyx(stdscr, rows, cols);

    initMainWindows();
}

void
sigHandler(int sig) {
    if (sig == SIGWINCH) {
        deinitCurses();
        initCurses();
        refresh();
    } else {
        exit(sig);
    }
}

void
init(void) {
    //signal(SIGWINCH, sigHandler);

    initCurses();
}

void
processCommand(char *inputString) {
    mvwprintw(trimWindow, 0, 0, inputString);
    wrefresh(trimWindow);
}

int
main(int argc, char *argv[]) {

    init();

    //test();
    //test2();
    //test3();
    //test4();
    //test5();
    //BufferedFile *bf = openFileToBuffer("hello.c", "r");
    //writeBufferedFileToWindow(stdscr, bf);

    char input[cols];
    echo();
    while (1) {
        if (mvwgetnstr(commandlineWindow, 0, 0, input, cols - 1) == ERR) {
            continue;
        }
        processCommand(input);
    }

    deinitCurses();

    return 0;   
}

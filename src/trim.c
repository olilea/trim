#include <stdlib.h>
#include <string.h>
#include <ncurses.h>
#include <signal.h>

#include "global.h"
#include "tests.h"
#include "outputOperations.h"
#include "file.h"
#include "fileOperations.h"
#include "trim.h"

#include "curses/window.h"

// As defined in global.h with extern visibility
volatile int rows;
volatile int cols;

TWINDOW *trimWindow;
TWINDOW *commandlineWindow;
TWINDOW *sidebarWindow;

void
deinitCurses(void) {
    tdelwin(trimWindow);
    tdelwin(commandlineWindow);
    tdelwin(sidebarWindow);
    endwin();                       /* End curses mode                      */
}

void
initMainWindows(void) {

    trimWindow = tnewwin(rows - 1, cols - 1, 0, 1);
    commandlineWindow = tnewwin(COMMANDLINE_HEIGHT, cols, rows - COMMANDLINE_HEIGHT, 0);
    sidebarWindow = tnewwin(rows - 1, 1, 0, 0);
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
init(void) {
    initCurses();
}

void
processCommand(char *inputString) {
    wprintw(trimWindow->window, inputString);
    wrefresh(trimWindow->window);
}

int
main(int argc, char *argv[]) {

    init();

    //test();
    //test2();
    //test3();
    //test4();
    //test5();
    BufferedFile *bf = openFileToBuffer("hello.c", "r");
    writeBufferedFileToWindow(trimWindow, bf);


    char input[cols];
    echo();
    while (1) {
        if (mvwgetnstr(commandlineWindow->window, 0, 0, input, cols - 1) == ERR) {
            continue;
        }
        processCommand(input);
    }

    deinitCurses();

    return 0;   
}

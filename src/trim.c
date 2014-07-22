#include <stdlib.h>
#include <string.h>
#include <ncurses.h>

#include "trim.h"
#include "tests.h"

void
initCurses(void) {

    initscr();              /* Starts curses mode                   */
    raw();                  /* Line buffering disabled and control
                             * signals disabled                     */
    keypad(stdscr, TRUE);   /* We get F1, F2 etc...                 */
    noecho();               /* Don't echo() while we do getch       */
}

void
deinitCurses(void) {
    endwin();               /* End curses mode                      */
}

int
main(int argc, char *argv[]) {

    initCurses();

    //test();
    //test2();
    //test3();
    //test4();
    test5();

    deinitCurses();

    return 0;   
}

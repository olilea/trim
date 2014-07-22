#include <stdlib.h>
#include <string.h>
#include <ncurses.h>

#include "trim.h"
#include "tests.h"

int
initCurses(void) {

    initscr();              /* Starts curses mode                   */
    raw();                  /* Line buffering disabled and control
                             * signals disabled                     */
    keypad(stdscr, TRUE);   /* We get F1, F2 etc...                 */
    noecho();               /* Don't echo() while we do getch       */

    return 0;
}

int
deinitCurses(void) {
    endwin();               /* End curses mode                      */
    return 0;
}

int
main(int argc, char *argv[]) {

    if (initCurses() == -1) {
        return -1;
    }   

    //test();
    //test2();
    //test3();
    test4();

    deinitCurses();

    return 0;   
}

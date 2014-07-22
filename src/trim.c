#include <stdlib.h>
#include <string.h>
#include <ncurses.h>

#include "tests.h"
#include "outputOperations.h"
#include "fileStructs.h"
#include "fileOperations.h"
#include "trim.h"

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
    //test5();
    BufferedFile *bf = openFileToBuffer("hello.c", "r");
    writeBufferedFileToWindow(stdscr, bf);

    deinitCurses();

    return 0;   
}

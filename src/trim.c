#include <stdlib.h>
#include <string.h>
#include <ncurses.h>

#include "trim.h"

static void
test(void) {

    int ch;

    printw("Type any character to see it in bold\n\r");
    ch = getch();           /* If raw() hadn't been called we have
                             * to press enter before it gets to the
                             * program                              */
    if (ch == KEY_F(1)) {
        printw("F1 key pressed");
    } else {
        mvprintw(30, 2, "The key pressed is: ");
        attron(A_BOLD);
        printw("%c", ch);
        attroff(A_BOLD);
    }
    refresh();              /* Prints it on the real screen         */
    getch();                /* Wait for user input                  */
}

static void
test2(void) {
    char mesg[] = "Just a string";
    int row, col;

    getmaxyx(stdscr, row, col);     /* Gets the number of rows and
                                     * columns                      */
    mvprintw(row/2, (col - strlen(mesg)) / 2, "%s", mesg);

    mvprintw(row - 2, 0, "This screen has %d rows and %d columns\n\r",
            row, col);

    refresh();
    getch();
}

static void
test3(void) {
    char mesg[] = "Enter a string: ";
    char str[80];
    int row, col;

    getmaxyx(stdscr, row, col);
    mvprintw(row - 3, 0, "%s", mesg);
    echo();
    getstr(str);
    mvprintw(LINES - 4, 0, "You entered: %s", str);
    noecho();
    getch();
}

static void
test4(void) {

    int y, x, row, col;
    int prev = EOF;
    int ch;
    FILE *fp = openFile("hello.c", "r");
    
    getmaxyx(stdscr, row, col);

    while ((ch = fgetc(fp)) != EOF) {
        getyx(stdscr, y, x);
        if (y == (row - 1)) {
            printw("<-Press Any Key->");
            getch();
            clear();
            move(0, 0);
        }
        if (prev == '/' && ch == '*') {
            attron(A_BOLD);
            getyx(stdscr, y, x);
            move(y, x - 1);
            printw("%c%c", '/', ch);
        } else {
            printw("%c", ch);
        }
        refresh();
        if (prev == '*' && ch == '/') {
            attroff(A_BOLD);
        }
        prev = ch;
    }
    getch();
    fclose(fp);
}

FILE *
openFile(char *fileName, char *mode) {
    FILE *fp = fopen(fileName, mode);
    if (fp == NULL) {
        deinitCurses();
        perror("Cannot open file");
        exit(1);
    }
    return fp;
}

static int
initCurses(void) {

    initscr();              /* Starts curses mode                   */
    raw();                  /* Line buffering disabled and control
                             * signals disabled                     */
    keypad(stdscr, TRUE);   /* We get F1, F2 etc...                 */
    noecho();               /* Don't echo() while we do getch       */

    return 0;
}

static int
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

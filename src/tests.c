#include <ncurses.h>
#include <stdio.h>
#include <string.h>

#include "tests.h"
#include "file_operations.h"

void
test1(void) {

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

void
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

void
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

void
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

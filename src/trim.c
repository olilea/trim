#include <ncurses.h>

int initCurses(void) {

	initscr();				/* Starts curses mode					*/
	raw();					/* Line buffering disabled and control
							 * signals disabled						*/
	keypad(stdscr, TRUE);	/* We get F1, F2 etc...					*/
	noecho();				/* Don't echo() while we do getch		*/

	return 0;
}

int main(int argc, char *argv[]) {

	int ch;

	if (initCurses() == -1) {
		return -1;
	}	
	printw("Type any character to see it in bold\n\r");
	ch = getch();			/* If raw() hadn't been called we have
							 * to press enter before it gets to the
							 * program								*/
	if (ch == KEY_F(1)) {
		printw("F1 key pressed");
	} else {
		mvprintw(30, 2, "The key pressed is: ");
		attron(A_BOLD);
		printw("%c", ch);
		attroff(A_BOLD);
	}
	refresh();				/* Prints it on the real screen			*/
	getch();				/* Wait for user input					*/
	endwin();				/* End curses mode						*/

	return 0;	
}

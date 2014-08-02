#include <ncurses.h>

#include "window.h"

WINDOW *
createNewWin(int height, int width, int starty, int startx) {

	WINDOW *win;
	win = newwin(height, width, starty, startx);
	box(win, 0, 0);
	wrefresh(win);

	return win;
}

void
destroyWin(WINDOW *window) {
	delwin(window);
}

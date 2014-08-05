#include <ncurses.h>
#include <stdlib.h>

#include "global.h"
#include "tcurses.h"

int
tmvwaddch(TWINDOW *twin, int y, int x, char ch) {
	return mvwaddch(twin->window, y, x, ch);
}

int
tmvwprintw(TWINDOW *twin, int y, int x, char *string) {
	return mvwprintw(twin->window, y, x, string);

}

int twresize(TWINDOW *twin, int rows, int cols) {
	return wresize(twin->window, rows, cols);
}

int twrefresh(TWINDOW *twin) {
	return wrefresh(twin->window);
}

// @TODO
// Refreshes the sidebar with the linecount
int addLineCount(unsigned int lines) {
	// Inittializes all elements to zero
	TWINDOW *twin = sidebarWindow;

	char *longString = { 0 };
	unsigned int i;
	for (i = 0; i < lines; ++i) {
		if (i >= twin->rows) {
			break;
		}
		sprintf(longString, "%u", i);
		if (sizeof(longString) > twin->cols) {
			twresize(twin, twin->rows, twin->cols);
		}
		tmvwprintw(twin, i, 0, longString);
	}

	return twrefresh(twin);
}

TWINDOW *
tnewwin(int height, int width, int starty, int startx) {

	TWINDOW *twin = (TWINDOW *)malloc(sizeof(TWINDOW));
	if ((twin->window = newwin(height, width, starty, startx)) == NULL) {
		free(twin);
		return NULL;
	}
	twin->buffer = (char *)malloc(sizeof(char) * TWIN_BUFFER_SIZE);
	twin->rows = height;
	twin->cols = width;

	#ifdef DEBUG
	box(twin->window, 0, 0);
	#endif
	wrefresh(twin->window);

	return twin;
}

int
tdelwin(TWINDOW *twin) {
	if (delwin(twin->window) == ERR) {
		return ERR;
	}
	free(twin->buffer);
	free(twin);
	return OK;
}

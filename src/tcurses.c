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

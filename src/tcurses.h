#ifndef TCURSES_H
#define TCURSES_H

typedef struct {
	WINDOW *window;
	char *buffer;
	int rows;
	int cols;
} TWINDOW;

int tmvwaddch(TWINDOW *twin, int y, int x, char ch);

int tmvwprintw(TWINDOW *twin, int y, int x, char *string);

int twresize(TWINDOW *twin, int rows, int cols);

int twrefresh(TWINDOW *twin);

int addLineCount(unsigned int lines);

TWINDOW *tnewwin(int height, int width, int starty, int startx);

int tdelwin(TWINDOW *window);

#endif

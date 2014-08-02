#ifndef WINDOW_H
#define WINDOW_H

typedef struct {
	WINDOW *window;
	char *buffer;
	int rows;
	int cols;
} TWINDOW;

TWINDOW *tnewwin(int height, int width, int starty, int startx);

int tdelwin(TWINDOW *window);

#endif

#ifndef GLOBAL_H
#define GLOBAL_H

#include "tcurses.h"

#define DEBUG 1

#define COMMANDLINE_HEIGHT 1
#define TWIN_BUFFER_SIZE 1024

extern TWINDOW *trimWindow;
extern TWINDOW *commandlineWindow;
extern TWINDOW *sidebarWindow;

extern volatile int rows;
extern volatile int cols;

#endif

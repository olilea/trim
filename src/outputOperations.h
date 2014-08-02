#ifndef OUTPUTOPERATIONS_H
#define OUTPUTOPERATIONS_H

#include "curses/window.h"
#include "file.h"

void writeBufferedFileToWindow(TWINDOW *window, BufferedFile *bf);

#endif

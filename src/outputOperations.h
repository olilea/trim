#ifndef OUTPUTOPERATIONS_H
#define OUTPUTOPERATIONS_H

#include "tcurses.h"
#include "file.h"

void writeBufferedFileToWindow(TWINDOW *window, BufferedFile *bf);

void showBufferedFile(TWINDOW *twin, BufferedFile *bf);

#endif

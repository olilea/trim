#include <stdlib.h>
#include <stdio.h>

#include "file_operations.h"
#include "trim.h"

FILE *
openFile(char *fileName, char *mode) {
    FILE *fp = fopen(fileName, mode);
    if (fp == NULL) {
        deinitCurses();
        perror("Cannot open file");
        exit(1);
    }
    return fp;
}

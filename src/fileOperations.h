#ifndef FILEOPERATIONS_H
#define FILEOPERATIONS_H

#include "fileStructs.h"

FILE *openFile(char *fileName, char *mode);

void closeFile(FILE *fp);

long fileLength(FILE *fp);

void readFileToBuffer(FILE *fp, char *buffer, long length);

BufferedFile *openFileToBuffer(char *fileName, char *mode);

#endif

#include <stdlib.h>
#include <stdio.h>

#include "fileOperations.h"
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

void
closeFile(FILE *fp) {
	if (fclose(fp) == EOF) {
		deinitCurses();
        perror("Cannot close file");
        exit(1);
	}
}

long
fileLength(FILE *fp) {
    long length;
    long currentLocation = ftell(fp);

    fseek(fp, 0, SEEK_END);
    length = ftell(fp);
    fseek(fp, 0, currentLocation);
    return length;
}

void
readFileToBuffer(FILE *fp, char *buffer, long length) {
    fseek(fp, 0, SEEK_SET);
    fread(buffer, length, 1, fp);
}

BufferedFile *
openFileToBuffer(char *fileName, char *mode) {

    BufferedFile *bf = (BufferedFile *) malloc(sizeof(BufferedFile));
    FILE *fp = openFile(fileName, mode);
    long length = fileLength(fp);

    bf->fileName = fileName;
    bf->mode = mode;
    bf->fp = fp;
    bf->length = length;
    bf->buffer = (char *) malloc(length + 1);

    readFileToBuffer(fp, bf->buffer, length);

    return bf;

} 

#ifndef FILE_H
#define FILE_H

typedef struct {
	char *fileName;
	char *mode;
	FILE *fp;
	long length;
	char *buffer;
} BufferedFile;

#endif

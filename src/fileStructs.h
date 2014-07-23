#ifndef FILESTRUCTS_H
#define FILESTRUCTS_H

typedef struct {
	char *fileName;
	char *mode;
	FILE *fp;
	long length;
	char *buffer;
} BufferedFile;

#endif

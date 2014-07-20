CC=gcc
CXX=g++
RM=rm -f

FLAGS=	-Wall\
		-pedantic\
		-O3\
		-lncurses

EXECUTABLE=bin/trim

SRCS=	src/trim.c

all:	main
		@echo "Build complete"

main:	$(SRCS)
		mkdir -p bin/
		$(CC) -o $(EXECUTABLE) $(SRCS) $(FLAGS)

clean:	$(RM) $(EXECUTABLE)

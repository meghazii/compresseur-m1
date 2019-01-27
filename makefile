IDIR=-I./include

CC=gcc
CFLAGS=-I$(IDIR) -Wall -Wextra -Werror -ansi -std=c11 -pedantic -g

LIBS=-lm

SRCS = ./src/converter.c ./src/fileReader.c ./src/algoCompress.c

OBJS = $(SRCS:.c=.o)

MAIN = compress

.PHONY:	depend clean

all:	$(MAIN)
	@echo "Compilation Successful"

$(MAIN):	$(OBJS)
	$(CC) $(CFLAGS) $(IDIR) -o $(MAIN) $(OBJS) $(LFLAGS) $(LIBS)

.c.o:
	$(CC) $(CFLAGS) $(IDIR) -c $<  -o $@

clean:
	$(RM) *.o *~ $(MAIN)

depend:	$(SRCS)
	makedepend $(IDIR) $^

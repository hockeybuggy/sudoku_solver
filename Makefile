#AUTHOR : Douglas Anderson
# Based on Professor Judi McCuaig's Makefile

CC          =gcc

CFLAGS      =-Wall -std=c99 -pedantic -g

#Directories where the compiler can find things
INCLUDES    =
LIBDIRS     =
LIBS        =

# add directory names here if you want to separate files by directories
BINDIR =bin/
SRCDIR =src/
TESTDIR =test/

#Put the names of your source code file in the lines below.
SOURCE = $(SRCDIR)cell.c $(SRCDIR)group.c $(SRCDIR)puzzle.c $(SRCDIR)solver.c

#The list of object files is below. Make changes as appropriate
OBJS = cell.o group.o puzzle.o
#The names of the binary programs that will be produced.
EXENAME = $(BINDIR)solver
TESTS = $(TESTDIR)unittests.c $(TESTDIR)check_cell.c $(TESTDIR)check_group.c $(TESTDIR)check_puzzle.c
TESTEXE = testexe

#### Targets
default : all

all : solver

debug: $(SRCDIR)cell.h $(SRCDIR)group.h $(SRCDIR)puzzle.h $(SRCDIR)solver.h
	$(CC) $(CFLAGS) $(INCLUDES) -DDEBUG=1 -c $(SOURCE)
	$(CC) $(CFLAGS) $(LIBS) -o $(EXENAME) $(OBJS) solver.o

solver: $(SRCDIR)cell.h $(SRCDIR)group.h $(SRCDIR)puzzle.h $(SRCDIR)solver.h
	$(CC) $(CFLAGS) $(INCLUDES) -c $(SOURCE)
	$(CC) $(CFLAGS) $(LIBS) -o $(EXENAME) $(OBJS) solver.o

test: solver
	$(CC) $(TESTS) $(OBJS) -o $(TESTEXE) `pkg-config --cflags --libs check`
	./$(TESTEXE)
	rm $(TESTEXE)

#### Util targets
.PHONY: doc clean test

doc:
	markdown README.md > README.html

clean:
	@ rm *.o
	@ rm bin/*
	@ rm README.html


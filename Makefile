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

#Put the names of your source code file in the lines below.  
SOURCE = $(SRCDIR)solver.c

#The list of object files is below. Make changes as appropriate
OBJS = solver.o 
#The names of the binary programs that will be produced.  
EXENAME = $(BINDIR)solver

#### Targets
default : all

all : solver 

debug: $(SRCDIR)solver.c $(SRCDIR)solver.h
	$(CC) $(CFLAGS) $(INCLUDES) -DDEBUG=1 -c $(SOURCE)
	$(CC) $(CFLAGS) $(LIBS) -o $(EXENAME) $(OBJS) 

solver: $(SRCDIR)solver.c $(SRCDIR)solver.h
	$(CC) $(CFLAGS) $(INCLUDES) -c $(SOURCE) 
	$(CC) $(CFLAGS) $(LIBS) -o $(EXENAME) $(OBJS)

#### Util targets
doc:
	markdown README.md > README.html

clean:
	@ rm *.o
	@ rm bin/*
	@ rm README.html


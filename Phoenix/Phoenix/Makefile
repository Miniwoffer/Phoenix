#vars
CC=g++
DEBUGFLAGS= -o ../debug
BUILDFLAGS= -o ../build
CFLAGS=-c -shared:
#vars end

#cimpiles all the files
all: debug build

build:
	$(CC) $(CFLAGS)  $(BUILDFLAGS)

debug:
	$(CC) $(CFLAGS) $(DEBUGFLAGS) 

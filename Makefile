CC = gcc
CFLAGS = -Wall 

all: run

run: main
	.\obj\main.exe

main :
	$(CC) $(CFLAGS) -o obj\main src/main.c src/arraylist.c

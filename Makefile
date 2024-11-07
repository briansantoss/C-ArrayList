CC = gcc
CFLAGS = -Wall -Werror

all: run

run: main
	.\obj\main.exe

main :
	$(CC) $(CFLAGS) -o obj\main src/main.c

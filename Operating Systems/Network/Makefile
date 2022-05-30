CC=gcc
CFLAGS= -std=gnu99 -Wall -fsanitize=address,undefined -g
LDLIBS= 

all: main
main: main.c	
	$(CC) $(CFLAGS) $(LDLIBS) -o main main.c
.PHONY: clean all
clean:
	rm main

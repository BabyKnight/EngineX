#declear the variable
CC=gcc

# this target will compile all the files
all: server

server: server.c
	$(CC) server.c -o server

clean:
	rm -rf *o server

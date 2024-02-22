CC = gcc
CFLAGS = -Wall

all: main

main: main.o my_app.o my_cli.o
	$(CC) $(CFLAGS) -o output main.o my_app.o my_cli.o

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

my_app.o: my_app.c
	$(CC) $(CFLAGS) -c my_app.c

my_cli.o: my_cli.c
	$(CC) $(CFLAGS) -c my_cli.c

clean:
	del *.o main

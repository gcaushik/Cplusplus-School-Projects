CC = g++
CFLAGS = -g -Wall

list: main.o list.o
	$(CC) $(CFLAGS) -o list main.o list.o

# Make already knows that you can generate .o file from its corresponding .cpp file.
# So only need to list the .h dependencies.

main.o: list.h
	$(CC) $(CFLAGS) -c main.cpp

list.o: list.h
	$(CC) $(CFLAGS) -c list.cpp

clean:
	rm list *.o *~

CC = g++
CFLAGS = -g -Wall

table1: main.o table.o
	$(CC) $(CFLAGS) -o table1 main.o table.o

# Make already knows that you can generate .o file from its corresponding .cpp file.
# So only need to list the .h dependencies.

main.o: table.h
	$(CC) $(CFLAGS) -c main.cpp

table.o: table.h
	$(CC) $(CFLAGS) -c table.cpp

clean:
	rm list *.o *~

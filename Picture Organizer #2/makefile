CC = g++
CFLAGS = -g -Wall

table2: main.o tree.o
	$(CC) $(CFLAGS) -o table1 main.o tree.o

# Make already knows that you can generate .o file from its corresponding .cpp file.
# So only need to list the .h dependencies.

main.o: tree.h
	$(CC) $(CFLAGS) -c main.cpp

tree.o: tree.h
	$(CC) $(CFLAGS) -c tree.cpp

clean:
	rm table2 *.o *~

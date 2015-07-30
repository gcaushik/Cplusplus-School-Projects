CC = g++
CFLAGS = -g -Wall

table3: main.o graph.o
	$(CC) $(CFLAGS) -o table3 main.o graph.o

# Make already knows that you can generate .o file from its corresponding .cpp file.
# So only need to list the .h dependencies.

main.o: graph.h
	$(CC) $(CFLAGS) -c main.cpp

graph.o: graph.h
	$(CC) $(CFLAGS) -c graph.cpp

clean:
	rm table3 *.o *~

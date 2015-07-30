CC = g++
CFLAGS = -g -Wall

patient: main.o queue.o stack.o
	$(CC) $(CFLAGS) -o patient main.o stack.o queue.o

# Make already knows that you can generate .o file from its corresponding .cpp file.
# So only need to list the .h dependencies.

main.o: queue.h stack.h
	$(CC) $(CFLAGS) -c main.cpp

queue.o: queue.h
	$(CC) $(CFLAGS) -c queue.cpp

stack.o: stack.h
	$(CC) $(CFLAGS) -c stack.cpp

clean:
	rm patient *.o *~

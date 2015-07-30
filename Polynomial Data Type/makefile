CC = g++
CFLAGS = -g -Wall

polynomial: main.o polynomial.o
	$(CC) $(CFLAGS) -o polynomial main.o polynomial.o

# Make already knows that you can generate .o file from its corresponding .cpp file.
# So only need to list the .h dependencies.

main.o: main.h
	$(CC) $(CFLAGS) -c main.cpp

polynomial.o: polynomial.h
	$(CC) $(CFLAGS) -c polynomial.cpp

clean:
	rm polynomial *.o *~

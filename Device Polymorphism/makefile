CC = g++
CFLAGS = -g -Wall

device: main.o device.o calc.o gps.o cellphone.o list.o
	$(CC) $(CFLAGS) -o device main.o device.o calc.o gps.o cellphone.o list.o

# Make already knows that you can generate .o file from its corresponding .cpp file.
# So only need to list the .h dependencies.

main.o: device.h calc.h gps.h cellphone.h
	$(CC) $(CFLAGS) -c main.cpp

device.o: device.h
	$(CC) $(CFLAGS) -c device.cpp

calc.o: device.h calc.h
	$(CC) $(CFLAGS) -c calc.cpp

gps.o: device.h gps.h
	$(CC) $(CFLAGS) -c gps.cpp

cellphone.o: device.h cellphone.h
	$(CC) $(CFLAGS) -c cellphone.cpp

list.o: list.h
	$(CC) $(CFLAGS) -c list.cpp

clean:
	rm device *.o *~

CC=gcc
CFLAGS=-Wall

# Link the object files into the program
main: main.o math_utils.o
	$(CC) main.o math_utils.o -o main

# Compile each source file into an object file
main.o: main.c math_utils.h
	$(CC) $(CFLAGS) -c main.c

math_utils.o: math_utils.c math_utils.h
	$(CC) $(CFLAGS) -c math_utils.c

run: main
	./main

clean:
	rm -f *.o main

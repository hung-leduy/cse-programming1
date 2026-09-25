CC=gcc
CFLAGS=-Wall

# Liên kết (link) các file object thành chương trình
main: main.o math_utils.o
	$(CC) main.o math_utils.o -o main

# Biên dịch (compile) từng file nguồn thành file object
main.o: main.c math_utils.h
	$(CC) $(CFLAGS) -c main.c

math_utils.o: math_utils.c math_utils.h
	$(CC) $(CFLAGS) -c math_utils.c

run: main
	./main

clean:
	rm -f *.o main

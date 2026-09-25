CC=gcc
CFLAGS=-Wall

all: libshapes.so main

# -shared -fPIC: build a shared (dynamically linked) library (.so)
libshapes.so: shapes.c
	$(CC) $(CFLAGS) -shared -fPIC shapes.c -o libshapes.so

# -ldl: link against the dlopen/dlsym library (needed on older glibc)
main: main.c
	$(CC) $(CFLAGS) main.c -o main -ldl

run: all
	./main

clean:
	rm -f main libshapes.so

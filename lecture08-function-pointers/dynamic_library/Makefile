CC=gcc
CFLAGS=-Wall

all: libshapes.so main

# -shared -fPIC: tạo thư viện liên kết động (.so)
libshapes.so: shapes.c
	$(CC) $(CFLAGS) -shared -fPIC shapes.c -o libshapes.so

# -ldl: liên kết với thư viện dlopen/dlsym (cần trên glibc cũ)
main: main.c
	$(CC) $(CFLAGS) main.c -o main -ldl

run: all
	./main

clean:
	rm -f main libshapes.so

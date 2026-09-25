CC=cc
CFLAGS=-Wall

all: hello_world hello_student

# Bước 1: biên dịch (compile) từng file .c thành file object .o
%.o: %.c hello.h
	$(CC) $(CFLAGS) -c $< -o $@

# Bước 2: liên kết (link) các file .o thành file thực thi
hello_world: hello_world.o hello.o
	$(CC) $^ -o $@

hello_student: hello_student.o hello.o
	$(CC) $^ -o $@

run: all
	./hello_world
	./hello_student

clean:
	rm -f *.o hello_world hello_student

CC=cc
CFLAGS=-Wall

all: hello_world hello_student

# Step 1: compile each .c file into an object file .o
%.o: %.c hello.h
	$(CC) $(CFLAGS) -c $< -o $@

# Step 2: link the .o files into an executable
hello_world: hello_world.o hello.o
	$(CC) $^ -o $@

hello_student: hello_student.o hello.o
	$(CC) $^ -o $@

run: all
	./hello_world
	./hello_student

clean:
	rm -f *.o hello_world hello_student

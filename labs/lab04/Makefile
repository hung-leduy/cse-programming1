# Lab 4 - Multi-file program
#   make test       compile and run the tests
#   make debug      recompile with -DDEBUG and run the tests
#   make valgrind   check memory
#   make app        (homework) menu-driven student management program
#   make clean      delete compiled files

CC = gcc
CFLAGS = -Wall -Wextra -g

.PHONY: test debug valgrind clean

test: test_student
	./test_student

# Linking: combine the object files into an executable
test_student: test_student.o student.o
	$(CC) $(CFLAGS) $^ -o $@

app: app.o student.o
	$(CC) $(CFLAGS) $^ -o $@

# Compiling: each .c file into a .o file; recompile when student.h changes
%.o: %.c student.h
	$(CC) $(CFLAGS) -c $< -o $@

debug: clean
	$(MAKE) CFLAGS="$(CFLAGS) -DDEBUG" test

valgrind: test_student
	valgrind --leak-check=full ./test_student

clean:
	rm -f *.o test_student app

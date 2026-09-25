# Lab 4 — Chương trình nhiều file
#   make test       biên dịch và chạy kiểm tra
#   make debug      biên dịch lại với -DDEBUG và chạy kiểm tra
#   make valgrind   kiểm tra bộ nhớ
#   make app        (bài tập về nhà) chương trình quản lý sinh viên có menu
#   make clean      xoá file đã biên dịch

CC = gcc
CFLAGS = -Wall -Wextra -g

.PHONY: test debug valgrind clean

test: test_student
	./test_student

# Liên kết: ghép các file object thành file thực thi
test_student: test_student.o student.o
	$(CC) $(CFLAGS) $^ -o $@

app: app.o student.o
	$(CC) $(CFLAGS) $^ -o $@

# Biên dịch: mỗi file .c thành một file .o; biên dịch lại khi student.h thay đổi
%.o: %.c student.h
	$(CC) $(CFLAGS) -c $< -o $@

debug: clean
	$(MAKE) CFLAGS="$(CFLAGS) -DDEBUG" test

valgrind: test_student
	valgrind --leak-check=full ./test_student

clean:
	rm -f *.o test_student app

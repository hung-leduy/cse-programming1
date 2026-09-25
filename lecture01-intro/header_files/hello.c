#include <stdio.h>
#include "hello.h" // include file header tự định nghĩa

// Định nghĩa (definition) của hàm print_hello
int print_hello(const char *name) {
    printf("hello, %s\n", name);
    return 0;
}

#include <stdio.h>
#include "hello.h" // include our own header file

// Definition of print_hello
int print_hello(const char *name) {
    printf("hello, %s\n", name);
    return 0;
}

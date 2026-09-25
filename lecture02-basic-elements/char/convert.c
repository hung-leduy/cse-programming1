#include <stdio.h>

// Exercise 1: convert a digit character to an integer
int convert(char var) {
    return var - '0';
}

int main() {
    char variable = '5';
    int converted_value = convert(variable); // 5
    printf("'%c' -> %d\n", variable, converted_value);
    return 0;
}

// Lab 3, Part 5.3 — Command-line arguments
//   gcc -Wall -g hello_loop_args.c -o hello_loop_args
//   ./hello_loop_args An 3
//   ./hello_loop_args "Nguyen Van An" 2
//
// argc: number of arguments, including the program name argv[0]
// argv: array of strings (char *); argv[argc] is always NULL
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc < 2 || argc > 3) {
        fprintf(stderr, "Usage: %s <name> [number_of_times]\n", argv[0]);
        return 1;
    }

    const char *name = argv[1]; // no copy needed: argv[1] already points to the string
    int times = 1;
    if (argc == 3)
        times = atoi(argv[2]); // "3" (a string) -> 3 (an int)

    for (int i = 0; i < times; i++)
        printf("Hello %s !\n", name);

    return 0;
}

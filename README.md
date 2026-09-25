# Programming 1 — C Programming Examples

This repository collects short C programs that accompany the lectures of the **Programming 1** course. Its organization is based on [bonigarcia/c-programming](https://github.com/bonigarcia/c-programming): each lecture is a folder, divided into topics, and each `.c` file is a standalone, commented program.

## Compiling and running

Requirements: `gcc` and `make` (Linux, WSL, macOS, or GitHub Codespaces).

```bash
make          # compile all examples
make clean    # remove compiled files

# or compile a single file
gcc -Wall -g lecture01-intro/hello_world/hello.c -o hello
./hello
```

Folders with their own `Makefile` contain multi-file programs (for example `lecture01-intro/header_files`); run `make run` inside that folder.

## Labs

The handouts for the 4 lab sessions (plus the Lab 0 preparation lab) are in [`labs/`](labs):

- [Lab 0 — Environment setup, Linux commands, SSH, Git/GitHub](labs/lab00-setup.md)
- [Lab 1 — C fundamentals](labs/lab01-basics.md)
- [Lab 2 — Arrays, strings, and debugging](labs/lab02-arrays-strings-debug.md)
- [Lab 3 — Pointers and dynamic memory](labs/lab03-pointers-memory.md)
- [Lab 4 — Structs, function pointers, and multi-file programs](labs/lab04-structs-modules.md)

The repo includes a `.devcontainer/` configuration for opening it in GitHub Codespaces (with `gcc`, `gdb`, `make`, and `valgrind` preinstalled).

## Contents

### [Lecture 1: Course introduction](lecture01-intro)

| Topic | Examples |
|---|---|
| The "hello, world" program | [hello.c](lecture01-intro/hello_world/hello.c) |
| Functions (definition, calling, reuse) | [print_hello.c](lecture01-intro/functions/print_hello.c) |
| Header files, multi-file compilation, compile/link | [header_files/](lecture01-intro/header_files) |
| Variables, while loops (temperature table) | [fahr_celsius.c](lecture01-intro/variables/fahr_celsius.c), [fahr_celsius_float.c](lecture01-intro/variables/fahr_celsius_float.c) |
| Arithmetic operators | [arithmetic.c](lecture01-intro/operators/arithmetic.c) |
| Increment/decrement operators `i++`, `++i` | [increment.c](lecture01-intro/operators/increment.c) |
| Comments | [comments.c](lecture01-intro/comments/comments.c) |
| Exercises: add, factorial, Fibonacci (recursive and iterative) | [add.c](lecture01-intro/exercises/add.c), [factorial.c](lecture01-intro/exercises/factorial.c), [fibonacci.c](lecture01-intro/exercises/fibonacci.c) |

### [Lecture 2: Basic elements](lecture02-basic-elements)

| Topic | Examples |
|---|---|
| Sizes of data types | [sizeof_types.c](lecture02-basic-elements/types/sizeof_types.c) |
| Declaring variables, constants, hexadecimal numbers | [declare_assign.c](lecture02-basic-elements/types/declare_assign.c) |
| Type casting, loss of precision | [casting.c](lecture02-basic-elements/types/casting.c), [cast_in_function.c](lecture02-basic-elements/types/cast_in_function.c) |
| Relational and logical operators | [relational_logical.c](lecture02-basic-elements/operators/relational_logical.c) |
| if / else if / else | [if_else.c](lecture02-basic-elements/control_flow/if_else.c) |
| for, while, do-while | [loops.c](lecture02-basic-elements/control_flow/loops.c) |
| The `char` type and the ASCII table | [char_ascii.c](lecture02-basic-elements/char/char_ascii.c) |
| Exercises 1, 2: converting characters to numbers, `atoi` | [convert.c](lecture02-basic-elements/char/convert.c), [my_atoi.c](lecture02-basic-elements/char/my_atoi.c) |

### [Lecture 3: Arrays and pointers](lecture03-array-pointer)

| Topic | Examples |
|---|---|
| switch, break, continue | [switch.c](lecture03-array-pointer/control_flow/switch.c), [break_continue.c](lecture03-array-pointer/control_flow/break_continue.c) |
| 1D arrays, finding the max | [array_1d.c](lecture03-array-pointer/arrays/array_1d.c) |
| 2D arrays, max along an axis | [array_2d.c](lecture03-array-pointer/arrays/array_2d.c) |
| Exercises: inner product, matrix multiplication, convolution | [inner_product.c](lecture03-array-pointer/arrays/inner_product.c), [matrix_multiplication.c](lecture03-array-pointer/arrays/matrix_multiplication.c), [convolution.c](lecture03-array-pointer/arrays/convolution.c) |
| Inserting and deleting array elements | [array_insert_delete.c](lecture03-array-pointer/arrays/array_insert_delete.c) |
| Declaring pointers, `&` and `*` | [pointer_basic.c](lecture03-array-pointer/pointers/pointer_basic.c) |
| Pointers to arrays, array names are constant | [pointer_to_array.c](lecture03-array-pointer/pointers/pointer_to_array.c) |
| Moving pointers, the `*(++p)` vs. `*(p++)` quiz | [pointer_arithmetic.c](lecture03-array-pointer/pointers/pointer_arithmetic.c) |
| Call by value and call by reference | [call_by_value_reference.c](lecture03-array-pointer/pointers/call_by_value_reference.c) |
| Array pointers with functions (max, reversing an array, returning an array) | [array_functions.c](lecture03-array-pointer/pointers/array_functions.c), [even_odd_bit.c](lecture03-array-pointer/pointers/even_odd_bit.c) |
| `malloc`, `free`, `realloc`, memory leaks | [malloc_free.c](lecture03-array-pointer/dynamic_mem/malloc_free.c), [realloc.c](lecture03-array-pointer/dynamic_mem/realloc.c), [memory_leak.c](lecture03-array-pointer/dynamic_mem/memory_leak.c) |
| Variable scope (global, local, heap) | [scope.c](lecture03-array-pointer/dynamic_mem/scope.c) |
| Structs, pointers to structs, `->` | [fraction.c](lecture03-array-pointer/structs/fraction.c), [struct_pointer.c](lecture03-array-pointer/structs/struct_pointer.c) |
| Linked lists (access, insert, delete, free) | [linked_list.c](lecture03-array-pointer/structs/linked_list.c) |
| Binary search trees | [binary_tree.c](lecture03-array-pointer/structs/binary_tree.c) |

### [Lecture 7: Review](lecture07-review)

| Topic | Examples |
|---|---|
| VS Code configuration: building, debugging with gdb | [vscode/](lecture07-review/vscode) |
| A program for practicing breakpoints | [sample.c](lecture07-review/multi_array/sample.c) |
| Allocating a 2D array with `int **` | [alloc_2d.c](lecture07-review/multi_array/alloc_2d.c) |
| Allocating an n-dimensional array recursively, returning `void *` | [alloc_nd.c](lecture07-review/multi_array/alloc_nd.c) |

Freeing linked lists and binary trees: see `free_list` in [linked_list.c](lecture03-array-pointer/structs/linked_list.c) and `free_tree` in [binary_tree.c](lecture03-array-pointer/structs/binary_tree.c).

### [Lecture 8: Function pointers](lecture08-function-pointers)

| Topic | Examples |
|---|---|
| Multi-dimensional array indexing (`struct MultiArray`, data + shape) | [multi_array.c](lecture08-function-pointers/multi_array/multi_array.c) |
| Strings: `char[]` vs. `char *`, the `'\0'` character | [string_basics.c](lecture08-function-pointers/strings/string_basics.c) |
| `strlen`, `strcmp`, `strcat`, `strcpy`, `strstr` | [string_functions.c](lecture08-function-pointers/strings/string_functions.c) |
| Implementing string functions yourself | [my_string.c](lecture08-function-pointers/strings/my_string.c) |
| Function pointers, arrays of function pointers | [function_pointer.c](lecture08-function-pointers/function_pointers/function_pointer.c) |
| Function pointers as parameters (`reduce`, `qsort`) | [reduce.c](lecture08-function-pointers/function_pointers/reduce.c), [qsort_compare.c](lecture08-function-pointers/function_pointers/qsort_compare.c) |
| `typedef` | [typedef.c](lecture08-function-pointers/function_pointers/typedef.c) |
| `#define`: constants and macros | [define.c](lecture08-function-pointers/preprocessor/define.c) |
| `#ifdef`: Debug / Release, per operating system | [debug_release.c](lecture08-function-pointers/preprocessor/debug_release.c), [platform.c](lecture08-function-pointers/preprocessor/platform.c) |
| Multiple files: prototypes and implementations, compile and link | [multiple_files/](lecture08-function-pointers/multiple_files) |
| Calling functions from a dynamic library (`dlopen`/`dlsym`) | [dynamic_library/](lecture08-function-pointers/dynamic_library) |

## Things to try

```bash
# Debug and Release builds with #ifdef
gcc -DDEBUG lecture08-function-pointers/preprocessor/debug_release.c -o debug && ./debug
gcc lecture08-function-pointers/preprocessor/debug_release.c -o release && ./release

# Check for memory leaks
cd lecture03-array-pointer/dynamic_mem
gcc -g memory_leak.c -o memory_leak && valgrind --leak-check=full ./memory_leak

# Debug with gdb
gcc -g lecture07-review/multi_array/sample.c -o sample && gdb ./sample
```

## Further reading

- Brian Kernighan, Dennis Ritchie — *The C Programming Language*
- Nick Parlante — [Essential C](https://cs.stanford.edu/people/nick/compdocs/Essential_C.pdf)
- [Harvard CS50x](https://cs50.harvard.edu/x/) and the [cs50.dev](https://cs50.dev/) environment
- [bonigarcia/c-programming](https://github.com/bonigarcia/c-programming)
- Practice: [LeetCode](https://leetcode.com/) (number and array topics)

# Programming 1 Labs

4 lab sessions of about 3 hours each, plus a preparation lab (Lab 0) that students complete on their own before session 1.
In each lab you read and run examples from [bonigarcia/c-programming](https://github.com/bonigarcia/c-programming), then work on exercises in a starter code file with **self-checking tests** (printing `PASS`/`FAIL`).

| Lab | Session | Content | Lecture | Folders in bonigarcia/c-programming | Starter code |
|---|---|---|---|---|---|
| [Lab 0 — Environment setup, Linux commands, SSH, Git/GitHub](lab00-setup.md) | Self-study before session 1 | WSL / Ubuntu / macOS setup, basic Linux commands, first C program, SSH & scp, Git/GitHub (optional) | 1, 7 | — | — |
| [Lab 1 — C fundamentals](lab01-basics.md) | 1 | The compilation process, `argc/argv`, data types, type casting, operators, branching, loops, functions, variable scope, top-down design | 1, 2 | `hello_world`, `types`, `variables`, `operators`, `boolean`, `control_flow`, `functions`, `top-down` | [`lab01/`](lab01) |
| [Lab 2 — Arrays, strings, debugging](lab02-arrays-strings-debug.md) | 2 | 1D/2D arrays, strings and `<string.h>`, `#ifdef DEBUG`, gdb, debugging in VS Code | 3, 7, 8 | `arrays`, `strings`, `debug` | [`lab02/`](lab02) |
| [Lab 3 — Pointers and dynamic memory](lab03-pointers-memory.md) | 3 | Pointers, pointers and arrays, pass by value/reference, `malloc/calloc/realloc/free`, dangling pointers, valgrind | 3, 7 | `pointers`, `dynamic_mem`, `valgrind` | [`lab03/`](lab03) |
| [Lab 4 — Structs, function pointers, multiple files](lab04-structs-modules.md) | 4 | `struct`, `typedef`, `enum`, linked lists, function pointers, `qsort`, headers, Makefile, `extern`, preprocessor | 3, 7, 8 | `structured_data`, `types`, `pointers`, `dynamic_mem`, `modules` | [`lab04/`](lab04) |

## Structure of each lab

1. **Objectives** and **Suggested timing**.
2. **Guided part:** a table of example files with "predict before you run" questions.
3. **In-class exercises:** implement the `TODO` functions in the starter code until everything shows `PASS`.
4. **Homework** (including some LeetCode problems) and **Submission** requirements.

## Student preparation

```bash
mkdir -p ~/prog1 && cd ~/prog1
git clone https://github.com/bonigarcia/c-programming.git
git clone <link to your fork of the course repo>      # or download the ZIP
```

## Running the starter code

```bash
cd labs/lab01 && gcc -Wall -Wextra lab01.c -o lab01 && ./lab01
cd labs/lab02 && gcc -Wall -Wextra -g lab02.c -o lab02 && ./lab02
cd labs/lab03 && gcc -Wall -Wextra -g lab03.c -o lab03 && ./lab03 && valgrind --leak-check=full ./lab03
cd labs/lab04 && make test && make valgrind
```

`main` returns 0 when everything is `PASS`, so it can be used for automated grading (for example `./lab01 && echo OK`).

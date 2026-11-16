# Lab 3 — Pointers, dynamic memory, and input/output

> **Session 3** · Related: Lecture 3 (Pointer, dynamic memory, scope, call by value/reference), Lecture 7 (multi array); Part 5 follows *The C Programming Language* (K&R), Chapter 7 (Input and Output)
> **Reference repo:** [bonigarcia/c-programming](https://github.com/bonigarcia/c-programming) — folders `pointers`, `dynamic_mem`, `valgrind`, `io`
> **Starter code:** [`lab03/lab03.c`](lab03/lab03.c), [`lab03/leaky.c`](lab03/leaky.c), [`lab03/lab03_io.c`](lab03/lab03_io.c), [`lab03/hello_loop_args.c`](lab03/hello_loop_args.c), data file [`lab03/18_em_1.txt`](lab03/18_em_1.txt)

## Objectives

- Understand that a pointer is a variable that holds an address; use `&`, `*`, `->`, and `NULL` confidently.
- The relationship between arrays and pointers; pointer arithmetic (`p + 1`, `*(p++)`, `*(++p)`).
- Pass by value vs. pass by reference; return multiple values through pointers.
- Allocate and free dynamic memory: `malloc`, `calloc`, `realloc`, `free`.
- Recognize and fix memory errors — leaks, dangling pointers, out-of-bounds writes, uninitialized variables — using **valgrind**.
- Format output and parse input with `printf`/`sprintf`/`snprintf` and `scanf`/`sscanf`, and check their return values.
- Pass command-line arguments to a program, and debug a program that needs arguments (gdb, VS Code `launch.json`).
- Read and write text files with `fopen`, `fgets`, `fprintf`, `fclose`, storing data of unknown size in a dynamic array.

## Suggested timing (≈ 3 hours)

| Time | Content |
|---|---|
| 0:00 – 0:30 | Part 1: pointer basics, pointers and arrays |
| 0:30 – 0:40 | Part 2: pass by value / by reference |
| 0:40 – 1:05 | Part 3: dynamic memory, scope, dangling pointers |
| 1:05 – 1:25 | Part 4: valgrind, fix `leaky.c` |
| 1:25 – 2:00 | Part 5: input/output — `sprintf`/`sscanf`, command-line arguments, debugging with arguments, text files |
| 2:00 – 2:50 | Part 6: exercises 3.1 – 3.9 (`lab03.c`), then 3.10 – 3.15 (`lab03_io.c`) |
| 2:50 – 3:00 | Review solutions |

> This lab is dense. Exercises you do not finish in class (usually 3.13 – 3.15) become part of the homework.

> **Draw pictures.** For each example, draw the "memory cells" (variable name, address, value) and the pointer arrows. Most pointer bugs become obvious once you draw them.

---

## Part 1. Pointer basics (≈ 30 minutes)

| File | Question |
|---|---|
| [`pointers/basic_pointer_1.c`](https://github.com/bonigarcia/c-programming/blob/master/pointers/basic_pointer_1.c) | Draw `age` and `p_age`. What does `%p` print? |
| [`pointers/basic_pointer_2.c`](https://github.com/bonigarcia/c-programming/blob/master/pointers/basic_pointer_2.c) | Why does `*p_age` change when you assign `age = 40`? Try the reverse: assign `*p_age = 60`, then print `age`. |
| [`pointers/null_pointer_1.c`](https://github.com/bonigarcia/c-programming/blob/master/pointers/null_pointer_1.c) | Add `printf("%d", *pointer);`. What happens? (Segmentation fault) |
| [`pointers/arrays_3.c`](https://github.com/bonigarcia/c-programming/blob/master/pointers/arrays_3.c) | Also print the addresses of `a`, `b`, `c`, `d`. How many bytes apart are they? Why? |
| [`pointers/arrays_4.c`](https://github.com/bonigarcia/c-programming/blob/master/pointers/arrays_4.c) | Why is `s1 != s2`? How are arrays and pointers different? |
| [`pointers/arrays_1.c`](https://github.com/bonigarcia/c-programming/blob/master/pointers/arrays_1.c) | Why can the `double_array` function modify `main`'s array? |
| [`pointers/double_pointer_1.c`](https://github.com/bonigarcia/c-programming/blob/master/pointers/double_pointer_1.c), [`double_pointer_2.c`](https://github.com/bonigarcia/c-programming/blob/master/pointers/double_pointer_2.c) | Draw `age`, `pointer`, `double_pointer`. What does the array `words` contain? |
| [`pointers/args.c`](https://github.com/bonigarcia/c-programming/blob/master/pointers/args.c) | `char *argv[]` is an array of pointers. Run `./args one two three`. |

### Lecture 3 quiz: `*(++p)` vs. `*(p++)`

Run [`lecture03-array-pointer/pointers/pointer_arithmetic.c`](../lecture03-array-pointer/pointers/pointer_arithmetic.c) from the course repo. Before running it, predict the contents of the array after each assignment. Explain why the program must end with `free(base)` and not `free(p_scores)`.

---

## Part 2. Pass by value and by reference (≈ 10 minutes)

| File | Question |
|---|---|
| [`pointers/pass_by_value.c`](https://github.com/bonigarcia/c-programming/blob/master/pointers/pass_by_value.c) | Why doesn't the value in `main` change? |
| [`pointers/pass_by_ref.c`](https://github.com/bonigarcia/c-programming/blob/master/pointers/pass_by_ref.c) | Draw the picture while execution is inside the function: where does the parameter point? |
| [`pointers/struct_pointer.c`](https://github.com/bonigarcia/c-programming/blob/master/pointers/struct_pointer.c) | What is `p->x` equivalent to when written with `*`? |

**LeetCode-style function pattern** (Lecture 3): a function that returns a new array **and** its size:

```c
int *evenOddBit(int n, int *returnSize);   // size is returned through *returnSize
```

See [`lecture03-array-pointer/pointers/even_odd_bit.c`](../lecture03-array-pointer/pointers/even_odd_bit.c). Who is responsible for calling `free` on the returned array?

---

## Part 3. Dynamic memory (≈ 25 minutes)

```
 high address ┌──────────────┐
              │    stack     │  local variables, parameters — destroyed when the function returns
              │      ↓       │
              │      ↑       │
              │     heap     │  malloc/calloc/realloc — lives until free
              ├──────────────┤
              │  data / bss  │  global variables, static variables
              ├──────────────┤
              │ rodata, text │  string literals "Hello", machine code
 low address  └──────────────┘
```

| File | Question |
|---|---|
| [`dynamic_mem/memory_segments.c`](https://github.com/bonigarcia/c-programming/blob/master/dynamic_mem/memory_segments.c) | Which segment does each variable live in? Why is `msg2[0] = 'h'` allowed but `msg1[0] = 'h'` is not? |
| [`dynamic_mem/malloc_1.c`](https://github.com/bonigarcia/c-programming/blob/master/dynamic_mem/malloc_1.c), [`malloc_2.c`](https://github.com/bonigarcia/c-programming/blob/master/dynamic_mem/malloc_2.c) | Fix the `FIXME`. Why must you check `ptr == NULL`? |
| [`dynamic_mem/malloc_3.c`](https://github.com/bonigarcia/c-programming/blob/master/dynamic_mem/malloc_3.c) | Are `*(ptr + i)` and `ptr[i]` the same? |
| [`dynamic_mem/calloc_1.c`](https://github.com/bonigarcia/c-programming/blob/master/dynamic_mem/calloc_1.c) | How is `calloc` different from `malloc`? |
| [`dynamic_mem/realloc_1.c`](https://github.com/bonigarcia/c-programming/blob/master/dynamic_mem/realloc_1.c) | Is the address the same before and after `realloc`? Why shouldn't you write `p = realloc(p, ...)` without checking the result? |
| [`dynamic_mem/double_pointer.c`](https://github.com/bonigarcia/c-programming/blob/master/dynamic_mem/double_pointer.c) | Why must you call `free(words[0])` **before** `free(words)`? |

### Allocating inside another function — a classic problem

Compare these 4 files: which ones are correct, which are wrong, and why?

1. [`out-of-scope-allocation_0.c`](https://github.com/bonigarcia/c-programming/blob/master/dynamic_mem/out-of-scope-allocation_0.c) — allocates directly in `main`
2. [`out-of-scope-allocation_1.c`](https://github.com/bonigarcia/c-programming/blob/master/dynamic_mem/out-of-scope-allocation_1.c) — `void allocate(int *ptr)`
3. [`out-of-scope-allocation_2.c`](https://github.com/bonigarcia/c-programming/blob/master/dynamic_mem/out-of-scope-allocation_2.c) — `void allocate(int **ptr)`
4. [`out-of-scope-allocation_3.c`](https://github.com/bonigarcia/c-programming/blob/master/dynamic_mem/out-of-scope-allocation_3.c) — `int *allocate()`

> Hint: file 2 makes exactly the same mistake as `swap_by_value` in Part 2 — except that the variable being "copied" is a pointer.

### Dangling pointers

| File | Question |
|---|---|
| [`dynamic_mem/dangling_pointer_1.c`](https://github.com/bonigarcia/c-programming/blob/master/dynamic_mem/dangling_pointer_1.c) | Using a pointer after `free`. How can you prevent this? |
| [`dynamic_mem/dangling_pointer_2.c`](https://github.com/bonigarcia/c-programming/blob/master/dynamic_mem/dangling_pointer_2.c) | Returning the address of a local variable. What does `-Wall` warn about? Fix it in 2 ways (`static` / `malloc`). |

---

## Part 4. Valgrind (≈ 20 minutes)

Valgrind runs your program in a monitored environment and reports every invalid memory access. Always compile with `-g` so that valgrind can show **line numbers**.

```bash
cd ~/prog1/c-programming/valgrind
gcc -g valgrind_memory_leak.c -o leak
valgrind --leak-check=full ./leak
```

| File | Bug | Valgrind message to look for |
|---|---|---|
| [`valgrind_memory_leak.c`](https://github.com/bonigarcia/c-programming/blob/master/valgrind/valgrind_memory_leak.c) | Memory leak | `definitely lost: 100 bytes in 1 blocks` |
| [`valgrind_illegal_write.c`](https://github.com/bonigarcia/c-programming/blob/master/valgrind/valgrind_illegal_write.c) | Writing to `NULL` | `Invalid write of size 4` |
| [`valgrind_illegal_free.c`](https://github.com/bonigarcia/c-programming/blob/master/valgrind/valgrind_illegal_free.c) | `free` at a wrong address / twice | `Invalid free()` |
| [`valgrind_unitialized.c`](https://github.com/bonigarcia/c-programming/blob/master/valgrind/valgrind_unitialized.c) | Reading an uninitialized variable | `Conditional jump or move depends on uninitialised value(s)` (add `--track-origins=yes`) |

**How to read the report:** find the first line in the stack trace that contains your file name (for example `at 0x...: main (leak.c:12)`). The final goal is always:

```
All heap blocks were freed -- no leaks are possible
ERROR SUMMARY: 0 errors from 0 contexts
```

> Valgrind does not run on Apple-silicon Macs — use the lab Linux server via SSH, or compile with `gcc -g -fsanitize=address leaky.c` (AddressSanitizer) instead.

### Exercise: `leaky.c`

The file [`lab03/leaky.c`](lab03/leaky.c) "seems to work" but has **4 memory bugs**. Use valgrind to find and fix all of them, and write notes about them at the top of the file.

```bash
cd ~/prog1/cse-programming1/labs/lab03
gcc -Wall -g leaky.c -o leaky
valgrind --leak-check=full --track-origins=yes ./leaky
```

---

## Part 5. Input/output with `<stdio.h>` (≈ 35 minutes)

> Reference: *The C Programming Language* (K&R), Chapter 7 — 7.1 standard input and output, 7.2 `printf`, 7.4 `scanf`, 7.5 file access, 7.6 `stderr` and `exit`, 7.7 line input and output.
> The date/time, command-line-argument and ink exercises in this part are adapted from the week-10 lab of [ntcuong2103/programming-1](https://github.com/ntcuong2103/programming-1/tree/main/lab_w10).

Every function in `<stdio.h>` works with a **stream** (`FILE *`). Three streams are already open when `main` starts: `stdin` (the keyboard), `stdout` (the screen) and `stderr` (the screen, for error messages). The same family of functions reads and writes the screen, files, and even strings:

| | Keyboard / screen | Any `FILE *f` | A string `char *s` |
|---|---|---|---|
| Formatted output | `printf(fmt, ...)` | `fprintf(f, fmt, ...)` | `sprintf(s, fmt, ...)`, `snprintf(s, size, fmt, ...)` |
| Formatted input | `scanf(fmt, ...)` | `fscanf(f, fmt, ...)` | `sscanf(s, fmt, ...)` |
| One whole line | `fgets(buf, size, stdin)` | `fgets(buf, size, f)` | — |

`printf(...)` is simply `fprintf(stdout, ...)`, and error messages go to `fprintf(stderr, ...)`.

### 5.1. Formatted output: `printf`, `sprintf`, `snprintf`

| Format | Value | Output |
|---|---|---|
| `[%d]`, `[%5d]`, `[%-5d]` | `9` | `[9]`, `[    9]`, `[9    ]` (width 5, right / left aligned) |
| `%02d`, `%04d` | `9` | `09`, `0009` (zero-padded: what you need for `hh:mm:ss`) |
| `%f`, `%.2f`, `[%8.3f]` | `3.14159` | `3.141590`, `3.14`, `[   3.142]` |
| `[%s]`, `[%5s]` | `"An"` | `[An]`, `[   An]` |
| `%c`, `%x`, `%p`, `%%` | | a character, hexadecimal, an address, a literal `%` |

| File | Question |
|---|---|
| [`io/sprintf.c`](https://github.com/bonigarcia/c-programming/blob/master/io/sprintf.c) | `sprintf` writes into a `char` array instead of the screen. Enter `20`, then `1234567890`. How many bytes does the string need the second time, and how big is `str`? Compile again with `gcc -g -fsanitize=address sprintf.c` and repeat. |
| [`io/snprintf.c`](https://github.com/bonigarcia/c-programming/blob/master/io/snprintf.c) | Same inputs. What is printed now? `snprintf` returns the length the complete string *would* have had (28): how can you use it to detect that the output was cut? |

**Predict, then run.** Compile this program with `gcc -Wall`, run it, then compile with `gcc -Wall -O2` and run it again. What does gcc warn about? Why can the output change? Fix the bug — and find the second problem that valgrind would report.

```c
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    char *out = malloc(1000);
    sprintf(out, "Current time is: %s", "09:05:30");
    sprintf(out, "%s, and today is: %s", out, "18/11/2026"); // out is both the destination and a source
    printf("%s\n", out);
    return 0;
}
```

> **Hint:** the destination of `sprintf` must not overlap any of its arguments (undefined behavior). Use a second buffer, `strcat`, or `snprintf(out + len, size - len, ...)`.

### 5.2. Formatted input: `scanf`, `sscanf`

- Pass **addresses**: `scanf("%d", &n)` — `scanf` writes into your variable (pass by reference, Part 2). An array name is already an address: `scanf("%9s", name)`, no `&`.
- Every character in the format that is not part of a `%...` must appear in the input: `"%d:%d:%d"` matches `9:5:30`.
- `scanf`/`sscanf` **return the number of values they read** (or `EOF` at the end of the input). Always check it.
- `%s` stops at the first space; give it a width (`%9s` for `char name[10]`) so it cannot overflow the array.

| File | Question |
|---|---|
| [`io/scanf_2.c`](https://github.com/bonigarcia/c-programming/blob/master/io/scanf_2.c) | Enter `An 20`, then `20 An`. What is `i` the second time? How could the program detect the problem from the return value of `scanf`? |
| [`io/scanf_3.c`](https://github.com/bonigarcia/c-programming/blob/master/io/scanf_3.c) | Press Ctrl+D instead of typing a number. What does `scanf` return? |
| [`io/sscanf.c`](https://github.com/bonigarcia/c-programming/blob/master/io/sscanf.c) | `sscanf` reads from a string instead of the keyboard. What does `%[^\n]` mean? |
| [`io/scanf_5_error.c`](https://github.com/bonigarcia/c-programming/blob/master/io/scanf_5_error.c) → [`scanf_5_sol1.c`](https://github.com/bonigarcia/c-programming/blob/master/io/scanf_5_sol1.c) | Why is "You entered" printed twice for every character in the first version? (Hint: `'\n'`.) How does reading the whole line with `fgets` fix it? |

**Mini-exercise — reading a time from the keyboard.** The program below reads a date written as `Weekday dd/mm/yyyy`. Save it as `lab03/time_input.c` and complete the `TODO`: read a time written as `hh:mm:ss` with `scanf` and print it back with leading zeros. Test it with a pipe instead of typing (Lab 0, Part 2.7).

```c
#include <stdio.h>

int main(void) {
    char weekday[10];
    int day, month, year;

    printf("Enter the date as \"Weekday dd/mm/yyyy\": ");
    if (scanf("%9s %d/%d/%d", weekday, &day, &month, &year) != 4) {
        fprintf(stderr, "Invalid date\n");
        return 1;
    }
    printf("You entered: %s, %02d/%02d/%04d\n", weekday, day, month, year);

    // TODO: read a time "hh:mm:ss" and print it as hh:mm:ss (for example 09:05:30)

    return 0;
}
```

```bash
echo "Wed 18/11/2026 9:5:30" | ./time_input     # expected time: 09:05:30
echo "Wed 18/11/2026 9-5-30" | ./time_input     # what does scanf return now?
```

Exercise 3.12 asks for the same thing with `sscanf`, reading from a string.

### 5.3. Command-line arguments and debugging with arguments

You have already met `int main(int argc, char *argv[])` in Lab 1 (`hello_args.c`) and in Part 1 (`args.c`). [`lab03/hello_loop_args.c`](lab03/hello_loop_args.c) takes a name and an optional number of repetitions:

```bash
cd ~/prog1/cse-programming1/labs/lab03
gcc -Wall -g hello_loop_args.c -o hello_loop_args
./hello_loop_args An 3
./hello_loop_args "Nguyen Van An" 2
./hello_loop_args An three
./hello_loop_args
```

For `./hello_loop_args An 3`:

```
argc    = 3
argv[0] = "./hello_loop_args"
argv[1] = "An"
argv[2] = "3"        <- a string; atoi converts it to the int 3
argv[3] = NULL
```

**Questions:** What is `argc` for `"Nguyen Van An"` written with quotes? Without quotes? What does `atoi("three")` return, and how would `strtol` let the program detect the mistake? Draw `argv` as an array of pointers, as in Part 1.

**Debugging a program that needs arguments.** Pressing F5 starts the program *without* arguments, so `hello_loop_args` only prints its usage message. Give the arguments to the debugger:

- **gdb:** `gdb --args ./hello_loop_args An 3`, or start `gdb ./hello_loop_args` and type `run An 3`.
- **VS Code:** in `.vscode/launch.json` (the configuration from [`lecture07-review/vscode/`](../lecture07-review/vscode), see Lab 2, Part 3.3), fill in `"args"` — each element of the list becomes one element of `argv`:

```json
"args": ["An", "3"],
"cwd": "${fileDirname}",
```

Set a breakpoint on the `for` loop, press F5, and look at `argc`, `argv[1]` and `argv[2]` in the **Variables** panel; add the **Watch** expression `*argv@argc`. Then try `"args": ["Nguyen Van An", "2"]` — no extra quotes are needed for the spaces.

> `"cwd"` is the **current working directory** of the program. A relative file name such as `"18_em_1.txt"` is looked up in the current working directory, **not** in the folder of the executable. With `"cwd": "${fileDirname}"`, it is the folder of the source file you are debugging.

### 5.4. Text files: `fopen`, `fgets`, `fprintf`, `fclose`

```c
FILE *f = fopen("data.txt", "r");    // "r" read, "w" write (creates or empties the file), "a" append
if (f == NULL) {                      // file not found, no permission, ...
    perror("data.txt");               // prints the reason, e.g. "data.txt: No such file or directory"
    return 1;
}
char line[256];
while (fgets(line, sizeof(line), f) != NULL) {   // one line at a time ('\n' is kept)
    int a, b;
    if (sscanf(line, "%d %d", &a, &b) == 2)       // then parse the line
        printf("%d\n", a + b);
}
fclose(f);                            // frees the FILE and writes out any buffered data
```

| File | Question |
|---|---|
| [`io/file_write.c`](https://github.com/bonigarcia/c-programming/blob/master/io/file_write.c) | Run it twice. Is the content of the first run kept? Change `"w"` to `"a"` and run it twice again. |
| [`io/file_read_1.c`](https://github.com/bonigarcia/c-programming/blob/master/io/file_read_1.c) | It reads the `file.txt` written above. Delete `file.txt` and run it again: which branch runs? Now remove `fclose(fd);`, recompile with `-g` and run `valgrind --leak-check=full`: what does the `HEAP SUMMARY` show? (A `FILE` lives on the heap too.) |
| [`io/fscanf.c`](https://github.com/bonigarcia/c-programming/blob/master/io/fscanf.c) + [`io/data.txt`](https://github.com/bonigarcia/c-programming/blob/master/io/data.txt) | Add the line `Dang Van Binh is 20 years old` to `data.txt`. Explain the strange output. Why is "read a line with `fgets`, then parse it with `sscanf`" more robust? |
| [`io/feof_1.c`](https://github.com/bonigarcia/c-programming/blob/master/io/feof_1.c) vs. [`feof_2.c`](https://github.com/bonigarcia/c-programming/blob/master/io/feof_2.c) | Why is the last line printed twice by `feof_1.c`? Rewrite the loop as `while (fgets(...) != NULL)`. |

### 5.5. The ink file format (exercises 3.13 – 3.15)

[`lab03/18_em_1.txt`](lab03/18_em_1.txt) is a handwritten math expression recorded with a pen tablet ("online ink"): the list of pen positions, in order. The first line is the label (LaTeX `\sqrt 4 8`, i.e. √48); every other line is one point `attr x y`, separated by tabs:

```
[\sqrt 4 8]
2	0	119
0	6	122
0	14	128
...
4	433	0
2	210	37
...
```

| `attr` | Meaning |
|---|---|
| `2` | first point of a stroke (pen down) |
| `0` | point inside a stroke |
| `4` | last point of a stroke (pen up) |

The file has 81 points in 4 strokes; `y` grows **downward**, as on a screen. In `lab03_io.c` you read the points into a dynamic array (3.13), draw them on a canvas of characters (3.14) and save the canvas to a file (3.15). When all tests pass, `./lab03_io 18_em_1.txt ink.txt` prints a drawing made of points (homework 3.19 joins them into lines):

```
18_em_1.txt: label "\sqrt 4 8", 81 points
+------------------------------------------------------------+
|                        *      * *    *            *    ** *|
|                     *                                      |
|                   *                                        |
|                   *       *                                |
|                   *      *                                 |
|                 *              *                           |
|                *        *                  ***   *         |
|               *                         ***                |
|              *                          ***       **       |
|*            *           *               **                 |
|**           *          *                 *     **          |
|                                                    *       |
|      *    **                 * *         *          *      |
|                       *         *  *    *            *     |
|                                         *           *      |
|         *                       *                   *      |
|                                         *          *       |
|                                  *         *   *           |
|                                                            |
|                                  *                         |
+------------------------------------------------------------+
```

---

## Part 6. Exercises

```bash
gcc -Wall -Wextra -g lab03.c -o lab03 && ./lab03
valgrind --leak-check=full ./lab03                     # must be clean: 0 errors, no leaks

gcc -Wall -Wextra -g lab03_io.c -o lab03_io && ./lab03_io 18_em_1.txt ink.txt
valgrind --leak-check=full ./lab03_io 18_em_1.txt      # must be clean too
```

**General requirement:** everything `PASS` **and** valgrind reports no errors.

### 6.1. Pointers and dynamic memory — [`lab03.c`](lab03/lab03.c)

| # | Function | Description |
|---|---|---|
| 3.1 | `void swap(int *a, int *b)` | Swap two numbers |
| 3.2 | `void min_max(const int *a, int n, int *min, int *max)` | Return 2 values through pointers |
| 3.3 | `int sum_pointer(const int *a, int n)` | Sum of an array, **without using `[]`** — pointer arithmetic only |
| 3.4 | `int *copy_array(const int *a, int n)` | Return a copy on the heap |
| 3.5 | `int *filter_even(const int *a, int n, int *returnSize)` | New array containing only the even numbers (LeetCode style) |
| 3.6 | `char *my_strdup(const char *s)` | Implement `strdup` yourself (remember to leave room for `'\0'`!) |
| 3.7 | `int *push_back(int *arr, int *size, int *capacity, int value)` | Dynamic array: when it is full, `realloc` to double the capacity |
| 3.8 | `int **alloc_matrix(int rows, int cols)`, `void free_matrix(int **m, int rows)` | 2D array using `int **` (Lecture 7) |
| 3.9 | `void allocate_int(int **p, int value)` | Allocate an `int` inside a function and "return" it through a parameter (fixes the bug in `out-of-scope-allocation_1.c`) |

### 6.2. Input/output — [`lab03_io.c`](lab03/lab03_io.c)

Run it from the `labs/lab03` folder: the tests open `18_em_1.txt` in the current working directory.

| # | Function | Description |
|---|---|---|
| 3.10 | `void sprint_time(char *out, const struct tm *t)` | Write `"hh:mm:ss"` into a buffer allocated by the caller (`sprintf`, `%02d`) |
| 3.11 | `void sprint_date(char *out, const struct tm *t)` | Write `"Wed, 18/11/2026"`: an array of strings for the weekday, `tm_mon + 1`, `tm_year + 1900` |
| 3.12 | `int parse_time(const char *s, int *h, int *m, int *sec)` | Parse `"hh:mm:ss"` with `sscanf`, return the values through pointers, reject invalid input using the return value of `sscanf` |
| 3.13 | `Point *read_ink(const char *filename, char *label, int label_size, int *count)` | Read the ink file with `fopen`/`fgets`/`sscanf` into an array grown with `realloc` (like 3.7); copy the label without overflowing it |
| 3.14 | `char **render_ink(const Point *pts, int n, int rows, int cols)`, `void free_canvas(char **canvas, int rows)` | Scale the points onto a `rows × cols` canvas whose rows are strings (like 3.8) |
| 3.15 | `int save_canvas(const char *filename, char **canvas, int rows)` | Write the canvas to a text file with `fprintf`; return `-1` if `fopen` fails |

After the tests, `main` uses your functions to print the current date and time (`time`, `localtime`) and, when you give it a file name, to draw the ink. **Debug with arguments:** set `"args": ["18_em_1.txt", "ink.txt"]` in `launch.json`, put a breakpoint inside the `while (fgets(...))` loop of `read_ink`, and watch `line`, `*count` and the last point you stored.

### Homework

- **3.16** `char **split(const char *s, char sep, int *count)`: split a string into an array of strings (each allocated separately), plus a `free_split` function. Check it with valgrind.
- **3.17** Allocate an **n-dimensional** array recursively, returning `void *` (Lecture 7). Study [`lecture07-review/multi_array/alloc_nd.c`](../lecture07-review/multi_array/alloc_nd.c), then write the free function yourself.
- **3.18** (LeetCode, pay attention to `returnSize`) [1480. Running Sum of 1d Array](https://leetcode.com/problems/running-sum-of-1d-array/), [2595. Number of Even and Odd Bits](https://leetcode.com/problems/number-of-even-and-odd-bits/), [977. Squares of a Sorted Array](https://leetcode.com/problems/squares-of-a-sorted-array/).
- **3.19** Join the points: in `render_ink`, connect each point to the next point **of the same stroke** (never connect a point with `attr == 4` to the next one). To draw the segment from `(c1, r1)` to `(c2, r2)`, take `k = max(|c2 - c1|, |r2 - r1|)` steps and mark `(c1 + i*(c2 - c1)/k, r1 + i*(r2 - r1)/k)` for `i = 0..k` — or look up Bresenham's line algorithm. The √48 becomes easy to read.
- **3.20** `int save_svg(const char *filename, const Point *pts, int n)`: write the ink as an SVG image with `fprintf` — inside `<svg xmlns="http://www.w3.org/2000/svg" viewBox="min_x min_y width height">`, write one `<polyline points="x1,y1 x2,y2 ..." fill="none" stroke="black"/>` per stroke — then open the file in a web browser.
- **3.21** Let the user choose the canvas size: `./lab03_io 18_em_1.txt ink.txt 30 90`. Convert the arguments with `strtol` and reject invalid values (`abc`, `0`, `-5`) with a message on `stderr`.

## Submission

- `labs/lab03/lab03.c`: all `PASS`, clean valgrind run (screenshot of the `HEAP SUMMARY` and `ERROR SUMMARY` sections)
- `labs/lab03/leaky.c`, fixed, with notes on the 4 bugs
- `labs/lab03/lab03_io.c`: all `PASS`, clean valgrind run of `./lab03_io 18_em_1.txt`, plus the `ink.txt` it saved
- `labs/lab03/time_input.c` (mini-exercise in Part 5.2)

If you submit a ZIP file instead of a Git repository, pack only the source and text files, then check the archive before uploading it:

```bash
cd ~/prog1/cse-programming1/labs
zip lab03_<student_id>.zip lab03/*.c lab03/*.txt     # zip -r <archive>.zip <folder> packs a whole folder
unzip -l lab03_<student_id>.zip                      # list the contents; unzip <archive>.zip extracts it
```

## Further reading

- *Essential C*, section 3 (pointers), section 6 (heap memory)
- *The C Programming Language* (K&R), Chapter 7 (Input and Output)
- Valgrind Quick Start: https://valgrind.org/docs/manual/quick-start.html
- Format specifiers: [`printf`](https://en.cppreference.com/w/c/io/fprintf), [`scanf`](https://en.cppreference.com/w/c/io/fscanf) on cppreference
- Example code: [`lecture03-array-pointer/pointers/`](../lecture03-array-pointer/pointers), [`lecture03-array-pointer/dynamic_mem/`](../lecture03-array-pointer/dynamic_mem), [`bonigarcia/c-programming/io`](https://github.com/bonigarcia/c-programming/tree/master/io)

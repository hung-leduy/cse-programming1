# Lab 2 — Arrays, strings, and debugging

> **Session 2** · Related: Lecture 3 (Array), Lecture 7 (IDE, debug), Lecture 8 (String, `#ifdef DEBUG`)
> **Reference repo:** [bonigarcia/c-programming](https://github.com/bonigarcia/c-programming) — folders `arrays`, `strings`, `debug`
> **Starter code:** [`lab02/lab02.c`](lab02/lab02.c), [`lab02/buggy.c`](lab02/buggy.c)

## Objectives

- Declare, initialize, and traverse 1D and 2D arrays; pass arrays to functions.
- Understand that a C string is a `char` array terminated by `'\0'`; use the functions in `<string.h>`.
- Debug with conditional `printf` (`#ifdef DEBUG`), with `gdb`, and with VS Code (breakpoints, stepping, watches).

## Suggested timing (≈ 3 hours)

| Time | Content |
|---|---|
| 0:00 – 0:25 | Part 1: arrays |
| 0:25 – 0:55 | Part 2: strings |
| 0:55 – 1:35 | Part 3: debugging with `#ifdef`, gdb, VS Code; fix `buggy.c` |
| 1:35 – 2:45 | Exercises 2.1 – 2.10 in `lab02.c` |
| 2:45 – 3:00 | Review solutions |

---

## Part 1. Arrays (≈ 25 minutes)

| File | Question |
|---|---|
| [`arrays/arrays_1.c`](https://github.com/bonigarcia/c-programming/blob/master/arrays/arrays_1.c) | Also print `array_1[2]` (never assigned). What is the result? Is it the same every run? |
| [`arrays/arrays_3.c`](https://github.com/bonigarcia/c-programming/blob/master/arrays/arrays_3.c) | Why use `#define SIZE` instead of writing the number 4 several times? |
| [`arrays/arrays_4.c`](https://github.com/bonigarcia/c-programming/blob/master/arrays/arrays_4.c) | What does `sizeof(array) / sizeof(array[0])` compute? Compile with `-Wall -Wextra`: what warning do you get about `int i` and `size_t size`? |
| [`arrays/arrays_5_error.c`](https://github.com/bonigarcia/c-programming/blob/master/arrays/arrays_5_error.c) → [`arrays_5_fixed.c`](https://github.com/bonigarcia/c-programming/blob/master/arrays/arrays_5_fixed.c) | Why can't you assign `array_2 = array_1`? (Lecture 3: "Array names are const") |
| [`arrays/qsort_1.c`](https://github.com/bonigarcia/c-programming/blob/master/arrays/qsort_1.c) | Modify it to sort in **descending** order. (The `compare` function is a *function pointer* — covered in depth in Lab 4.) |

### Experiment: `sizeof` when passing an array to a function

```c
void f(int a[]) {
    printf("in function: sizeof(a) = %zu\n", sizeof(a));
}
int main() {
    int a[10];
    printf("in main: sizeof(a) = %zu\n", sizeof(a));
    f(a);
}
```

Are the two values equal? Use this to explain why a function that takes an array **always needs an extra size parameter** `n` (Lecture 3: `get_max_1d_array(int a[], int N)`).

### 2D arrays

Run [`lecture03-array-pointer/arrays/array_2d.c`](../lecture03-array-pointer/arrays/array_2d.c) from the course repo. On paper, draw how the array `int a[3][4]` is stored **contiguously** in memory (row by row). Why must the parameter be declared as `int a[][4]` and not `int a[][]`?

---

## Part 2. Strings (≈ 30 minutes)

| File | Question |
|---|---|
| [`strings/basic_string_1.c`](https://github.com/bonigarcia/c-programming/blob/master/strings/basic_string_1.c), [`_2.c`](https://github.com/bonigarcia/c-programming/blob/master/strings/basic_string_2.c), [`_4.c`](https://github.com/bonigarcia/c-programming/blob/master/strings/basic_string_4.c) | What do the three declarations have in common? What happens if you remove the `'\0'` in `_2.c`? |
| [`strings/basic_string_3.c`](https://github.com/bonigarcia/c-programming/blob/master/strings/basic_string_3.c) | Add `greetings[0] = 'h';`. What happens to the program? Compare `char s[]` with `char *s` (Lecture 8). |
| [`strings/error_string.c`](https://github.com/bonigarcia/c-programming/blob/master/strings/error_string.c) | Why is this an error? Fix it with `strcpy`. |
| [`strings/strlen_3.c`](https://github.com/bonigarcia/c-programming/blob/master/strings/strlen_3.c) | How is `strlen` different from `sizeof`? |
| [`strings/strcpy_2.c`](https://github.com/bonigarcia/c-programming/blob/master/strings/strcpy_2.c), [`strcat.c`](https://github.com/bonigarcia/c-programming/blob/master/strings/strcat.c) | What happens if the destination array is too small? Why should you prefer `strncpy`/`strncat`/`snprintf`? |
| [`strings/strcmp_1.c`](https://github.com/bonigarcia/c-programming/blob/master/strings/strcmp_1.c) … [`strcmp_3.c`](https://github.com/bonigarcia/c-programming/blob/master/strings/strcmp_3.c) | Why should you **not** compare strings with `str1 == str2`? |
| [`strings/strtok_1.c`](https://github.com/bonigarcia/c-programming/blob/master/strings/strtok_1.c) | Split the sentence `"C,is;fun"` on both `,` and `;`. Print `str` after splitting: what happened to the original string? |
| [`strings/memset_1.c`](https://github.com/bonigarcia/c-programming/blob/master/strings/memset_1.c) | What is `memset` used for? |

**ASCII reminder (Lecture 2):** `'a' - 'A' == 32`, `'7' - '0' == 7`. The string exercises below use these tricks a lot.

---

## Part 3. Debugging (≈ 40 minutes)

### 3.1. Conditional `printf` with `#ifdef DEBUG`

Examples: [`debug/debug_1.c`](https://github.com/bonigarcia/c-programming/blob/master/debug/debug_1.c), [`debug_2.c`](https://github.com/bonigarcia/c-programming/blob/master/debug/debug_2.c), [`debug_3.c`](https://github.com/bonigarcia/c-programming/blob/master/debug/debug_3.c)

```bash
cd ~/prog1/c-programming/debug
gcc -Wall debug_3.c -o debug_3 && ./debug_3              # Release build
gcc -Wall -DDEBUG debug_3.c -o debug_3 && ./debug_3      # Debug build
./debug_3 2> /dev/null                                   # discard stderr: what is left?
```

**Questions:** What does the `-DDEBUG` flag do? Why print debug information to `stderr` instead of `stdout`?

### 3.2. gdb

Example: [`debug/debug_gdb.c`](https://github.com/bonigarcia/c-programming/blob/master/debug/debug_gdb.c) — a buggy program; run it and find out where it goes wrong.

```bash
gcc -Wall -g debug_gdb.c -o debug_gdb    # -g: include debug information
gdb ./debug_gdb
```

| gdb command | Meaning |
|---|---|
| `break printArray` / `b 5` | Set a breakpoint at a function / at line 5 |
| `run` / `r` | Run the program |
| `next` / `n` | Run the next line (without stepping into functions) |
| `step` / `s` | Run the next line (stepping into functions) |
| `continue` / `c` | Run until the next breakpoint |
| `print i` / `p arr[i]` | Print the value of an expression |
| `p *arr@size` | Print `size` elements of the array that `arr` points to |
| `display i` | Automatically print `i` after every step |
| `info locals` | Print the local variables |
| `backtrace` / `bt` | Show the chain of function calls (useful after a `Segmentation fault`) |
| `quit` / `q` | Quit |

Task: set a breakpoint in `printArray`, use `display i` and `next` until you see the bug. Fix it.

### 3.3. VS Code

Copy `tasks.json` and `launch.json` from [`lecture07-review/vscode/`](../lecture07-review/vscode) into a `.vscode/` folder. Open `debug_gdb.c`, set a breakpoint (click to the left of a line number), and press **F5**. Use:

- The **Variables** and **Watch** panels (add the expressions `arr[i]`, `*arr@5`).
- The toolbar: Continue (F5), Step Over (F10), Step Into (F11), Step Out (Shift+F11).
- The **Debug Console**: type `-exec p i` or any expression.

### 3.4. Debugging exercise: `buggy.c`

The file [`lab02/buggy.c`](lab02/buggy.c) compiles but gives **wrong results**. It has **4 bugs**. You may only use gdb or VS Code (no extra `printf`) to find them. For each bug, write in the comment at the top of the file: which line, what the symptom was, and how you fixed it.

```bash
cd ~/prog1/cse-programming1/labs/lab02
gcc -Wall -g buggy.c -o buggy && ./buggy
```

Expected correct output:

```
sum = 151
average = 30.20
max = 51
max temp = -1
reversed: olleh
```

---

## Part 4. Exercises

```bash
cd ~/prog1/cse-programming1/labs/lab02
gcc -Wall -Wextra -g lab02.c -o lab02 && ./lab02
```

**Arrays**

| # | Function | Description |
|---|---|---|
| 2.1 | `int array_max(int a[], int n)` | Largest value |
| 2.2 | `double array_mean(int a[], int n)` | Arithmetic mean (watch out for integer division!) |
| 2.3 | `void reverse_array(int a[], int n)` | Reverse in place |
| 2.4 | `int count_value(int a[], int n, int value)` | Number of occurrences of `value` |
| 2.5 | `void max_2d(int a[][COLS], int rows, int axis, int out[])` | Max along an axis, like numpy (Lecture 3): `axis = 0` per column, `axis = 1` per row |
| 2.6 | `void matmul(...)` | Matrix multiplication `A[2][3] x B[3][2]` (Lecture 3) |

**Strings** (do not use `<string.h>` for 2.7)

| # | Function | Description |
|---|---|---|
| 2.7 | `int my_strlen(const char s[])` | Implement `strlen` yourself |
| 2.8 | `void to_upper(char s[])` | Convert lowercase letters to uppercase, leave other characters unchanged |
| 2.9 | `int is_palindrome(const char s[])` | Is the string a palindrome? (`"racecar"` → 1) |
| 2.10 | `int count_words(const char s[])` | Count the words; words are separated by one or more spaces |

### Homework

- **2.11** `int my_atoi(const char s[])`: like `atoi`, supporting a leading `+`/`-` sign (Lecture 2, exercise 2).
- **2.12** Write a program that reads a line with `fgets` and prints how many times each letter `a`–`z` appears (case-insensitive). Hint: an `int count[26]` array, indexed by `c - 'a'`.
- **2.13** (LeetCode) [1. Two Sum](https://leetcode.com/problems/two-sum/) (arrays only, O(n²) is fine), [344. Reverse String](https://leetcode.com/problems/reverse-string/), [58. Length of Last Word](https://leetcode.com/problems/length-of-last-word/).

## Submission

- `labs/lab02/lab02.c` (all `PASS`)
- `labs/lab02/buggy.c`, fixed, with comments describing the 4 bugs

## Further reading

- *Essential C*, section 3 (Complex data types: arrays), section 6 (strings)
- K&R, sections 1.6–1.9, 5.5
- GDB cheat sheet: https://darkdust.net/files/GDB%20Cheat%20Sheet.pdf

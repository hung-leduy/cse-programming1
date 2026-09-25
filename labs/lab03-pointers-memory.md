# Lab 3 — Pointers and dynamic memory

> **Session 3** · Related: Lecture 3 (Pointer, dynamic memory, scope, call by value/reference), Lecture 7 (multi array)
> **Reference repo:** [bonigarcia/c-programming](https://github.com/bonigarcia/c-programming) — folders `pointers`, `dynamic_mem`, `valgrind`
> **Starter code:** [`lab03/lab03.c`](lab03/lab03.c), [`lab03/leaky.c`](lab03/leaky.c)

## Objectives

- Understand that a pointer is a variable that holds an address; use `&`, `*`, `->`, and `NULL` confidently.
- The relationship between arrays and pointers; pointer arithmetic (`p + 1`, `*(p++)`, `*(++p)`).
- Pass by value vs. pass by reference; return multiple values through pointers.
- Allocate and free dynamic memory: `malloc`, `calloc`, `realloc`, `free`.
- Recognize and fix memory errors — leaks, dangling pointers, out-of-bounds writes, uninitialized variables — using **valgrind**.

## Suggested timing (≈ 3 hours)

| Time | Content |
|---|---|
| 0:00 – 0:35 | Part 1: pointer basics, pointers and arrays |
| 0:35 – 0:50 | Part 2: pass by value / by reference |
| 0:50 – 1:20 | Part 3: dynamic memory, scope, dangling pointers |
| 1:20 – 1:45 | Part 4: valgrind, fix `leaky.c` |
| 1:45 – 2:50 | Exercises 3.1 – 3.9 in `lab03.c` |
| 2:50 – 3:00 | Review solutions |

> **Draw pictures.** For each example, draw the "memory cells" (variable name, address, value) and the pointer arrows. Most pointer bugs become obvious once you draw them.

---

## Part 1. Pointer basics (≈ 35 minutes)

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

## Part 2. Pass by value and by reference (≈ 15 minutes)

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

## Part 3. Dynamic memory (≈ 30 minutes)

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

## Part 4. Valgrind (≈ 25 minutes)

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

## Part 5. Exercises

```bash
gcc -Wall -Wextra -g lab03.c -o lab03 && ./lab03
valgrind --leak-check=full ./lab03       # must be clean: 0 errors, no leaks
```

**General requirement:** everything `PASS` **and** valgrind reports no errors.

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

### Homework

- **3.10** `char **split(const char *s, char sep, int *count)`: split a string into an array of strings (each allocated separately), plus a `free_split` function. Check it with valgrind.
- **3.11** Allocate an **n-dimensional** array recursively, returning `void *` (Lecture 7). Study [`lecture07-review/multi_array/alloc_nd.c`](../lecture07-review/multi_array/alloc_nd.c), then write the free function yourself.
- **3.12** (LeetCode, pay attention to `returnSize`) [1480. Running Sum of 1d Array](https://leetcode.com/problems/running-sum-of-1d-array/), [2595. Number of Even and Odd Bits](https://leetcode.com/problems/number-of-even-and-odd-bits/), [977. Squares of a Sorted Array](https://leetcode.com/problems/squares-of-a-sorted-array/).

## Submission

- `labs/lab03/lab03.c`: all `PASS`, clean valgrind run (screenshot of the `HEAP SUMMARY` and `ERROR SUMMARY` sections)
- `labs/lab03/leaky.c`, fixed, with notes on the 4 bugs

## Further reading

- *Essential C*, section 3 (pointers), section 6 (heap memory)
- Valgrind Quick Start: https://valgrind.org/docs/manual/quick-start.html
- Example code: [`lecture03-array-pointer/pointers/`](../lecture03-array-pointer/pointers), [`lecture03-array-pointer/dynamic_mem/`](../lecture03-array-pointer/dynamic_mem)

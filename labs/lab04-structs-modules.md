# Lab 4 — Structs, linked lists, function pointers, and multi-file programs

> **Session 4** · Related: Lecture 3 (Structure, linked list), Lecture 7 (freeing a linked list), Lecture 8 (function pointer, typedef, preprocessor, compiling/linking, multiple files)
> **Reference repo:** [bonigarcia/c-programming](https://github.com/bonigarcia/c-programming) — folders `structured_data`, `types` (typedef, enum), `pointers` (function pointer), `dynamic_mem/linked_list.c`, `modules`, `debug`
> **Starter code:** [`lab04/`](lab04) — `student.h`, `student.c`, `test_student.c`, `Makefile`

## Objectives

- Define and use `struct`, `typedef`, `enum`; access members with `.` and `->`.
- Implement a singly linked list: insert, search, delete, free.
- Use function pointers: pass functions as arguments (`qsort`, `count_if`), `typedef` for function pointers.
- Organize a program into multiple files (`.h` for declarations, `.c` for implementations), compile them separately, and link them with a `Makefile`.
- Use the preprocessor: include guards, `#define`, `#ifdef DEBUG`.

## Suggested timing (≈ 3 hours)

| Time | Content |
|---|---|
| 0:00 – 0:20 | Part 1: struct, typedef, enum, union |
| 0:20 – 0:40 | Part 2: function pointers |
| 0:40 – 1:05 | Part 3: multi-file programs, Makefile |
| 1:05 – 2:45 | Part 4: student management mini-project (4.1 – 4.3) |
| 2:45 – 3:00 | Review solutions, introduce homework |

---

## Part 1. Struct, typedef, enum (≈ 20 minutes)

| File | Question |
|---|---|
| [`structured_data/struct_1.c`](https://github.com/bonigarcia/c-programming/blob/master/structured_data/struct_1.c) | Declaring a struct and accessing members with `.` |
| [`structured_data/struct_2.c`](https://github.com/bonigarcia/c-programming/blob/master/structured_data/struct_2.c) | How does `typedef struct {...} my_structure;` help? |
| [`types/typedef.c`](https://github.com/bonigarcia/c-programming/blob/master/types/typedef.c) | `typedef` for basic types |
| [`types/enums.c`](https://github.com/bonigarcia/c-programming/blob/master/types/enums.c) | What is the value of `SATURDAY`? Why use an `enum` instead of plain numbers? |
| [`structured_data/union_1.c`](https://github.com/bonigarcia/c-programming/blob/master/structured_data/union_1.c) | (Optional) Why does `salary` get corrupted? Compare the `sizeof` of a `union` and a `struct` with the same members. |
| [`pointers/struct_pointer.c`](https://github.com/bonigarcia/c-programming/blob/master/pointers/struct_pointer.c), [`dynamic_mem/malloc_4.c`](https://github.com/bonigarcia/c-programming/blob/master/dynamic_mem/malloc_4.c) | `(*p).a` and `p->a` (Lecture 3). Allocating a struct on the heap. |

**Experiment:** print `sizeof(struct my_struct)` in `struct_1.c`. Is the result equal to `sizeof(int) + sizeof(char)`? (Look up *padding*.)

**Passing a struct to a function:** `void f(Student s)` copies the whole struct; `void f(const Student *s)` passes only the address (8 bytes). When should you use each?

### Linked lists

Read [`dynamic_mem/linked_list.c`](https://github.com/bonigarcia/c-programming/blob/master/dynamic_mem/linked_list.c) and [`lecture03-array-pointer/structs/linked_list.c`](../lecture03-array-pointer/structs/linked_list.c). Draw the list `1 → 2 → 3 → NULL` and the steps for:

1. Inserting at the front. 2. Inserting at the back. 3. Deleting a node in the middle. 4. Freeing the whole list (why must you save `next` before calling `free`?)

---

## Part 2. Function pointers (≈ 20 minutes)

| File | Question |
|---|---|
| [`pointers/function_pointer_1.c`](https://github.com/bonigarcia/c-programming/blob/master/pointers/function_pointer_1.c) | Read the type `int (*func_ptr)(int, int)` as: "func_ptr is a pointer to a function that takes (int, int) and returns int". |
| [`pointers/function_pointer_2.c`](https://github.com/bonigarcia/c-programming/blob/master/pointers/function_pointer_2.c) | The calculator uses `switch` to **choose a function**, then calls it once. Rewrite it with an **array of function pointers** `operations[option - 1]`, removing the `switch` entirely. |
| [`arrays/qsort_1.c`](https://github.com/bonigarcia/c-programming/blob/master/arrays/qsort_1.c) | `qsort` does not know the element type — it calls back our `compare` function. Why are the parameters `const void *`? |

See also in the course repo: [`reduce.c`](../lecture08-function-pointers/function_pointers/reduce.c) (Lecture 8: `int reduce(int **arr, int N, int M, int (*func)(int, int))`) and [`typedef.c`](../lecture08-function-pointers/function_pointers/typedef.c) (`typedef int (*fp)(int, int);`).

---

## Part 3. Multi-file programs and Makefiles (≈ 25 minutes)

The reference repo has 4 versions of [`modules/`](https://github.com/bonigarcia/c-programming/tree/master/modules), in increasing order of complexity:

| Folder | What's new |
|---|---|
| [`program.c`](https://github.com/bonigarcia/c-programming/blob/master/modules/program.c) | Everything in one file |
| [`mod1`](https://github.com/bonigarcia/c-programming/tree/master/modules/mod1) | Split into `person.h` (declarations) and `person.c` (implementation); the Makefile compiles each `.o` file, then links |
| [`mod2`](https://github.com/bonigarcia/c-programming/tree/master/modules/mod2) | Adds a `job` module that reuses `person` |
| [`mod3`](https://github.com/bonigarcia/c-programming/tree/master/modules/mod3) | A global variable shared between files: `extern` |
| [`mod4`](https://github.com/bonigarcia/c-programming/tree/master/modules/mod4) | A `debug` macro turned on/off with `-DDEBUG` |

```bash
cd ~/prog1/c-programming/modules/mod1
make compile && ./main
make clean
```

**Questions:**

1. Open `person.h`: what is `#ifndef PERSON_H / #define PERSON_H / #endif` for? Try removing it in `mod2` (where `person.h` is included twice indirectly) — what error do you get?
2. The `mod1` Makefile always recompiles every file. If you only edit `person.c`, do you in principle need to recompile `main.c`? Compare with `lab04/Makefile` (which uses dependency rules): edit `student.c`, then run `make test` twice and see which commands are re-run.
3. Run `nm person.o` and `nm main.o`. What do the symbols `T` and `U` mean? Does the error `undefined reference to 'sum_ages'` happen at the compile step or the link step?
4. In `mod3`, what does `extern Job company[];` declare? In which file is the variable actually defined?

### Makefile basics

```make
test_student: test_student.o student.o     # target: dependencies
	$(CC) $(CFLAGS) $^ -o $@                # command (starts with a TAB, not spaces!)

%.o: %.c student.h                         # pattern rule: .c -> .o
	$(CC) $(CFLAGS) -c $< -o $@
```

`$@` = the target name, `$<` = the first dependency, `$^` = all dependencies. `make` only recompiles files that **have changed**.

---

## Part 4. Mini-project: student management

Folder [`lab04/`](lab04):

| File | Role |
|---|---|
| [`student.h`](lab04/student.h) | **Declarations** (complete): `Student`, `Node`, function pointer types, the `DEBUG_PRINT` macro, prototypes |
| [`student.c`](lab04/student.c) | **Implementation** — you complete the `TODO`s here |
| [`test_student.c`](lab04/test_student.c) | Test program (do not modify) |
| [`Makefile`](lab04/Makefile) | `make test`, `make debug`, `make valgrind`, `make clean` |

```bash
cd ~/prog1/cse-programming1/labs/lab04
make test
```

### 4.1 Struct

- `make_student(id, name, gpa)`: create and return a `Student`. A name that is too long must be truncated so it does not overflow the `name` array.

### 4.2 Linked list

Functions that modify the list **return the new head**, so always call them like `list = list_push_front(list, s);`.

| Function | Requirement |
|---|---|
| `list_push_front` | Insert at the front |
| `list_push_back` | Insert at the back (an empty list is a special case) |
| `list_length` | Count the nodes |
| `list_find` | Return a `Student *` pointing **into** the list (so the GPA can be modified), or `NULL` |
| `list_remove` | Remove by id and `free` that node; consider 3 cases: first, middle, and last node |
| `list_free` | Free the whole list |

> Alternative approach (Lecture 3): pass `Node **head` so the function can modify the caller's head directly — see [`linked_list.c`](../lecture03-array-pointer/structs/linked_list.c). Once you are done, compare the two approaches.

### 4.3 Function pointers

| Function | Requirement |
|---|---|
| `compare_by_name` | Compare by name (use `strcmp`) |
| `compare_by_gpa_desc` | GPA in descending order. `gpa` is a `float`, so you must **not** `return x->gpa - y->gpa` (why?) |
| `list_to_array` | Copy at most `max` elements into an array |
| `sort_students` | Sort with `qsort` using the comparison function passed in |
| `is_excellent` | GPA ≥ 3.6 |
| `count_if` | Count the students that satisfy **any condition** passed in as a function pointer |

### 4.4 Final check

```bash
make test        # all PASS
make debug       # you should see [DEBUG] student.c:... lines
make valgrind    # 0 errors, no leaks
```

Add a `DEBUG_PRINT(...)` to `list_remove` that prints the removed id; check that `make test` (the normal build) does **not** print that line.

---

## Homework

**4.5 — Menu-driven application** (`lab04/app.c`, create it yourself; run it with `make app && ./app`). Use top-down design as in [`top-down/main.c`](https://github.com/bonigarcia/c-programming/blob/master/top-down/main.c), **using only the functions in `student.h`**:

```
1. Add student             4. Update GPA
2. Remove student by id    5. Print list (sorted by: id / name / GPA)
3. Find by id              6. Count excellent students
0. Exit
```

Item 5 uses an **array of function pointers** `StudentCompare sorters[] = {compare_by_id, compare_by_name, compare_by_gpa_desc};` instead of a `switch`. Read input with `fgets` + `sscanf` (see [`io/readline_fgets.c`](https://github.com/bonigarcia/c-programming/blob/master/io/readline_fgets.c), [`io/sscanf.c`](https://github.com/bonigarcia/c-programming/blob/master/io/sscanf.c)) to avoid the leftover-input problems of `scanf`.

**4.6 — Saving to and loading from a file** (advanced): add two functions to the module, `int save_csv(const Node *head, const char *filename)` and `Node *load_csv(const char *filename)`, with one line per student in the form `1003,Nguyen Van An,3.45`. See [`io/file_write.c`](https://github.com/bonigarcia/c-programming/blob/master/io/file_write.c), [`io/fscanf.c`](https://github.com/bonigarcia/c-programming/blob/master/io/fscanf.c).

**4.7 — Binary search tree** (advanced): re-implement the student list as a BST keyed by id (insert, search, in-order traversal, free). See [`binary_tree.c`](../lecture03-array-pointer/structs/binary_tree.c).

## Submission

- `labs/lab04/student.c`: `make test` all `PASS`, `make valgrind` clean
- (Homework) `labs/lab04/app.c`

## Further reading

- *Essential C*, section 3 (struct), section 7 (function pointers), section 9 (preprocessor, multiple files)
- K&R, sections 4.5 (header files), 5.11 (function pointers), chapter 6 (structures)
- GNU Make manual — An Introduction to Makefiles: https://www.gnu.org/software/make/manual/html_node/Introduction.html
- Example code: [`lecture08-function-pointers/`](../lecture08-function-pointers)

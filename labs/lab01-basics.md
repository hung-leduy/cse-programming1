# Lab 1 — C Fundamentals: compilation, data types, operators, branching, loops, functions

> **Session 1** · Related: Lecture 1 (Course introduction), Lecture 2 (Basic elements)
> **Reference repo:** [bonigarcia/c-programming](https://github.com/bonigarcia/c-programming) — folders `hello_world`, `types`, `variables`, `operators`, `boolean`, `control_flow`, `functions`, `io`, `top-down`
> **Starter code:** [`lab01/lab01.c`](lab01/lab01.c)

## Objectives

- Understand the 4 stages of compilation: preprocessing → compiling → assembling → linking.
- Know the sizes, ranges, and type casting of the basic data types.
- Use arithmetic, relational, and logical operators, `++`/`--`, and the ternary operator correctly.
- Write `if/else`, `switch`, `for`, `while`, `do-while`, `break`, `continue`.
- Break a problem down into small functions (divide and conquer, top-down design).
- Read input from the keyboard with `scanf` and take command-line arguments with `argc/argv`.

## Suggested timing (≈ 3 hours)

| Time | Content |
|---|---|
| 0:00 – 0:30 | Check Lab 0, clone the repo, Part 1 (the compilation process) |
| 0:30 – 1:00 | Part 2 (data types), Part 3 (operators) |
| 1:00 – 1:30 | Part 4 (control flow), Part 5 (functions, variable scope) |
| 1:30 – 2:45 | Exercises 1.1 – 1.8 in `lab01.c` |
| 2:45 – 3:00 | Review solutions, introduce homework 1.9, 1.10 |

## Preparation

```bash
cd ~/prog1
git clone https://github.com/bonigarcia/c-programming.git   # if you don't have it yet
cd c-programming
```

> **Rule for the whole session:** before running each example, **predict the output** and write it down. After running it, compare and explain any differences.
> Always compile with `-Wall` and **read every warning** — warnings are often real bugs.

---

## Part 1. The compilation process (≈ 20 minutes)

Example: [`hello_world/hello_macro.c`](https://github.com/bonigarcia/c-programming/blob/master/hello_world/hello_macro.c)

```bash
cd hello_world
gcc -E hello_macro.c -o hello_macro.i   # 1. preprocess: handle #include, #define
gcc -S hello_macro.i -o hello_macro.s   # 2. compile: C -> assembly
gcc -c hello_macro.s -o hello_macro.o   # 3. assemble: assembly -> machine code
gcc hello_macro.o -o hello_macro        # 4. link: + standard library -> executable
./hello_macro
```

**Questions:**

1. Open `hello_macro.i` (use `tail -n 20`). What has the line `return OK;` become? Why is the `.i` file hundreds of lines long?
2. Open `hello_macro.s` and find the line that calls `printf` (or `puts`). Why can the compiler replace `printf` with `puts`?
3. Run `ls -l hello_macro.o hello_macro`. Why is the executable larger than the `.o` file?

### Command-line arguments

Example: [`hello_world/hello_args.c`](https://github.com/bonigarcia/c-programming/blob/master/hello_world/hello_args.c)

```bash
gcc -Wall hello_args.c -o hello_args
./hello_args
./hello_args An
./hello_args "Nguyen Van An"
echo $?        # exit (return) code of the program that just ran
```

**Questions:** What is `argc` in each run? What is `argv[0]`? Why does the program use `fprintf(stderr, ...)` and `return 1` when the argument is missing?

---

## Part 2. Data types (≈ 15 minutes)

| File | Prediction / Question |
|---|---|
| [`types/sizeof_1.c`](https://github.com/bonigarcia/c-programming/blob/master/types/sizeof_1.c), [`sizeof_2.c`](https://github.com/bonigarcia/c-programming/blob/master/types/sizeof_2.c) | Compare with the "short ≤ int ≤ long" table in Lecture 2. Is `long` 4 or 8 bytes on your machine? |
| [`types/ranges.c`](https://github.com/bonigarcia/c-programming/blob/master/types/ranges.c) | What is the largest `int` value? What happens when you add 1 to `INT_MAX`? (try it yourself) |
| [`types/casting.c`](https://github.com/bonigarcia/c-programming/blob/master/types/casting.c) | When do you need an explicit cast to avoid losing the fractional part? |
| [`types/promotion_1.c`](https://github.com/bonigarcia/c-programming/blob/master/types/promotion_1.c), [`promotion_2.c`](https://github.com/bonigarcia/c-programming/blob/master/types/promotion_2.c) | What is `1 + 'A'`? What does `char c = 65` print with `%c`? |
| [`boolean/bool_1.c`](https://github.com/bonigarcia/c-programming/blob/master/boolean/bool_1.c) | What numbers are `true`/`false` really? |

**Try this too** (example from Lecture 2):

```c
char variable = 'a';
float v1 = variable / 5;          // = ?
float v2 = (float)variable / 5;   // = ?
```

---

## Part 3. Operators (≈ 15 minutes)

| File | Prediction / Question |
|---|---|
| [`operators/aritmetic.c`](https://github.com/bonigarcia/c-programming/blob/master/operators/aritmetic.c) | What are `7 / 2`, `7 % 2`, `7.0 / 2`? |
| [`operators/relational.c`](https://github.com/bonigarcia/c-programming/blob/master/operators/relational.c), [`logical.c`](https://github.com/bonigarcia/c-programming/blob/master/operators/logical.c) | What type does a comparison produce? |
| [`operators/ternary.c`](https://github.com/bonigarcia/c-programming/blob/master/operators/ternary.c) | Rewrite it using `if/else`. |
| [`operators/bitwise.c`](https://github.com/bonigarcia/c-programming/blob/master/operators/bitwise.c) | (Advanced) What is `x & 1` used for? |

**`++` quiz** (Lecture 1) — predict, then check:

```c
int i = 42;
int j = (i++ + 10);   // j = ?, i = ?
int k = (++i + 10);   // k = ?, i = ?
```

**Common mistake:** writing `if (x = 5)` instead of `if (x == 5)`. Compile with `-Wall` and read the warning.

---

## Part 4. Control flow (≈ 15 minutes)

Run and read: [`control_flow/for.c`](https://github.com/bonigarcia/c-programming/blob/master/control_flow/for.c), [`break.c`](https://github.com/bonigarcia/c-programming/blob/master/control_flow/break.c), [`continue.c`](https://github.com/bonigarcia/c-programming/blob/master/control_flow/continue.c), [`switch.c`](https://github.com/bonigarcia/c-programming/blob/master/control_flow/switch.c)

**Questions:**

1. In `switch.c`, delete one `break` statement. What does the program print? What is this behavior called (fall-through)? When would we use it *on purpose* (hint: combining `case 3:` and `case 4:` in Lecture 3)?
2. `switch.c` already groups months with the same number of days — exercise 1.8 extends this to handle leap years.
3. Rewrite the `for` loop in `for.c` using `while` and using `do-while`. How is `do-while` different?

---

## Part 5. Functions and variable scope (≈ 15 minutes)

| File | Question |
|---|---|
| [`functions/functions_1.c`](https://github.com/bonigarcia/c-programming/blob/master/functions/functions_1.c) | Function defined before `main` |
| [`functions/functions_2.c`](https://github.com/bonigarcia/c-programming/blob/master/functions/functions_2.c) | Compile with `-Wall`: what warning do you get (gcc ≥ 14 reports an **error**)? Why? |
| [`functions/functions_3.c`](https://github.com/bonigarcia/c-programming/blob/master/functions/functions_3.c) | How does a declaration (prototype) fix the problem above? Relate this to `.h` header files in Lecture 1. |
| [`variables/scopes_1.c`](https://github.com/bonigarcia/c-programming/blob/master/variables/scopes_1.c) | Why doesn't it compile? Fix it. |
| [`variables/static.c`](https://github.com/bonigarcia/c-programming/blob/master/variables/static.c) | Predict the 10 lines printed. How is a `static` variable different from an ordinary local variable? |
| [`io/scanf_1.c`](https://github.com/bonigarcia/c-programming/blob/master/io/scanf_1.c) | Enter `Nguyen Van An`. Why does it print only `Nguyen`? |
| [`top-down/main.c`](https://github.com/bonigarcia/c-programming/blob/master/top-down/main.c) | Top-down design: write `main` with "empty" functions first, then fill in the details. |

---

## Part 6. Exercises

Open [`lab01/lab01.c`](lab01/lab01.c). The file already contains function skeletons (marked `TODO`) and a self-checking `main`. Your task: implement the functions until every line shows `PASS`.

```bash
cd ~/prog1/cse-programming1/labs/lab01
gcc -Wall -Wextra lab01.c -o lab01 && ./lab01
```

| # | Function | Description |
|---|---|---|
| 1.1 | `int add(int a, int b)` | Sum of two numbers (warm-up) |
| 1.2 | `int sum_digits(int n)` | Sum of the digits: `sum_digits(1234) = 10`. Handle negative numbers too. |
| 1.3 | `long factorial(int n)` | n! using a **loop** |
| 1.4 | `long fib_recursive(int n)`, `long fib_loop(int n)` | Fibonacci in two ways. Time it with n = 40: `time ./lab01` (temporarily edit main). Explain the difference. |
| 1.5 | `int is_prime(int n)` | Return 1 if n is prime |
| 1.6 | `int gcd(int a, int b)` | Greatest common divisor (Euclid's algorithm) |
| 1.7 | `int is_leap_year(int y)` | Leap year: divisible by 4 and not by 100, or divisible by 400 |
| 1.8 | `int days_in_month(int month, int year)` | **Use `switch`**, grouping `case`s with the same number of days; return 0 for an invalid month |

### Homework

**1.9 — Temperature table** (`lab01/temperature.c`, create it yourself): read `lower`, `upper`, `step` with `scanf` and print a Fahrenheit → Celsius table as in Lecture 1, using `float` and `printf("%3.0f %6.1f\n", ...)`. Validate the input (`step > 0`, `lower <= upper`).

```bash
echo "0 300 20" | ./temperature     # quick test without typing by hand
```

**1.10 — Pocket calculator, top-down design** (`lab01/calculator.c`, create it yourself): based on [`top-down/main.c`](https://github.com/bonigarcia/c-programming/blob/master/top-down/main.c), show the menu `1. Add 2. Subtract 3. Multiply 4. Divide 5. Power 0. Exit` and repeat until the user chooses 0. Each operation is a separate function; division by zero must report an error.

## Submission

- `labs/lab01/lab01.c` (all `PASS`), `temperature.c`, `calculator.c`
- If you use GitHub: commit and push to your fork; otherwise: zip the `lab01` folder and submit it as instructed by your lecturer.

## Further reading

- K&R, chapters 1–3; *Essential C*, sections 1–2
- Example code in this repo: [`lecture01-intro/`](../lecture01-intro), [`lecture02-basic-elements/`](../lecture02-basic-elements)

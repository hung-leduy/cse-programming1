# Programming 1 — Ví dụ lập trình C

Kho mã này tập hợp các chương trình C ngắn đi kèm các bài giảng môn **Programming 1** (Lập trình 1). Cách tổ chức tham khảo từ [bonigarcia/c-programming](https://github.com/bonigarcia/c-programming): mỗi bài giảng là một thư mục, trong đó chia theo chủ đề, và mỗi file `.c` là một chương trình độc lập, có chú thích tiếng Việt.

## Biên dịch và chạy

Yêu cầu: `gcc` và `make` (Linux, WSL, macOS, hoặc GitHub Codespaces).

```bash
make          # biên dịch toàn bộ ví dụ
make clean    # xoá các file đã biên dịch

# hoặc biên dịch từng file
gcc -Wall -g lecture01-intro/hello_world/hello.c -o hello
./hello
```

Các thư mục có `Makefile` riêng là chương trình gồm nhiều file (ví dụ `lecture01-intro/header_files`); chạy `make run` trong thư mục đó.

## Thực hành

Tài liệu cho 4 buổi thực hành (và bài chuẩn bị Lab 0) nằm trong [`labs/`](labs):

- [Lab 0 — Cài đặt môi trường, Linux, SSH, Git/GitHub](labs/lab00-setup.md)
- [Lab 1 — Nền tảng C](labs/lab01-basics.md)
- [Lab 2 — Mảng, chuỗi và debug](labs/lab02-arrays-strings-debug.md)
- [Lab 3 — Con trỏ và bộ nhớ động](labs/lab03-pointers-memory.md)
- [Lab 4 — Struct, con trỏ hàm và chương trình nhiều file](labs/lab04-structs-modules.md)

Repo có sẵn cấu hình `.devcontainer/` để mở bằng GitHub Codespaces (đã cài `gcc`, `gdb`, `make`, `valgrind`).

## Nội dung

### [Lecture 1: Giới thiệu môn học](lecture01-intro)

| Chủ đề | Ví dụ |
|---|---|
| Chương trình "hello, world" | [hello.c](lecture01-intro/hello_world/hello.c) |
| Hàm (định nghĩa, gọi, tái sử dụng) | [print_hello.c](lecture01-intro/functions/print_hello.c) |
| File header, biên dịch nhiều file, compile/link | [header_files/](lecture01-intro/header_files) |
| Biến, vòng lặp while (bảng nhiệt độ) | [fahr_celsius.c](lecture01-intro/variables/fahr_celsius.c), [fahr_celsius_float.c](lecture01-intro/variables/fahr_celsius_float.c) |
| Toán tử số học | [arithmetic.c](lecture01-intro/operators/arithmetic.c) |
| Toán tử tăng/giảm `i++`, `++i` | [increment.c](lecture01-intro/operators/increment.c) |
| Chú thích | [comments.c](lecture01-intro/comments/comments.c) |
| Bài tập: add, giai thừa, Fibonacci (đệ quy và vòng lặp) | [add.c](lecture01-intro/exercises/add.c), [factorial.c](lecture01-intro/exercises/factorial.c), [fibonacci.c](lecture01-intro/exercises/fibonacci.c) |

### [Lecture 2: Các thành phần cơ bản](lecture02-basic-elements)

| Chủ đề | Ví dụ |
|---|---|
| Kích thước các kiểu dữ liệu | [sizeof_types.c](lecture02-basic-elements/types/sizeof_types.c) |
| Khai báo biến, hằng, số hệ 16 | [declare_assign.c](lecture02-basic-elements/types/declare_assign.c) |
| Ép kiểu, mất độ chính xác | [casting.c](lecture02-basic-elements/types/casting.c), [cast_in_function.c](lecture02-basic-elements/types/cast_in_function.c) |
| Toán tử quan hệ và logic | [relational_logical.c](lecture02-basic-elements/operators/relational_logical.c) |
| if / else if / else | [if_else.c](lecture02-basic-elements/control_flow/if_else.c) |
| for, while, do-while | [loops.c](lecture02-basic-elements/control_flow/loops.c) |
| Kiểu `char` và bảng ASCII | [char_ascii.c](lecture02-basic-elements/char/char_ascii.c) |
| Bài tập 1, 2: chuyển ký tự thành số, `atoi` | [convert.c](lecture02-basic-elements/char/convert.c), [my_atoi.c](lecture02-basic-elements/char/my_atoi.c) |

### [Lecture 3: Mảng và con trỏ](lecture03-array-pointer)

| Chủ đề | Ví dụ |
|---|---|
| switch, break, continue | [switch.c](lecture03-array-pointer/control_flow/switch.c), [break_continue.c](lecture03-array-pointer/control_flow/break_continue.c) |
| Mảng 1 chiều, tìm max | [array_1d.c](lecture03-array-pointer/arrays/array_1d.c) |
| Mảng 2 chiều, max theo trục (axis) | [array_2d.c](lecture03-array-pointer/arrays/array_2d.c) |
| Bài tập: tích vô hướng, nhân ma trận, tích chập | [inner_product.c](lecture03-array-pointer/arrays/inner_product.c), [matrix_multiplication.c](lecture03-array-pointer/arrays/matrix_multiplication.c), [convolution.c](lecture03-array-pointer/arrays/convolution.c) |
| Chèn, xoá phần tử trong mảng | [array_insert_delete.c](lecture03-array-pointer/arrays/array_insert_delete.c) |
| Khai báo con trỏ, `&` và `*` | [pointer_basic.c](lecture03-array-pointer/pointers/pointer_basic.c) |
| Con trỏ tới mảng, tên mảng là hằng | [pointer_to_array.c](lecture03-array-pointer/pointers/pointer_to_array.c) |
| Di chuyển con trỏ, quiz `*(++p)` và `*(p++)` | [pointer_arithmetic.c](lecture03-array-pointer/pointers/pointer_arithmetic.c) |
| Truyền tham trị và tham chiếu | [call_by_value_reference.c](lecture03-array-pointer/pointers/call_by_value_reference.c) |
| Con trỏ mảng với hàm (max, đảo mảng, trả về mảng) | [array_functions.c](lecture03-array-pointer/pointers/array_functions.c), [even_odd_bit.c](lecture03-array-pointer/pointers/even_odd_bit.c) |
| `malloc`, `free`, `realloc`, rò rỉ bộ nhớ | [malloc_free.c](lecture03-array-pointer/dynamic_mem/malloc_free.c), [realloc.c](lecture03-array-pointer/dynamic_mem/realloc.c), [memory_leak.c](lecture03-array-pointer/dynamic_mem/memory_leak.c) |
| Phạm vi biến (toàn cục, cục bộ, heap) | [scope.c](lecture03-array-pointer/dynamic_mem/scope.c) |
| Struct, con trỏ tới struct, `->` | [fraction.c](lecture03-array-pointer/structs/fraction.c), [struct_pointer.c](lecture03-array-pointer/structs/struct_pointer.c) |
| Danh sách liên kết (truy cập, chèn, xoá, giải phóng) | [linked_list.c](lecture03-array-pointer/structs/linked_list.c) |
| Cây nhị phân tìm kiếm | [binary_tree.c](lecture03-array-pointer/structs/binary_tree.c) |

### [Lecture 7: Ôn tập](lecture07-review)

| Chủ đề | Ví dụ |
|---|---|
| Cấu hình VS Code: build, debug với gdb | [vscode/](lecture07-review/vscode) |
| Chương trình để thử breakpoint | [sample.c](lecture07-review/multi_array/sample.c) |
| Cấp phát mảng 2 chiều bằng `int **` | [alloc_2d.c](lecture07-review/multi_array/alloc_2d.c) |
| Cấp phát mảng n chiều bằng đệ quy, trả về `void *` | [alloc_nd.c](lecture07-review/multi_array/alloc_nd.c) |

Giải phóng danh sách liên kết và cây nhị phân: xem `free_list` trong [linked_list.c](lecture03-array-pointer/structs/linked_list.c) và `free_tree` trong [binary_tree.c](lecture03-array-pointer/structs/binary_tree.c).

### [Lecture 8: Con trỏ hàm](lecture08-function-pointers)

| Chủ đề | Ví dụ |
|---|---|
| Chỉ số mảng nhiều chiều (`struct MultiArray`, data + shape) | [multi_array.c](lecture08-function-pointers/multi_array/multi_array.c) |
| Chuỗi: `char[]` và `char *`, ký tự `'\0'` | [string_basics.c](lecture08-function-pointers/strings/string_basics.c) |
| `strlen`, `strcmp`, `strcat`, `strcpy`, `strstr` | [string_functions.c](lecture08-function-pointers/strings/string_functions.c) |
| Tự cài đặt các hàm xử lý chuỗi | [my_string.c](lecture08-function-pointers/strings/my_string.c) |
| Con trỏ hàm, mảng con trỏ hàm | [function_pointer.c](lecture08-function-pointers/function_pointers/function_pointer.c) |
| Con trỏ hàm làm tham số (`reduce`, `qsort`) | [reduce.c](lecture08-function-pointers/function_pointers/reduce.c), [qsort_compare.c](lecture08-function-pointers/function_pointers/qsort_compare.c) |
| `typedef` | [typedef.c](lecture08-function-pointers/function_pointers/typedef.c) |
| `#define`: hằng và macro | [define.c](lecture08-function-pointers/preprocessor/define.c) |
| `#ifdef`: Debug / Release, theo hệ điều hành | [debug_release.c](lecture08-function-pointers/preprocessor/debug_release.c), [platform.c](lecture08-function-pointers/preprocessor/platform.c) |
| Nhiều file: prototype và cài đặt, compile và link | [multiple_files/](lecture08-function-pointers/multiple_files) |
| Gọi hàm từ thư viện động (`dlopen`/`dlsym`) | [dynamic_library/](lecture08-function-pointers/dynamic_library) |

## Gợi ý thử nghiệm

```bash
# Bản Debug và Release với #ifdef
gcc -DDEBUG lecture08-function-pointers/preprocessor/debug_release.c -o debug && ./debug
gcc lecture08-function-pointers/preprocessor/debug_release.c -o release && ./release

# Kiểm tra rò rỉ bộ nhớ
cd lecture03-array-pointer/dynamic_mem
gcc -g memory_leak.c -o memory_leak && valgrind --leak-check=full ./memory_leak

# Debug bằng gdb
gcc -g lecture07-review/multi_array/sample.c -o sample && gdb ./sample
```

## Tài liệu tham khảo

- Brian Kernighan, Dennis Ritchie — *The C Programming Language*
- Nick Parlante — [Essential C](https://cs.stanford.edu/people/nick/compdocs/Essential_C.pdf)
- [Harvard CS50x](https://cs50.harvard.edu/x/) và môi trường [cs50.dev](https://cs50.dev/)
- [bonigarcia/c-programming](https://github.com/bonigarcia/c-programming)
- Luyện tập: [LeetCode](https://leetcode.com/) (chủ đề number, array)

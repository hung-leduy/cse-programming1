# Lab 3 — Con trỏ và bộ nhớ động

> **Buổi 3** · Liên quan: Lecture 3 (Pointer, dynamic memory, scope, call by value/reference), Lecture 7 (multi array)
> **Repo tham khảo:** [bonigarcia/c-programming](https://github.com/bonigarcia/c-programming) — thư mục `pointers`, `dynamic_mem`, `valgrind`
> **Code khởi đầu:** [`lab03/lab03.c`](lab03/lab03.c), [`lab03/leaky.c`](lab03/leaky.c)

## Mục tiêu

- Hiểu con trỏ là biến chứa địa chỉ; dùng thành thạo `&`, `*`, `->`, `NULL`.
- Quan hệ giữa mảng và con trỏ; phép toán trên con trỏ (`p + 1`, `*(p++)`, `*(++p)`).
- Truyền tham trị và truyền tham chiếu; trả về nhiều giá trị qua con trỏ.
- Cấp phát và giải phóng bộ nhớ động: `malloc`, `calloc`, `realloc`, `free`.
- Nhận biết và sửa các lỗi bộ nhớ: rò rỉ, con trỏ treo, ghi ngoài vùng nhớ, biến chưa khởi tạo — bằng **valgrind**.

## Phân bổ thời gian gợi ý (≈ 3 giờ)

| Thời gian | Nội dung |
|---|---|
| 0:00 – 0:35 | Phần 1: con trỏ cơ bản, con trỏ và mảng |
| 0:35 – 0:50 | Phần 2: truyền tham trị / tham chiếu |
| 0:50 – 1:20 | Phần 3: bộ nhớ động, phạm vi, con trỏ treo |
| 1:20 – 1:45 | Phần 4: valgrind, sửa `leaky.c` |
| 1:45 – 2:50 | Bài tập 3.1 – 3.9 trong `lab03.c` |
| 2:50 – 3:00 | Chữa bài |

> **Khuyến khích vẽ hình.** Với mỗi ví dụ, vẽ các "ô nhớ" (tên biến, địa chỉ, giá trị) và mũi tên con trỏ. Hầu hết lỗi con trỏ đều lộ ra khi vẽ.

---

## Phần 1. Con trỏ cơ bản (≈ 35 phút)

| File | Câu hỏi |
|---|---|
| [`pointers/basic_pointer_1.c`](https://github.com/bonigarcia/c-programming/blob/master/pointers/basic_pointer_1.c) | Vẽ hình `age` và `p_age`. `%p` in ra gì? |
| [`pointers/basic_pointer_2.c`](https://github.com/bonigarcia/c-programming/blob/master/pointers/basic_pointer_2.c) | Vì sao `*p_age` đổi theo khi gán `age = 40`? Thử ngược lại: gán `*p_age = 60` rồi in `age`. |
| [`pointers/null_pointer_1.c`](https://github.com/bonigarcia/c-programming/blob/master/pointers/null_pointer_1.c) | Thêm `printf("%d", *pointer);`. Chuyện gì xảy ra? (Segmentation fault) |
| [`pointers/arrays_3.c`](https://github.com/bonigarcia/c-programming/blob/master/pointers/arrays_3.c) | In thêm địa chỉ `a`, `b`, `c`, `d`. Các địa chỉ cách nhau bao nhiêu byte? Vì sao? |
| [`pointers/arrays_4.c`](https://github.com/bonigarcia/c-programming/blob/master/pointers/arrays_4.c) | Vì sao `s1 != s2`? Mảng và con trỏ khác nhau ở đâu? |
| [`pointers/arrays_1.c`](https://github.com/bonigarcia/c-programming/blob/master/pointers/arrays_1.c) | Vì sao hàm `double_array` sửa được mảng của `main`? |
| [`pointers/double_pointer_1.c`](https://github.com/bonigarcia/c-programming/blob/master/pointers/double_pointer_1.c), [`double_pointer_2.c`](https://github.com/bonigarcia/c-programming/blob/master/pointers/double_pointer_2.c) | Vẽ hình `age`, `pointer`, `double_pointer`. `words` là mảng gồm những gì? |
| [`pointers/args.c`](https://github.com/bonigarcia/c-programming/blob/master/pointers/args.c) | `char *argv[]` là mảng các con trỏ. Chạy `./args mot hai ba`. |

### Quiz Lecture 3: `*(++p)` và `*(p++)`

Chạy [`lecture03-array-pointer/pointers/pointer_arithmetic.c`](../lecture03-array-pointer/pointers/pointer_arithmetic.c) trong repo môn học. Trước khi chạy, dự đoán nội dung mảng sau mỗi lệnh gán. Giải thích vì sao cuối cùng phải `free(base)` chứ không phải `free(p_scores)`.

---

## Phần 2. Truyền tham trị và tham chiếu (≈ 15 phút)

| File | Câu hỏi |
|---|---|
| [`pointers/pass_by_value.c`](https://github.com/bonigarcia/c-programming/blob/master/pointers/pass_by_value.c) | Vì sao giá trị trong `main` không đổi? |
| [`pointers/pass_by_ref.c`](https://github.com/bonigarcia/c-programming/blob/master/pointers/pass_by_ref.c) | Vẽ hình lúc đang ở trong hàm: tham số trỏ tới đâu? |
| [`pointers/struct_pointer.c`](https://github.com/bonigarcia/c-programming/blob/master/pointers/struct_pointer.c) | `p->x` tương đương với cách viết nào dùng `*`? |

**Mẫu hàm kiểu LeetCode** (Lecture 3): hàm trả về một mảng mới **và** kích thước của nó:

```c
int *evenOddBit(int n, int *returnSize);   // kích thước trả về qua *returnSize
```

Xem [`lecture03-array-pointer/pointers/even_odd_bit.c`](../lecture03-array-pointer/pointers/even_odd_bit.c). Ai chịu trách nhiệm `free` mảng trả về?

---

## Phần 3. Bộ nhớ động (≈ 30 phút)

```
 địa chỉ cao  ┌──────────────┐
              │    stack     │  biến cục bộ, tham số — tự huỷ khi hàm kết thúc
              │      ↓       │
              │      ↑       │
              │     heap     │  malloc/calloc/realloc — tồn tại tới khi free
              ├──────────────┤
              │  data / bss  │  biến toàn cục, biến static
              ├──────────────┤
              │ rodata, text │  chuỗi hằng "Hello", mã lệnh
 địa chỉ thấp └──────────────┘
```

| File | Câu hỏi |
|---|---|
| [`dynamic_mem/memory_segments.c`](https://github.com/bonigarcia/c-programming/blob/master/dynamic_mem/memory_segments.c) | Mỗi biến nằm ở vùng nào? Vì sao `msg2[0] = 'h'` được mà `msg1[0] = 'h'` thì không? |
| [`dynamic_mem/malloc_1.c`](https://github.com/bonigarcia/c-programming/blob/master/dynamic_mem/malloc_1.c), [`malloc_2.c`](https://github.com/bonigarcia/c-programming/blob/master/dynamic_mem/malloc_2.c) | Sửa `FIXME`. Vì sao phải kiểm tra `ptr == NULL`? |
| [`dynamic_mem/malloc_3.c`](https://github.com/bonigarcia/c-programming/blob/master/dynamic_mem/malloc_3.c) | `*(ptr + i)` và `ptr[i]` có giống nhau không? |
| [`dynamic_mem/calloc_1.c`](https://github.com/bonigarcia/c-programming/blob/master/dynamic_mem/calloc_1.c) | `calloc` khác `malloc` ở đâu? |
| [`dynamic_mem/realloc_1.c`](https://github.com/bonigarcia/c-programming/blob/master/dynamic_mem/realloc_1.c) | Địa chỉ trước và sau `realloc` có giống nhau không? Vì sao không được viết `p = realloc(p, ...)` mà không kiểm tra? |
| [`dynamic_mem/double_pointer.c`](https://github.com/bonigarcia/c-programming/blob/master/dynamic_mem/double_pointer.c) | Vì sao phải `free(words[0])` **trước** `free(words)`? |

### Cấp phát trong một hàm khác — bài toán kinh điển

So sánh 4 file, file nào đúng, file nào sai, vì sao:

1. [`out-of-scope-allocation_0.c`](https://github.com/bonigarcia/c-programming/blob/master/dynamic_mem/out-of-scope-allocation_0.c) — cấp phát ngay trong `main`
2. [`out-of-scope-allocation_1.c`](https://github.com/bonigarcia/c-programming/blob/master/dynamic_mem/out-of-scope-allocation_1.c) — `void allocate(int *ptr)`
3. [`out-of-scope-allocation_2.c`](https://github.com/bonigarcia/c-programming/blob/master/dynamic_mem/out-of-scope-allocation_2.c) — `void allocate(int **ptr)`
4. [`out-of-scope-allocation_3.c`](https://github.com/bonigarcia/c-programming/blob/master/dynamic_mem/out-of-scope-allocation_3.c) — `int *allocate()`

> Gợi ý: file 2 mắc đúng lỗi của `swap_by_value` ở Phần 2 — chỉ có điều biến bị "sao chép" lại là một con trỏ.

### Con trỏ treo (dangling pointer)

| File | Câu hỏi |
|---|---|
| [`dynamic_mem/dangling_pointer_1.c`](https://github.com/bonigarcia/c-programming/blob/master/dynamic_mem/dangling_pointer_1.c) | Dùng con trỏ sau khi `free`. Cách phòng tránh? |
| [`dynamic_mem/dangling_pointer_2.c`](https://github.com/bonigarcia/c-programming/blob/master/dynamic_mem/dangling_pointer_2.c) | Trả về địa chỉ biến cục bộ. `-Wall` cảnh báo gì? Sửa bằng 2 cách (`static` / `malloc`). |

---

## Phần 4. Valgrind (≈ 25 phút)

Valgrind chạy chương trình trong môi trường giám sát và báo mọi truy cập bộ nhớ sai. Luôn biên dịch với `-g` để valgrind chỉ ra **số dòng**.

```bash
cd ~/prog1/c-programming/valgrind
gcc -g valgrind_memory_leak.c -o leak
valgrind --leak-check=full ./leak
```

| File | Lỗi | Thông báo valgrind cần tìm |
|---|---|---|
| [`valgrind_memory_leak.c`](https://github.com/bonigarcia/c-programming/blob/master/valgrind/valgrind_memory_leak.c) | Rò rỉ bộ nhớ | `definitely lost: 100 bytes in 1 blocks` |
| [`valgrind_illegal_write.c`](https://github.com/bonigarcia/c-programming/blob/master/valgrind/valgrind_illegal_write.c) | Ghi vào `NULL` | `Invalid write of size 4` |
| [`valgrind_illegal_free.c`](https://github.com/bonigarcia/c-programming/blob/master/valgrind/valgrind_illegal_free.c) | `free` sai địa chỉ / 2 lần | `Invalid free()` |
| [`valgrind_unitialized.c`](https://github.com/bonigarcia/c-programming/blob/master/valgrind/valgrind_unitialized.c) | Đọc biến chưa khởi tạo | `Conditional jump or move depends on uninitialised value(s)` (thêm `--track-origins=yes`) |

**Cách đọc báo cáo:** tìm dòng đầu tiên có tên file của bạn trong stack trace (ví dụ `at 0x...: main (leak.c:12)`). Mục tiêu cuối cùng luôn là:

```
All heap blocks were freed -- no leaks are possible
ERROR SUMMARY: 0 errors from 0 contexts
```

> macOS chip Apple không chạy được valgrind — dùng Codespaces, hoặc thay bằng `gcc -g -fsanitize=address leaky.c` (AddressSanitizer).

### Bài tập: `leaky.c`

File [`lab03/leaky.c`](lab03/leaky.c) chạy "có vẻ đúng" nhưng có **4 lỗi bộ nhớ**. Dùng valgrind để tìm và sửa hết, ghi chú lại vào đầu file.

```bash
cd ~/prog1/cse-programming1/labs/lab03
gcc -Wall -g leaky.c -o leaky
valgrind --leak-check=full --track-origins=yes ./leaky
```

---

## Phần 5. Bài tập

```bash
gcc -Wall -Wextra -g lab03.c -o lab03 && ./lab03
valgrind --leak-check=full ./lab03       # phải sạch: 0 errors, không rò rỉ
```

**Yêu cầu chung:** tất cả `PASS` **và** valgrind không báo lỗi.

| # | Hàm | Mô tả |
|---|---|---|
| 3.1 | `void swap(int *a, int *b)` | Hoán đổi hai số |
| 3.2 | `void min_max(const int *a, int n, int *min, int *max)` | Trả về 2 giá trị qua con trỏ |
| 3.3 | `int sum_pointer(const int *a, int n)` | Tổng mảng, **không được dùng `[]`**, chỉ dùng phép toán con trỏ |
| 3.4 | `int *copy_array(const int *a, int n)` | Trả về bản sao trên heap |
| 3.5 | `int *filter_even(const int *a, int n, int *returnSize)` | Mảng mới chỉ gồm số chẵn (kiểu LeetCode) |
| 3.6 | `char *my_strdup(const char *s)` | Tự cài đặt `strdup` (nhớ chỗ cho `'\0'`!) |
| 3.7 | `int *push_back(int *arr, int *size, int *capacity, int value)` | Mảng động: khi đầy thì `realloc` gấp đôi |
| 3.8 | `int **alloc_matrix(int rows, int cols)`, `void free_matrix(int **m, int rows)` | Mảng 2 chiều bằng `int **` (Lecture 7) |
| 3.9 | `void allocate_int(int **p, int value)` | Cấp phát một `int` trong hàm và "trả" về qua tham số (sửa lỗi `out-of-scope-allocation_1.c`) |

### Bài tập về nhà

- **3.10** `char **split(const char *s, char sep, int *count)`: tách chuỗi thành mảng các chuỗi (mỗi chuỗi cấp phát riêng) và hàm `free_split`. Kiểm tra bằng valgrind.
- **3.11** Cấp phát mảng **n chiều** bằng đệ quy, trả về `void *` (Lecture 7). Tham khảo [`lecture07-review/multi_array/alloc_nd.c`](../lecture07-review/multi_array/alloc_nd.c) rồi tự viết lại hàm giải phóng.
- **3.12** (LeetCode, chú ý `returnSize`) [1480. Running Sum of 1d Array](https://leetcode.com/problems/running-sum-of-1d-array/), [2595. Number of Even and Odd Bits](https://leetcode.com/problems/number-of-even-and-odd-bits/), [977. Squares of a Sorted Array](https://leetcode.com/problems/squares-of-a-sorted-array/).

## Nộp bài

- `labs/lab03/lab03.c`: tất cả `PASS`, valgrind sạch (chụp màn hình phần `HEAP SUMMARY` và `ERROR SUMMARY`)
- `labs/lab03/leaky.c` đã sửa, có ghi chú 4 lỗi

## Tham khảo thêm

- *Essential C*, mục 3 (pointers), mục 6 (heap memory)
- Valgrind Quick Start: https://valgrind.org/docs/manual/quick-start.html
- Code ví dụ: [`lecture03-array-pointer/pointers/`](../lecture03-array-pointer/pointers), [`lecture03-array-pointer/dynamic_mem/`](../lecture03-array-pointer/dynamic_mem)

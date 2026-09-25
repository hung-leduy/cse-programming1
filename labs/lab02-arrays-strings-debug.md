# Lab 2 — Mảng, chuỗi và gỡ lỗi (debug)

> **Buổi 2** · Liên quan: Lecture 3 (Array), Lecture 7 (IDE, debug), Lecture 8 (String, `#ifdef DEBUG`)
> **Repo tham khảo:** [bonigarcia/c-programming](https://github.com/bonigarcia/c-programming) — thư mục `arrays`, `strings`, `debug`
> **Code khởi đầu:** [`lab02/lab02.c`](lab02/lab02.c), [`lab02/buggy.c`](lab02/buggy.c)

## Mục tiêu

- Khai báo, khởi tạo, duyệt mảng 1 chiều và 2 chiều; truyền mảng vào hàm.
- Hiểu chuỗi trong C là mảng `char` kết thúc bằng `'\0'`; dùng các hàm trong `<string.h>`.
- Debug bằng `printf` có điều kiện (`#ifdef DEBUG`), bằng `gdb` và bằng VS Code (breakpoint, step, watch).

## Phân bổ thời gian gợi ý (≈ 3 giờ)

| Thời gian | Nội dung |
|---|---|
| 0:00 – 0:25 | Phần 1: mảng |
| 0:25 – 0:55 | Phần 2: chuỗi |
| 0:55 – 1:35 | Phần 3: debug với `#ifdef`, gdb, VS Code; sửa `buggy.c` |
| 1:35 – 2:45 | Bài tập 2.1 – 2.10 trong `lab02.c` |
| 2:45 – 3:00 | Chữa bài |

---

## Phần 1. Mảng (≈ 25 phút)

| File | Câu hỏi |
|---|---|
| [`arrays/arrays_1.c`](https://github.com/bonigarcia/c-programming/blob/master/arrays/arrays_1.c) | In thêm `array_1[2]` (chưa gán). Kết quả là gì? Có giống nhau mỗi lần chạy không? |
| [`arrays/arrays_3.c`](https://github.com/bonigarcia/c-programming/blob/master/arrays/arrays_3.c) | Vì sao dùng `#define SIZE` thay vì viết số 4 nhiều lần? |
| [`arrays/arrays_4.c`](https://github.com/bonigarcia/c-programming/blob/master/arrays/arrays_4.c) | `sizeof(array) / sizeof(array[0])` tính gì? Biên dịch với `-Wall -Wextra`: cảnh báo gì về `int i` và `size_t size`? |
| [`arrays/arrays_5_error.c`](https://github.com/bonigarcia/c-programming/blob/master/arrays/arrays_5_error.c) → [`arrays_5_fixed.c`](https://github.com/bonigarcia/c-programming/blob/master/arrays/arrays_5_fixed.c) | Vì sao không gán được `array_2 = array_1`? (Lecture 3: "Array names are const") |
| [`arrays/qsort_1.c`](https://github.com/bonigarcia/c-programming/blob/master/arrays/qsort_1.c) | Sửa để sắp xếp **giảm dần**. (Hàm `compare` là một *con trỏ hàm* — sẽ học kỹ ở Lab 4.) |

### Thí nghiệm: `sizeof` khi truyền mảng vào hàm

```c
void f(int a[]) {
    printf("trong hàm: sizeof(a) = %zu\n", sizeof(a));
}
int main() {
    int a[10];
    printf("trong main: sizeof(a) = %zu\n", sizeof(a));
    f(a);
}
```

Hai giá trị có bằng nhau không? Từ đó giải thích vì sao hàm nhận mảng **luôn cần thêm tham số kích thước** `n` (Lecture 3: `get_max_1d_array(int a[], int N)`).

### Mảng 2 chiều

Chạy [`lecture03-array-pointer/arrays/array_2d.c`](../lecture03-array-pointer/arrays/array_2d.c) trong repo môn học. Vẽ ra giấy cách mảng `int a[3][4]` được lưu **liên tiếp** trong bộ nhớ (theo hàng). Vì sao khai báo tham số phải là `int a[][4]` mà không được là `int a[][]`?

---

## Phần 2. Chuỗi (≈ 30 phút)

| File | Câu hỏi |
|---|---|
| [`strings/basic_string_1.c`](https://github.com/bonigarcia/c-programming/blob/master/strings/basic_string_1.c), [`_2.c`](https://github.com/bonigarcia/c-programming/blob/master/strings/basic_string_2.c), [`_4.c`](https://github.com/bonigarcia/c-programming/blob/master/strings/basic_string_4.c) | Ba cách khai báo giống nhau ở điểm nào? Xoá `'\0'` trong `_2.c` thì sao? |
| [`strings/basic_string_3.c`](https://github.com/bonigarcia/c-programming/blob/master/strings/basic_string_3.c) | Thêm `greetings[0] = 'h';`. Chương trình bị gì? So sánh `char s[]` với `char *s` (Lecture 8). |
| [`strings/error_string.c`](https://github.com/bonigarcia/c-programming/blob/master/strings/error_string.c) | Vì sao lỗi? Sửa bằng `strcpy`. |
| [`strings/strlen_3.c`](https://github.com/bonigarcia/c-programming/blob/master/strings/strlen_3.c) | `strlen` khác `sizeof` thế nào? |
| [`strings/strcpy_2.c`](https://github.com/bonigarcia/c-programming/blob/master/strings/strcpy_2.c), [`strcat.c`](https://github.com/bonigarcia/c-programming/blob/master/strings/strcat.c) | Điều gì xảy ra nếu mảng đích quá nhỏ? Vì sao nên dùng `strncpy`/`strncat`/`snprintf`? |
| [`strings/strcmp_1.c`](https://github.com/bonigarcia/c-programming/blob/master/strings/strcmp_1.c) … [`strcmp_3.c`](https://github.com/bonigarcia/c-programming/blob/master/strings/strcmp_3.c) | Vì sao **không** so sánh chuỗi bằng `str1 == str2`? |
| [`strings/strtok_1.c`](https://github.com/bonigarcia/c-programming/blob/master/strings/strtok_1.c) | Tách câu `"C,is;fun"` theo cả `,` và `;`. In `str` sau khi tách: điều gì đã xảy ra với chuỗi gốc? |
| [`strings/memset_1.c`](https://github.com/bonigarcia/c-programming/blob/master/strings/memset_1.c) | `memset` dùng để làm gì? |

**Nhắc lại ASCII (Lecture 2):** `'a' - 'A' == 32`, `'7' - '0' == 7`. Các bài tập chuỗi bên dưới dùng nhiều mẹo này.

---

## Phần 3. Gỡ lỗi (≈ 40 phút)

### 3.1. `printf` có điều kiện với `#ifdef DEBUG`

Ví dụ: [`debug/debug_1.c`](https://github.com/bonigarcia/c-programming/blob/master/debug/debug_1.c), [`debug_2.c`](https://github.com/bonigarcia/c-programming/blob/master/debug/debug_2.c), [`debug_3.c`](https://github.com/bonigarcia/c-programming/blob/master/debug/debug_3.c)

```bash
cd ~/prog1/c-programming/debug
gcc -Wall debug_3.c -o debug_3 && ./debug_3              # bản Release
gcc -Wall -DDEBUG debug_3.c -o debug_3 && ./debug_3      # bản Debug
./debug_3 2> /dev/null                                   # bỏ luồng stderr: chỉ còn gì?
```

**Câu hỏi:** Cờ `-DDEBUG` làm gì? Vì sao in thông tin debug ra `stderr` thay vì `stdout`?

### 3.2. gdb

Ví dụ: [`debug/debug_gdb.c`](https://github.com/bonigarcia/c-programming/blob/master/debug/debug_gdb.c) — chương trình có lỗi, chạy thử và tìm xem sai ở đâu.

```bash
gcc -Wall -g debug_gdb.c -o debug_gdb    # -g: thêm thông tin debug
gdb ./debug_gdb
```

| Lệnh gdb | Ý nghĩa |
|---|---|
| `break printArray` / `b 5` | Đặt breakpoint tại hàm / dòng 5 |
| `run` / `r` | Chạy chương trình |
| `next` / `n` | Chạy dòng tiếp theo (không đi vào hàm) |
| `step` / `s` | Chạy dòng tiếp theo (đi vào hàm) |
| `continue` / `c` | Chạy tới breakpoint tiếp theo |
| `print i` / `p arr[i]` | In giá trị biểu thức |
| `p *arr@size` | In `size` phần tử của mảng mà `arr` trỏ tới |
| `display i` | Tự in `i` sau mỗi bước |
| `info locals` | In các biến cục bộ |
| `backtrace` / `bt` | Xem chuỗi lời gọi hàm (hữu ích khi bị `Segmentation fault`) |
| `quit` / `q` | Thoát |

Bài làm: đặt breakpoint trong `printArray`, dùng `display i` và `next` cho tới khi thấy lỗi. Sửa lỗi.

### 3.3. VS Code

Chép `tasks.json` và `launch.json` từ [`lecture07-review/vscode/`](../lecture07-review/vscode) vào thư mục `.vscode/`. Mở `debug_gdb.c`, đặt breakpoint (click trái số dòng), nhấn **F5**. Dùng:

- Panel **Variables** và **Watch** (thêm biểu thức `arr[i]`, `*arr@5`).
- Thanh công cụ: Continue (F5), Step Over (F10), Step Into (F11), Step Out (Shift+F11).
- **Debug Console**: gõ `-exec p i` hoặc biểu thức bất kỳ.

### 3.4. Bài tập debug: `buggy.c`

File [`lab02/buggy.c`](lab02/buggy.c) biên dịch được nhưng cho **kết quả sai**. Có **4 lỗi**. Chỉ được dùng gdb hoặc VS Code (không thêm `printf`) để tìm. Với mỗi lỗi, ghi vào phần chú thích đầu file: dòng nào, triệu chứng gì, sửa thế nào.

```bash
cd ~/prog1/cse-programming1/labs/lab02
gcc -Wall -g buggy.c -o buggy && ./buggy
```

Kết quả đúng mong đợi:

```
sum = 151
average = 30.20
max = 51
max temp = -1
reversed: olleh
```

---

## Phần 4. Bài tập

```bash
cd ~/prog1/cse-programming1/labs/lab02
gcc -Wall -Wextra -g lab02.c -o lab02 && ./lab02
```

**Mảng**

| # | Hàm | Mô tả |
|---|---|---|
| 2.1 | `int array_max(int a[], int n)` | Giá trị lớn nhất |
| 2.2 | `double array_mean(int a[], int n)` | Trung bình cộng (cẩn thận chia nguyên!) |
| 2.3 | `void reverse_array(int a[], int n)` | Đảo ngược tại chỗ |
| 2.4 | `int count_value(int a[], int n, int value)` | Số lần xuất hiện của `value` |
| 2.5 | `void max_2d(int a[][COLS], int rows, int axis, int out[])` | Max theo trục như numpy (Lecture 3): `axis = 0` theo cột, `axis = 1` theo hàng |
| 2.6 | `void matmul(...)` | Nhân ma trận `A[2][3] x B[3][2]` (Lecture 3) |

**Chuỗi** (không dùng `<string.h>` cho 2.7)

| # | Hàm | Mô tả |
|---|---|---|
| 2.7 | `int my_strlen(const char s[])` | Tự cài đặt `strlen` |
| 2.8 | `void to_upper(char s[])` | Đổi chữ thường thành chữ hoa, giữ nguyên ký tự khác |
| 2.9 | `int is_palindrome(const char s[])` | Chuỗi đối xứng? (`"racecar"` → 1) |
| 2.10 | `int count_words(const char s[])` | Đếm số từ, các từ cách nhau bởi một hoặc nhiều dấu cách |

### Bài tập về nhà

- **2.11** `int my_atoi(const char s[])`: như `atoi`, hỗ trợ dấu `+`/`-` ở đầu (Lecture 2, bài tập 2).
- **2.12** Viết chương trình đọc một dòng bằng `fgets`, in ra số lần xuất hiện của mỗi chữ cái `a`–`z` (không phân biệt hoa thường). Gợi ý: mảng `int count[26]`, chỉ số là `c - 'a'`.
- **2.13** (LeetCode) [1. Two Sum](https://leetcode.com/problems/two-sum/) (chỉ dùng mảng, O(n²) là đủ), [344. Reverse String](https://leetcode.com/problems/reverse-string/), [58. Length of Last Word](https://leetcode.com/problems/length-of-last-word/).

## Nộp bài

- `labs/lab02/lab02.c` (tất cả `PASS`)
- `labs/lab02/buggy.c` đã sửa, có chú thích 4 lỗi

## Tham khảo thêm

- *Essential C*, mục 3 (Complex data types: arrays), mục 6 (strings)
- K&R, chương 1.6–1.9, 5.5
- GDB cheat sheet: https://darkdust.net/files/GDB%20Cheat%20Sheet.pdf

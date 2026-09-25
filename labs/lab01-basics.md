# Lab 1 — Nền tảng C: biên dịch, kiểu dữ liệu, toán tử, rẽ nhánh, vòng lặp, hàm

> **Buổi 1** · Liên quan: Lecture 1 (Course introduction), Lecture 2 (Basic elements)
> **Repo tham khảo:** [bonigarcia/c-programming](https://github.com/bonigarcia/c-programming) — thư mục `hello_world`, `types`, `variables`, `operators`, `boolean`, `control_flow`, `functions`, `io`, `top-down`
> **Code khởi đầu:** [`lab01/lab01.c`](lab01/lab01.c)

## Mục tiêu

- Hiểu 4 bước biên dịch: tiền xử lý → biên dịch → hợp dịch → liên kết.
- Nắm kích thước, phạm vi, ép kiểu của các kiểu dữ liệu cơ bản.
- Dùng đúng toán tử số học, quan hệ, logic, `++`/`--`, toán tử 3 ngôi.
- Viết được `if/else`, `switch`, `for`, `while`, `do-while`, `break`, `continue`.
- Tách bài toán thành các hàm nhỏ (chia để trị, thiết kế top-down).
- Đọc dữ liệu từ bàn phím bằng `scanf`, nhận tham số dòng lệnh `argc/argv`.

## Phân bổ thời gian gợi ý (≈ 3 giờ)

| Thời gian | Nội dung |
|---|---|
| 0:00 – 0:30 | Kiểm tra Lab 0, clone repo, Phần 1 (quá trình biên dịch) |
| 0:30 – 1:00 | Phần 2 (kiểu dữ liệu), Phần 3 (toán tử) |
| 1:00 – 1:30 | Phần 4 (điều khiển), Phần 5 (hàm, phạm vi biến) |
| 1:30 – 2:45 | Bài tập 1.1 – 1.8 trong `lab01.c` |
| 2:45 – 3:00 | Chữa bài, giới thiệu bài tập về nhà 1.9, 1.10 |

## Chuẩn bị

```bash
cd ~/prog1
git clone https://github.com/bonigarcia/c-programming.git   # nếu chưa có
cd c-programming
```

> **Quy tắc cho cả buổi:** trước khi chạy mỗi ví dụ, **dự đoán kết quả** và ghi ra giấy. Sau khi chạy, so sánh và giải thích chỗ khác biệt.
> Luôn biên dịch với `-Wall` và **đọc hết cảnh báo** — cảnh báo thường là lỗi thật.

---

## Phần 1. Quá trình biên dịch (≈ 20 phút)

Ví dụ: [`hello_world/hello_macro.c`](https://github.com/bonigarcia/c-programming/blob/master/hello_world/hello_macro.c)

```bash
cd hello_world
gcc -E hello_macro.c -o hello_macro.i   # 1. tiền xử lý: xử lý #include, #define
gcc -S hello_macro.i -o hello_macro.s   # 2. biên dịch: C -> hợp ngữ (assembly)
gcc -c hello_macro.s -o hello_macro.o   # 3. hợp dịch: assembly -> mã máy
gcc hello_macro.o -o hello_macro        # 4. liên kết: + thư viện chuẩn -> file thực thi
./hello_macro
```

**Câu hỏi:**

1. Mở `hello_macro.i` (dùng `tail -n 20`). Dòng `return OK;` đã trở thành gì? Vì sao file `.i` dài hàng trăm dòng?
2. Mở `hello_macro.s`, tìm dòng gọi `printf` (hoặc `puts`). Vì sao trình biên dịch có thể thay `printf` bằng `puts`?
3. Chạy `ls -l hello_macro.o hello_macro`. Vì sao file thực thi lớn hơn file `.o`?

### Tham số dòng lệnh

Ví dụ: [`hello_world/hello_args.c`](https://github.com/bonigarcia/c-programming/blob/master/hello_world/hello_args.c)

```bash
gcc -Wall hello_args.c -o hello_args
./hello_args
./hello_args An
./hello_args "Nguyen Van An"
echo $?        # mã trả về (return) của chương trình vừa chạy
```

**Câu hỏi:** `argc` bằng bao nhiêu trong mỗi lần chạy? `argv[0]` là gì? Vì sao chương trình dùng `fprintf(stderr, ...)` và `return 1` khi thiếu tham số?

---

## Phần 2. Kiểu dữ liệu (≈ 15 phút)

| File | Dự đoán / Câu hỏi |
|---|---|
| [`types/sizeof_1.c`](https://github.com/bonigarcia/c-programming/blob/master/types/sizeof_1.c), [`sizeof_2.c`](https://github.com/bonigarcia/c-programming/blob/master/types/sizeof_2.c) | So sánh với bảng "short ≤ int ≤ long" trong Lecture 2. `long` trên máy bạn là 4 hay 8 byte? |
| [`types/ranges.c`](https://github.com/bonigarcia/c-programming/blob/master/types/ranges.c) | Giá trị lớn nhất của `int`? Điều gì xảy ra khi cộng 1 vào `INT_MAX`? (tự viết thử) |
| [`types/casting.c`](https://github.com/bonigarcia/c-programming/blob/master/types/casting.c) | Khi nào phải ép kiểu tường minh để không mất phần thập phân? |
| [`types/promotion_1.c`](https://github.com/bonigarcia/c-programming/blob/master/types/promotion_1.c), [`promotion_2.c`](https://github.com/bonigarcia/c-programming/blob/master/types/promotion_2.c) | `1 + 'A'` bằng bao nhiêu? `char c = 65` in ra `%c` là gì? |
| [`boolean/bool_1.c`](https://github.com/bonigarcia/c-programming/blob/master/boolean/bool_1.c) | `true`/`false` thực chất là số mấy? |

**Thử thêm** (ví dụ trong Lecture 2):

```c
char variable = 'a';
float v1 = variable / 5;          // = ?
float v2 = (float)variable / 5;   // = ?
```

---

## Phần 3. Toán tử (≈ 15 phút)

| File | Dự đoán / Câu hỏi |
|---|---|
| [`operators/aritmetic.c`](https://github.com/bonigarcia/c-programming/blob/master/operators/aritmetic.c) | `7 / 2`, `7 % 2`, `7.0 / 2` bằng bao nhiêu? |
| [`operators/relational.c`](https://github.com/bonigarcia/c-programming/blob/master/operators/relational.c), [`logical.c`](https://github.com/bonigarcia/c-programming/blob/master/operators/logical.c) | Kết quả của phép so sánh có kiểu gì? |
| [`operators/ternary.c`](https://github.com/bonigarcia/c-programming/blob/master/operators/ternary.c) | Viết lại bằng `if/else`. |
| [`operators/bitwise.c`](https://github.com/bonigarcia/c-programming/blob/master/operators/bitwise.c) | (Nâng cao) `x & 1` dùng để làm gì? |

**Quiz `++`** (Lecture 1) — dự đoán rồi kiểm tra:

```c
int i = 42;
int j = (i++ + 10);   // j = ?, i = ?
int k = (++i + 10);   // k = ?, i = ?
```

**Lỗi hay gặp:** viết `if (x = 5)` thay vì `if (x == 5)`. Thử biên dịch với `-Wall` và đọc cảnh báo.

---

## Phần 4. Cấu trúc điều khiển (≈ 15 phút)

Chạy và đọc: [`control_flow/for.c`](https://github.com/bonigarcia/c-programming/blob/master/control_flow/for.c), [`break.c`](https://github.com/bonigarcia/c-programming/blob/master/control_flow/break.c), [`continue.c`](https://github.com/bonigarcia/c-programming/blob/master/control_flow/continue.c), [`switch.c`](https://github.com/bonigarcia/c-programming/blob/master/control_flow/switch.c)

**Câu hỏi:**

1. Trong `switch.c`, xoá một lệnh `break`. Chương trình in ra gì? Hiện tượng này gọi là gì (fall-through)? Khi nào ta *cố ý* dùng nó (gợi ý: gộp `case 3:` và `case 4:` trong Lecture 3)?
2. `switch.c` đã gộp các tháng có cùng số ngày — bài tập 1.8 sẽ mở rộng để xử lý năm nhuận.
3. Viết lại vòng `for` trong `for.c` bằng `while` và bằng `do-while`. Khác biệt của `do-while` là gì?

---

## Phần 5. Hàm và phạm vi biến (≈ 15 phút)

| File | Câu hỏi |
|---|---|
| [`functions/functions_1.c`](https://github.com/bonigarcia/c-programming/blob/master/functions/functions_1.c) | Hàm định nghĩa trước `main` |
| [`functions/functions_2.c`](https://github.com/bonigarcia/c-programming/blob/master/functions/functions_2.c) | Biên dịch với `-Wall`: cảnh báo gì (gcc ≥ 14 báo **lỗi**)? Vì sao? |
| [`functions/functions_3.c`](https://github.com/bonigarcia/c-programming/blob/master/functions/functions_3.c) | Khai báo (prototype) sửa lỗi trên thế nào? Liên hệ với file header `.h` trong Lecture 1. |
| [`variables/scopes_1.c`](https://github.com/bonigarcia/c-programming/blob/master/variables/scopes_1.c) | Vì sao không biên dịch được? Sửa lại. |
| [`variables/static.c`](https://github.com/bonigarcia/c-programming/blob/master/variables/static.c) | Dự đoán 10 dòng in ra. `static` khác biến cục bộ thường ở đâu? |
| [`io/scanf_1.c`](https://github.com/bonigarcia/c-programming/blob/master/io/scanf_1.c) | Nhập `Nguyen Van An`. Vì sao chỉ in ra `Nguyen`? |
| [`top-down/main.c`](https://github.com/bonigarcia/c-programming/blob/master/top-down/main.c) | Thiết kế top-down: viết `main` với các hàm "rỗng" trước, cài đặt chi tiết sau. |

---

## Phần 6. Bài tập

Mở [`lab01/lab01.c`](lab01/lab01.c). File đã có sẵn khung các hàm (đánh dấu `TODO`) và hàm `main` tự kiểm tra. Nhiệm vụ: cài đặt các hàm cho đến khi tất cả dòng đều `PASS`.

```bash
cd ~/prog1/cse-programming1/labs/lab01
gcc -Wall -Wextra lab01.c -o lab01 && ./lab01
```

| # | Hàm | Mô tả |
|---|---|---|
| 1.1 | `int add(int a, int b)` | Tổng hai số (khởi động) |
| 1.2 | `int sum_digits(int n)` | Tổng các chữ số: `sum_digits(1234) = 10`. Xử lý cả số âm. |
| 1.3 | `long factorial(int n)` | n! bằng **vòng lặp** |
| 1.4 | `long fib_recursive(int n)`, `long fib_loop(int n)` | Fibonacci hai cách. Đo thời gian với n = 40: `time ./lab01` (tạm sửa main). Giải thích. |
| 1.5 | `int is_prime(int n)` | Trả về 1 nếu n là số nguyên tố |
| 1.6 | `int gcd(int a, int b)` | Ước chung lớn nhất (thuật toán Euclid) |
| 1.7 | `int is_leap_year(int y)` | Năm nhuận: chia hết cho 4 và không chia hết cho 100, hoặc chia hết cho 400 |
| 1.8 | `int days_in_month(int month, int year)` | **Dùng `switch`**, gộp các `case` cùng số ngày; trả về 0 nếu tháng không hợp lệ |

### Bài tập về nhà

**1.9 — Bảng nhiệt độ** (`lab01/temperature.c`, tự tạo): đọc `lower`, `upper`, `step` bằng `scanf`, in bảng Fahrenheit → Celsius như Lecture 1, dùng `float` và `printf("%3.0f %6.1f\n", ...)`. Kiểm tra dữ liệu nhập hợp lệ (`step > 0`, `lower <= upper`).

```bash
echo "0 300 20" | ./temperature     # test nhanh không cần gõ tay
```

**1.10 — Máy tính bỏ túi, thiết kế top-down** (`lab01/calculator.c`, tự tạo): dựa theo [`top-down/main.c`](https://github.com/bonigarcia/c-programming/blob/master/top-down/main.c), hiện menu `1. Cộng 2. Trừ 3. Nhân 4. Chia 5. Luỹ thừa 0. Thoát`, lặp tới khi chọn 0. Mỗi chức năng là một hàm riêng; chia cho 0 phải báo lỗi.

## Nộp bài

- `labs/lab01/lab01.c` (tất cả `PASS`), `temperature.c`, `calculator.c`
- Nếu dùng GitHub: commit và push lên bản fork; nếu không: nén thư mục `lab01` và nộp theo hướng dẫn của giảng viên.

## Tham khảo thêm

- K&R, chương 1–3; *Essential C*, mục 1–2
- Code ví dụ trong repo: [`lecture01-intro/`](../lecture01-intro), [`lecture02-basic-elements/`](../lecture02-basic-elements)

# Thực hành Programming 1

4 buổi thực hành, mỗi buổi khoảng 3 giờ, cộng một bài chuẩn bị (Lab 0) sinh viên tự làm trước buổi 1.
Mỗi bài đọc và chạy ví dụ trong [bonigarcia/c-programming](https://github.com/bonigarcia/c-programming), sau đó làm bài tập trong file code khởi đầu có **test tự chấm** (in `PASS`/`FAIL`).

| Bài | Buổi | Nội dung | Lecture | Thư mục trong bonigarcia/c-programming | Code khởi đầu |
|---|---|---|---|---|---|
| [Lab 0 — Cài đặt môi trường](lab00-setup.md) | Tự học trước buổi 1 | Codespaces/WSL/Linux/macOS, `gcc`, lệnh Linux, SSH, `scp`, Git/GitHub (không bắt buộc) | 1, 7 | — | — |
| [Lab 1 — Nền tảng C](lab01-basics.md) | 1 | Quá trình biên dịch, `argc/argv`, kiểu dữ liệu, ép kiểu, toán tử, rẽ nhánh, vòng lặp, hàm, phạm vi biến, top-down | 1, 2 | `hello_world`, `types`, `variables`, `operators`, `boolean`, `control_flow`, `functions`, `top-down` | [`lab01/`](lab01) |
| [Lab 2 — Mảng, chuỗi, debug](lab02-arrays-strings-debug.md) | 2 | Mảng 1–2 chiều, chuỗi và `<string.h>`, `#ifdef DEBUG`, gdb, debug trong VS Code | 3, 7, 8 | `arrays`, `strings`, `debug` | [`lab02/`](lab02) |
| [Lab 3 — Con trỏ và bộ nhớ động](lab03-pointers-memory.md) | 3 | Con trỏ, con trỏ và mảng, tham trị/tham chiếu, `malloc/calloc/realloc/free`, con trỏ treo, valgrind | 3, 7 | `pointers`, `dynamic_mem`, `valgrind` | [`lab03/`](lab03) |
| [Lab 4 — Struct, con trỏ hàm, nhiều file](lab04-structs-modules.md) | 4 | `struct`, `typedef`, `enum`, danh sách liên kết, con trỏ hàm, `qsort`, header, Makefile, `extern`, tiền xử lý | 3, 7, 8 | `structured_data`, `types`, `pointers`, `dynamic_mem`, `modules` | [`lab04/`](lab04) |

## Cấu trúc mỗi bài

1. **Mục tiêu** và **phân bổ thời gian** gợi ý.
2. **Phần hướng dẫn:** bảng các file ví dụ kèm câu hỏi "dự đoán trước khi chạy".
3. **Bài tập trên lớp:** cài đặt các hàm `TODO` trong code khởi đầu cho tới khi tất cả `PASS`.
4. **Bài tập về nhà** (bao gồm một số bài LeetCode) và **yêu cầu nộp bài**.

## Chuẩn bị cho sinh viên

```bash
mkdir -p ~/prog1 && cd ~/prog1
git clone https://github.com/bonigarcia/c-programming.git
git clone <link bản fork repo môn học>      # hoặc tải ZIP
```

## Chạy code khởi đầu

```bash
cd labs/lab01 && gcc -Wall -Wextra lab01.c -o lab01 && ./lab01
cd labs/lab02 && gcc -Wall -Wextra -g lab02.c -o lab02 && ./lab02
cd labs/lab03 && gcc -Wall -Wextra -g lab03.c -o lab03 && ./lab03 && valgrind --leak-check=full ./lab03
cd labs/lab04 && make test && make valgrind
```

Hàm `main` trả về 0 khi tất cả `PASS`, nên có thể dùng để chấm tự động (ví dụ `./lab01 && echo OK`).

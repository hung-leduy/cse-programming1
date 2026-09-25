# Lab 4 — Struct, danh sách liên kết, con trỏ hàm và chương trình nhiều file

> **Buổi 4** · Liên quan: Lecture 3 (Structure, linked list), Lecture 7 (giải phóng linked list), Lecture 8 (function pointer, typedef, preprocessor, compiling/linking, multiple files)
> **Repo tham khảo:** [bonigarcia/c-programming](https://github.com/bonigarcia/c-programming) — thư mục `structured_data`, `types` (typedef, enum), `pointers` (function pointer), `dynamic_mem/linked_list.c`, `modules`, `debug`
> **Code khởi đầu:** [`lab04/`](lab04) — `student.h`, `student.c`, `test_student.c`, `Makefile`

## Mục tiêu

- Định nghĩa và dùng `struct`, `typedef`, `enum`; truy cập bằng `.` và `->`.
- Cài đặt danh sách liên kết đơn: thêm, tìm, xoá, giải phóng.
- Dùng con trỏ hàm: truyền hàm làm tham số (`qsort`, `count_if`), `typedef` cho con trỏ hàm.
- Tổ chức chương trình thành nhiều file (`.h` khai báo, `.c` cài đặt), biên dịch riêng và liên kết bằng `Makefile`.
- Dùng tiền xử lý: include guard, `#define`, `#ifdef DEBUG`.

## Phân bổ thời gian gợi ý (≈ 3 giờ)

| Thời gian | Nội dung |
|---|---|
| 0:00 – 0:20 | Phần 1: struct, typedef, enum, union |
| 0:20 – 0:40 | Phần 2: con trỏ hàm |
| 0:40 – 1:05 | Phần 3: chương trình nhiều file, Makefile |
| 1:05 – 2:45 | Phần 4: mini-project quản lý sinh viên (4.1 – 4.3) |
| 2:45 – 3:00 | Chữa bài, giới thiệu bài tập về nhà |

---

## Phần 1. Struct, typedef, enum (≈ 20 phút)

| File | Câu hỏi |
|---|---|
| [`structured_data/struct_1.c`](https://github.com/bonigarcia/c-programming/blob/master/structured_data/struct_1.c) | Khai báo và truy cập bằng `.` |
| [`structured_data/struct_2.c`](https://github.com/bonigarcia/c-programming/blob/master/structured_data/struct_2.c) | `typedef struct {...} my_structure;` giúp gì? |
| [`types/typedef.c`](https://github.com/bonigarcia/c-programming/blob/master/types/typedef.c) | `typedef` cho kiểu cơ bản |
| [`types/enums.c`](https://github.com/bonigarcia/c-programming/blob/master/types/enums.c) | Giá trị của `SATURDAY` là bao nhiêu? Vì sao dùng `enum` thay vì số? |
| [`structured_data/union_1.c`](https://github.com/bonigarcia/c-programming/blob/master/structured_data/union_1.c) | (Tham khảo) Vì sao `salary` bị hỏng? So sánh `sizeof` của `union` và `struct` cùng thành phần. |
| [`pointers/struct_pointer.c`](https://github.com/bonigarcia/c-programming/blob/master/pointers/struct_pointer.c), [`dynamic_mem/malloc_4.c`](https://github.com/bonigarcia/c-programming/blob/master/dynamic_mem/malloc_4.c) | `(*p).a` và `p->a` (Lecture 3). Cấp phát struct trên heap. |

**Thí nghiệm:** in `sizeof(struct my_struct)` trong `struct_1.c`. Kết quả có bằng `sizeof(int) + sizeof(char)` không? (Tìm hiểu *padding*.)

**Truyền struct vào hàm:** `void f(Student s)` sao chép toàn bộ struct; `void f(const Student *s)` chỉ truyền địa chỉ (8 byte). Khi nào dùng cách nào?

### Danh sách liên kết

Đọc [`dynamic_mem/linked_list.c`](https://github.com/bonigarcia/c-programming/blob/master/dynamic_mem/linked_list.c) và [`lecture03-array-pointer/structs/linked_list.c`](../lecture03-array-pointer/structs/linked_list.c). Vẽ hình danh sách `1 → 2 → 3 → NULL` và các bước khi:

1. Thêm vào đầu. 2. Thêm vào cuối. 3. Xoá nút ở giữa. 4. Giải phóng toàn bộ (vì sao phải lưu `next` trước khi `free`?)

---

## Phần 2. Con trỏ hàm (≈ 20 phút)

| File | Câu hỏi |
|---|---|
| [`pointers/function_pointer_1.c`](https://github.com/bonigarcia/c-programming/blob/master/pointers/function_pointer_1.c) | Đọc kiểu `int (*func_ptr)(int, int)`: "func_ptr là con trỏ tới hàm nhận (int, int), trả về int". |
| [`pointers/function_pointer_2.c`](https://github.com/bonigarcia/c-programming/blob/master/pointers/function_pointer_2.c) | Máy tính dùng `switch` để **chọn hàm**, rồi gọi một lần. Viết lại bằng **mảng con trỏ hàm** `operations[option - 1]`, bỏ hẳn `switch`. |
| [`arrays/qsort_1.c`](https://github.com/bonigarcia/c-programming/blob/master/arrays/qsort_1.c) | `qsort` không biết kiểu phần tử — nó gọi lại hàm `compare` của ta. Vì sao tham số là `const void *`? |

Tham khảo thêm trong repo môn học: [`reduce.c`](../lecture08-function-pointers/function_pointers/reduce.c) (Lecture 8: `int reduce(int **arr, int N, int M, int (*func)(int, int))`) và [`typedef.c`](../lecture08-function-pointers/function_pointers/typedef.c) (`typedef int (*fp)(int, int);`).

---

## Phần 3. Chương trình nhiều file và Makefile (≈ 25 phút)

Repo tham khảo có 4 phiên bản [`modules/`](https://github.com/bonigarcia/c-programming/tree/master/modules) tăng dần độ phức tạp:

| Thư mục | Nội dung mới |
|---|---|
| [`program.c`](https://github.com/bonigarcia/c-programming/blob/master/modules/program.c) | Tất cả trong một file |
| [`mod1`](https://github.com/bonigarcia/c-programming/tree/master/modules/mod1) | Tách `person.h` (khai báo) và `person.c` (cài đặt); Makefile compile từng file `.o` rồi link |
| [`mod2`](https://github.com/bonigarcia/c-programming/tree/master/modules/mod2) | Thêm module `job` dùng lại `person` |
| [`mod3`](https://github.com/bonigarcia/c-programming/tree/master/modules/mod3) | Biến toàn cục dùng chung giữa các file: `extern` |
| [`mod4`](https://github.com/bonigarcia/c-programming/tree/master/modules/mod4) | Macro `debug` bật/tắt bằng `-DDEBUG` |

```bash
cd ~/prog1/c-programming/modules/mod1
make compile && ./main
make clean
```

**Câu hỏi:**

1. Mở `person.h`: `#ifndef PERSON_H / #define PERSON_H / #endif` để làm gì? Thử xoá đi trong `mod2` (nơi `person.h` được include 2 lần gián tiếp) — lỗi gì?
2. Makefile của `mod1` luôn biên dịch lại mọi file. Nếu chỉ sửa `person.c`, về nguyên tắc có cần biên dịch lại `main.c` không? So sánh với `lab04/Makefile` (dùng quy tắc phụ thuộc): sửa `student.c` rồi chạy `make test` hai lần, xem lệnh nào được chạy lại.
3. Chạy `nm person.o` và `nm main.o`. Ký hiệu `T` và `U` nghĩa là gì? Lỗi `undefined reference to 'sum_ages'` xảy ra ở bước compile hay link?
4. Trong `mod3`, từ khoá `extern Job company[];` khai báo gì? Biến thật sự được định nghĩa ở file nào?

### Makefile cơ bản

```make
test_student: test_student.o student.o     # đích: các phụ thuộc
	$(CC) $(CFLAGS) $^ -o $@                # lệnh (bắt đầu bằng TAB, không phải dấu cách!)

%.o: %.c student.h                         # quy tắc mẫu: .c -> .o
	$(CC) $(CFLAGS) -c $< -o $@
```

`$@` = tên đích, `$<` = phụ thuộc đầu tiên, `$^` = tất cả phụ thuộc. `make` chỉ biên dịch lại những file **mới thay đổi**.

---

## Phần 4. Mini-project: quản lý sinh viên

Thư mục [`lab04/`](lab04):

| File | Vai trò |
|---|---|
| [`student.h`](lab04/student.h) | **Khai báo** (đã hoàn chỉnh): `Student`, `Node`, kiểu con trỏ hàm, macro `DEBUG_PRINT`, prototype |
| [`student.c`](lab04/student.c) | **Cài đặt** — sinh viên làm các `TODO` ở đây |
| [`test_student.c`](lab04/test_student.c) | Chương trình kiểm tra (không sửa) |
| [`Makefile`](lab04/Makefile) | `make test`, `make debug`, `make valgrind`, `make clean` |

```bash
cd ~/prog1/cse-programming1/labs/lab04
make test
```

### 4.1 Struct

- `make_student(id, name, gpa)`: tạo và trả về một `Student`. Tên dài quá phải cắt bớt để không tràn mảng `name`.

### 4.2 Danh sách liên kết

Các hàm thay đổi danh sách **trả về head mới**, nên luôn gọi theo dạng `list = list_push_front(list, s);`.

| Hàm | Yêu cầu |
|---|---|
| `list_push_front` | Thêm vào đầu |
| `list_push_back` | Thêm vào cuối (danh sách rỗng là trường hợp đặc biệt) |
| `list_length` | Đếm số nút |
| `list_find` | Trả về `Student *` trỏ **vào trong** danh sách (để sửa được GPA), hoặc `NULL` |
| `list_remove` | Xoá theo id và `free` nút đó; xét 3 trường hợp: nút đầu, giữa, cuối |
| `list_free` | Giải phóng toàn bộ |

> Cách khác (Lecture 3): truyền `Node **head` để hàm sửa trực tiếp head của người gọi, xem [`linked_list.c`](../lecture03-array-pointer/structs/linked_list.c). Sau khi làm xong, thử so sánh hai cách.

### 4.3 Con trỏ hàm

| Hàm | Yêu cầu |
|---|---|
| `compare_by_name` | So sánh theo tên (dùng `strcmp`) |
| `compare_by_gpa_desc` | GPA giảm dần. `gpa` là `float` nên **không** được `return x->gpa - y->gpa` (vì sao?) |
| `list_to_array` | Chép tối đa `max` phần tử sang mảng |
| `sort_students` | Sắp xếp bằng `qsort` với hàm so sánh truyền vào |
| `is_excellent` | GPA ≥ 3.6 |
| `count_if` | Đếm số sinh viên thoả **điều kiện bất kỳ** được truyền vào dưới dạng con trỏ hàm |

### 4.4 Kiểm tra cuối

```bash
make test        # tất cả PASS
make debug       # thấy các dòng [DEBUG] student.c:...
make valgrind    # 0 errors, không rò rỉ
```

Thêm `DEBUG_PRINT(...)` vào `list_remove` để in id bị xoá; kiểm tra rằng `make test` (bản thường) **không** in dòng đó.

---

## Bài tập về nhà

**4.5 — Ứng dụng có menu** (`lab04/app.c`, tự tạo; chạy bằng `make app && ./app`). Thiết kế top-down như [`top-down/main.c`](https://github.com/bonigarcia/c-programming/blob/master/top-down/main.c), **chỉ dùng các hàm trong `student.h`**:

```
1. Thêm sinh viên          4. Sửa GPA
2. Xoá sinh viên theo id   5. In danh sách (sắp xếp theo: id / tên / GPA)
3. Tìm theo id             6. Thống kê số sinh viên xuất sắc
0. Thoát
```

Mục 5 dùng **mảng con trỏ hàm** `StudentCompare sorters[] = {compare_by_id, compare_by_name, compare_by_gpa_desc};` thay vì `switch`. Đọc dữ liệu bằng `fgets` + `sscanf` (tham khảo [`io/readline_fgets.c`](https://github.com/bonigarcia/c-programming/blob/master/io/readline_fgets.c), [`io/sscanf.c`](https://github.com/bonigarcia/c-programming/blob/master/io/sscanf.c)) để tránh lỗi trôi lệnh của `scanf`.

**4.6 — Lưu và đọc file** (nâng cao): thêm vào module hai hàm `int save_csv(const Node *head, const char *filename)` và `Node *load_csv(const char *filename)`, mỗi dòng dạng `1003,Nguyen Van An,3.45`. Tham khảo [`io/file_write.c`](https://github.com/bonigarcia/c-programming/blob/master/io/file_write.c), [`io/fscanf.c`](https://github.com/bonigarcia/c-programming/blob/master/io/fscanf.c).

**4.7 — Cây nhị phân tìm kiếm** (nâng cao): cài đặt lại danh sách sinh viên bằng BST theo id (thêm, tìm, duyệt in-order, giải phóng). Tham khảo [`binary_tree.c`](../lecture03-array-pointer/structs/binary_tree.c).

## Nộp bài

- `labs/lab04/student.c`: `make test` tất cả `PASS`, `make valgrind` sạch
- (Về nhà) `labs/lab04/app.c`

## Tham khảo thêm

- *Essential C*, mục 3 (struct), mục 7 (function pointers), mục 9 (preprocessor, multiple files)
- K&R, chương 4.5 (header files), 5.11 (function pointers), 6 (structures)
- GNU Make manual — An Introduction to Makefiles: https://www.gnu.org/software/make/manual/html_node/Introduction.html
- Code ví dụ: [`lecture08-function-pointers/`](../lecture08-function-pointers)

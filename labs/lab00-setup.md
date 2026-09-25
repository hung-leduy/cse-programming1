# Lab 0 — Cài đặt môi trường, Linux cơ bản, SSH và Git/GitHub

> **Hình thức:** sinh viên tự làm trước buổi 1 (khoảng 60–90 phút). Đầu buổi 1 dành 30 phút kiểm tra và hỗ trợ ai chưa cài xong.
> Phần 4 (Git/GitHub) là **không bắt buộc**, nhưng nên làm vì các buổi sau nộp bài qua GitHub sẽ tiện hơn.

## Mục tiêu

Sau bài này, sinh viên:

- Có một môi trường Linux với `gcc`, `gdb`, `make`, `valgrind` và VS Code.
- Biên dịch và chạy được chương trình C đầu tiên từ dòng lệnh.
- Dùng được các lệnh Linux cơ bản để làm việc với file và thư mục.
- Kết nối được tới máy chủ bằng SSH, chép file bằng `scp`.
- (Không bắt buộc) Dùng Git để lưu và nộp bài lên GitHub.

---

## Phần 1. Cài đặt môi trường

Chọn **một** trong các cách sau. Nếu máy yếu hoặc cài đặt gặp lỗi, dùng **Cách A (Codespaces)**.

### Cách A — GitHub Codespaces (không cần cài gì, chỉ cần trình duyệt)

1. Tạo tài khoản GitHub (nên dùng email sinh viên để được [GitHub Education](https://education.github.com/) miễn phí thêm giờ Codespaces).
2. Mở repo của môn học, bấm **Code → Codespaces → Create codespace on main**.
3. Chờ 1–2 phút. Repo đã có sẵn file `.devcontainer/devcontainer.json` nên Codespace tự cài `gcc`, `gdb`, `make`, `valgrind` và extension C/C++.
4. Mở terminal: menu **Terminal → New Terminal**.

> Lưu ý: Codespaces miễn phí có giới hạn số giờ mỗi tháng. Nhớ **Stop codespace** khi không dùng (github.com/codespaces).
> Một lựa chọn tương tự là [cs50.dev](https://cs50.dev/) (VS Code trên web của khoá CS50).

### Cách B — Windows: WSL2 + Ubuntu

1. Mở **PowerShell (Run as administrator)** và chạy:
   ```powershell
   wsl --install -d Ubuntu-24.04
   ```
2. Khởi động lại máy. Mở **Ubuntu** từ Start menu, đặt username và password (khi gõ password sẽ không hiện ký tự — bình thường).
3. Trong Ubuntu, cài công cụ:
   ```bash
   sudo apt update
   sudo apt install -y build-essential gdb valgrind git
   ```
4. Cài [VS Code](https://code.visualstudio.com/) trên Windows, rồi cài extension **WSL** và **C/C++ Extension Pack**.
5. Từ terminal Ubuntu, gõ `code .` để mở VS Code kết nối vào WSL.

> Thư mục nhà của Ubuntu (`/home/<tên>`) xem được từ Windows Explorer qua đường dẫn `\\wsl$\Ubuntu-24.04\home\<tên>`.
> Nên để code **bên trong** Linux (`~/...`), không để ở `/mnt/c/...` vì sẽ chậm.

### Cách C — Ubuntu / Linux

```bash
sudo apt update
sudo apt install -y build-essential gdb valgrind git
```

Cài VS Code và extension **C/C++ Extension Pack**.

### Cách D — macOS

```bash
xcode-select --install     # cài clang, make, git, lldb
```

Lệnh `gcc` trên macOS thực chất là `clang` — dùng bình thường được. Tuy nhiên `gdb` và `valgrind` **không** chạy trên Mac chip Apple (M1/M2/…). Cho buổi 2–3 (debug, kiểm tra bộ nhớ), sinh viên dùng Mac nên chuyển sang **Codespaces**.

### Kiểm tra cài đặt

```bash
gcc --version
gdb --version
make --version
valgrind --version     # (không có trên macOS)
```

Tất cả phải in ra số phiên bản, không báo `command not found`.

---

## Phần 2. Chương trình C đầu tiên

```bash
mkdir -p ~/prog1/lab00
cd ~/prog1/lab00
code hello.c        # hoặc: nano hello.c
```

Nội dung `hello.c`:

```c
#include <stdio.h>

int main() {
    printf("hello, world\n");
    return 0;
}
```

Biên dịch và chạy:

```bash
gcc -Wall hello.c -o hello   # -Wall: bật cảnh báo, -o: tên file đầu ra
./hello                      # ./ nghĩa là "file hello trong thư mục hiện tại"
```

Thử tách hai bước **compile** và **link** như trong Lecture 1:

```bash
gcc -c hello.c -o hello.o    # compile: .c -> .o (mã máy, chưa chạy được)
gcc hello.o -o hello         # link: .o + thư viện -> file thực thi
./hello
```

**Câu hỏi:** Xoá dấu `;` sau `printf(...)` rồi biên dịch lại. Trình biên dịch báo lỗi ở dòng nào? Đọc và giải thích thông báo lỗi.

---

## Phần 3. Lệnh Linux cơ bản

### 3.1. Cấu trúc một lệnh

```
gcc  -c  hello.c  -o  hello.o
───  ──  ───────  ──  ───────
lệnh      tham số (arguments)
```

Xem hướng dẫn của một lệnh: `man ls` (nhấn `q` để thoát) hoặc `ls --help`.

### 3.2. Các lệnh hay dùng

| Lệnh | Ý nghĩa | Ví dụ |
|---|---|---|
| `pwd` | In thư mục hiện tại | `pwd` |
| `ls` | Liệt kê file | `ls -l`, `ls -a`, `ls -lh` |
| `cd` | Chuyển thư mục | `cd ~/prog1`, `cd ..`, `cd -`, `cd` (về nhà) |
| `mkdir` | Tạo thư mục | `mkdir -p a/b/c` |
| `touch` | Tạo file rỗng | `touch main.c` |
| `cp` | Sao chép | `cp a.c b.c`, `cp -r lab00 lab00_backup` |
| `mv` | Di chuyển / đổi tên | `mv a.c b.c`, `mv b.c ../` |
| `rm` | Xoá (**không có thùng rác!**) | `rm a.o`, `rm -r thu_muc` |
| `cat` | In nội dung file | `cat hello.c` |
| `less` | Xem file dài (q để thoát) | `less /etc/passwd` |
| `head` / `tail` | Xem đầu / cuối file | `head -n 5 hello.c` |
| `grep` | Tìm chuỗi trong file | `grep -n printf *.c`, `grep -rn main .` |
| `find` | Tìm file | `find . -name "*.c"` |
| `wc` | Đếm dòng/từ/ký tự | `wc -l hello.c` |
| `echo` | In ra màn hình | `echo "xin chao"` |
| `history` | Xem các lệnh đã gõ | `history \| tail` |
| `clear` | Xoá màn hình | `Ctrl+L` |

### 3.3. Đường dẫn

- `/` — thư mục gốc; `~` — thư mục nhà (`/home/<tên>`)
- `.` — thư mục hiện tại; `..` — thư mục cha
- Đường dẫn tuyệt đối bắt đầu bằng `/` (`/home/an/prog1`), đường dẫn tương đối thì không (`prog1/lab00`).

### 3.4. Chuyển hướng và pipe

```bash
./hello > out.txt          # ghi đầu ra vào file (ghi đè)
./hello >> out.txt         # ghi thêm vào cuối file
./program < input.txt      # lấy dữ liệu vào từ file thay vì bàn phím
./hello 2> err.txt         # ghi luồng lỗi (stderr) vào file
ls -l | grep ".c"          # pipe: đầu ra lệnh trước là đầu vào lệnh sau
```

> Chuyển hướng `< input.txt` rất hữu ích để test chương trình đọc dữ liệu bằng `scanf` mà không phải gõ lại mỗi lần.

### 3.5. Quyền và tiến trình

```bash
ls -l hello                # -rwxr-xr-x: r=đọc, w=ghi, x=chạy
chmod +x script.sh         # cho phép chạy
./chay_mai_khong_dung      # chương trình bị treo? nhấn Ctrl+C để dừng
```

### 3.6. Phím tắt tiết kiệm thời gian

- `Tab`: tự hoàn thành tên lệnh/file (nhấn 2 lần để xem gợi ý)
- `↑` / `↓`: lệnh trước / sau; `Ctrl+R`: tìm lại lệnh cũ
- `Ctrl+C`: dừng chương trình; `Ctrl+D`: kết thúc nhập (EOF)

### Bài tập 0.1

Chỉ dùng terminal, thực hiện và ghi lại các lệnh đã dùng vào file `lab00/commands.txt`:

1. Tạo cấu trúc thư mục `~/prog1/lab00/practice/{src,build}`.
2. Chép `hello.c` vào `practice/src/`.
3. Biên dịch sao cho file thực thi nằm trong `practice/build/` (gợi ý: `gcc src/hello.c -o build/hello`).
4. Chạy chương trình và ghi đầu ra vào `practice/output.txt`.
5. Dùng `find` để liệt kê tất cả file `.c` trong `~/prog1`.
6. Đếm số dòng của `hello.c` bằng `wc`.
7. Đổi tên `practice` thành `practice_done`.

---

## Phần 4. SSH — làm việc trên máy chủ từ xa

SSH (Secure Shell) cho phép mở terminal trên một máy khác qua mạng, ví dụ máy chủ Linux của phòng lab.

> Giảng viên cung cấp: địa chỉ máy chủ `<may_chu>`, tên đăng nhập `<user>` và mật khẩu ban đầu.

### 4.1. Đăng nhập

```bash
ssh <user>@<may_chu>              # lần đầu sẽ hỏi "Are you sure...": gõ yes
ssh -p 2222 <user>@<may_chu>      # nếu máy chủ dùng cổng khác 22
exit                              # đăng xuất (hoặc Ctrl+D)
```

Sau khi vào máy chủ, thử `pwd`, `ls`, `gcc --version`, `whoami`, `hostname`.

### 4.2. Đăng nhập bằng khoá (không cần gõ mật khẩu)

```bash
ssh-keygen -t ed25519 -C "email_cua_ban@example.com"   # nhấn Enter để chấp nhận mặc định
ls ~/.ssh                                              # id_ed25519 (bí mật) và id_ed25519.pub (công khai)
ssh-copy-id <user>@<may_chu>                           # chép khoá công khai lên máy chủ
ssh <user>@<may_chu>                                   # giờ không cần mật khẩu
```

> **Không bao giờ** gửi file `id_ed25519` (khoá bí mật) cho người khác. Chỉ chia sẻ file `.pub`.

### 4.3. Đặt tên tắt trong `~/.ssh/config`

```
Host lab
    HostName <may_chu>
    User <user>
    Port 22
```

Sau đó chỉ cần `ssh lab`.

### 4.4. Chép file qua lại

```bash
scp hello.c lab:~/                  # máy mình -> máy chủ
scp lab:~/hello.c ./hello_copy.c    # máy chủ -> máy mình
scp -r lab00 lab:~/prog1/           # chép cả thư mục
```

### 4.5. VS Code Remote-SSH

Cài extension **Remote - SSH**, bấm biểu tượng `><` ở góc dưới trái → **Connect to Host...** → chọn `lab`. VS Code sẽ mở file và terminal ngay trên máy chủ.

### Bài tập 0.2

1. Đăng nhập máy chủ bằng mật khẩu, rồi thiết lập đăng nhập bằng khoá.
2. Chép `hello.c` lên máy chủ bằng `scp`, biên dịch và chạy trên máy chủ.
3. Chạy `uname -a` trên máy chủ và trên máy mình, so sánh kết quả.

---

## Phần 5 (không bắt buộc). Git và GitHub

Git lưu lại lịch sử thay đổi của code; GitHub là nơi lưu repo trên mạng để nộp bài, chia sẻ và làm việc nhóm.

### 5.1. Cấu hình lần đầu

```bash
git config --global user.name "Nguyen Van An"
git config --global user.email "email_cua_ban@example.com"
git config --global init.defaultBranch main
```

### 5.2. Thêm khoá SSH vào GitHub

```bash
cat ~/.ssh/id_ed25519.pub     # chép toàn bộ dòng này
```

Vào GitHub → **Settings → SSH and GPG keys → New SSH key** → dán vào. Kiểm tra:

```bash
ssh -T git@github.com         # "Hi <tên>! You've successfully authenticated..."
```

### 5.3. Fork và clone repo môn học

1. Mở repo môn học trên GitHub, bấm **Fork** để tạo bản sao dưới tài khoản của mình.
2. Clone bản fork về máy:
   ```bash
   cd ~/prog1
   git clone git@github.com:<tai_khoan_cua_ban>/cse-programming1.git
   cd cse-programming1
   ```
3. Clone thêm repo ví dụ tham khảo dùng trong các buổi thực hành:
   ```bash
   cd ~/prog1
   git clone https://github.com/bonigarcia/c-programming.git
   ```

### 5.4. Vòng làm việc hằng ngày

```bash
git status                    # xem file nào thay đổi
git add labs/lab01/lab01.c    # chọn file để lưu vào lần commit
git commit -m "Lab 1: hoan thanh bai 1-3"
git push                      # đẩy lên GitHub
git pull                      # lấy thay đổi mới từ GitHub về
git log --oneline             # xem lịch sử
git diff                      # xem thay đổi chưa add
```

```
 Working directory --git add--> Staging area --git commit--> Local repo --git push--> GitHub
                  <------------------------------------------------git pull--------
```

### 5.5. `.gitignore`

Không commit file biên dịch (`*.o`, file thực thi). Repo môn học đã có sẵn `.gitignore`; khi tự tạo repo, thêm file `.gitignore`:

```
*.o
*.out
a.out
build/
```

### 5.6. Lấy bài mới của giảng viên về bản fork

```bash
git remote add upstream https://github.com/<tai_khoan_gv>/cse-programming1.git
git pull upstream main
git push
```

### Bài tập 0.3

1. Fork và clone repo môn học.
2. Tạo file `labs/lab00/commands.txt` (từ bài tập 0.1) trong repo, commit và push.
3. Gửi link GitHub của bản fork cho giảng viên.

---

## Checklist trước buổi 1

- [ ] `gcc --version`, `gdb --version`, `make --version` chạy được
- [ ] Biên dịch và chạy được `hello.c`
- [ ] Làm xong bài tập 0.1
- [ ] Đăng nhập được máy chủ bằng SSH (nếu lớp dùng máy chủ)
- [ ] (Không bắt buộc) Có bản fork repo môn học trên GitHub

## Tham khảo

- VS Code + C trên Linux: https://code.visualstudio.com/docs/cpp/config-linux
- VS Code + WSL: https://code.visualstudio.com/docs/cpp/config-wsl
- The Missing Semester (shell, git): https://missing.csail.mit.edu/
- Pro Git (có bản tiếng Việt): https://git-scm.com/book/vi/v2

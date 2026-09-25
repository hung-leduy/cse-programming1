# Cấu hình VS Code để build và debug C

Chép hai file `tasks.json` và `launch.json` vào thư mục `.vscode/` ở gốc thư mục đang mở trong VS Code.

1. Cài extension **C/C++ Extension Pack**.
2. Build: menu **Terminal > Run Build Task** (`Ctrl+Shift+B`) — biên dịch file đang mở bằng `gcc -g -Wall`.
3. Debug: đặt breakpoint (click bên trái số dòng), rồi menu **Run > Start Debugging** (`F5`).
   - Thanh công cụ debug: Continue, Step over, Step into, Step out, Restart, Stop.
   - Tab **Debug Console**: gõ biểu thức bất kỳ (ví dụ `a[i]`, `*p@5`) để xem giá trị.
4. Định dạng code: `Ctrl+Shift+P` → **Format Document**.

Thử với `../multi_array/sample.c`.

Tham khảo cấu hình cho từng hệ điều hành:

- Linux: https://code.visualstudio.com/docs/cpp/config-linux
- Windows (MinGW): https://code.visualstudio.com/docs/cpp/config-mingw
- Windows (WSL): https://code.visualstudio.com/docs/cpp/config-wsl
- Windows (MSVC): https://code.visualstudio.com/docs/cpp/config-msvc
- macOS (clang): https://code.visualstudio.com/docs/cpp/config-clang-mac

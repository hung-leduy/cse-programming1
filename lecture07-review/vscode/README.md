# Configuring VS Code to build and debug C

Copy `tasks.json` and `launch.json` into the `.vscode/` folder at the root of the folder open in VS Code.

1. Install the **C/C++ Extension Pack** extension.
2. Build: menu **Terminal > Run Build Task** (`Ctrl+Shift+B`) - compiles the current file with `gcc -g -Wall`.
3. Debug: set a breakpoint (click left of the line number), then menu **Run > Start Debugging** (`F5`).
   - Debug toolbar: Continue, Step over, Step into, Step out, Restart, Stop.
   - Tab **Debug Console**: type any expression (e.g. `a[i]`, `*p@5`) to see its value.
4. Format code: `Ctrl+Shift+P` -> **Format Document**.

Try it with `../multi_array/sample.c`.

Configuration guides for each operating system:

- Linux: https://code.visualstudio.com/docs/cpp/config-linux
- Windows (MinGW): https://code.visualstudio.com/docs/cpp/config-mingw
- Windows (WSL): https://code.visualstudio.com/docs/cpp/config-wsl
- Windows (MSVC): https://code.visualstudio.com/docs/cpp/config-msvc
- macOS (clang): https://code.visualstudio.com/docs/cpp/config-clang-mac

#include <stdio.h>

// Chọn code theo hệ điều hành bằng #ifdef / #else / #endif
// (_WIN32 được trình biên dịch tự định nghĩa khi build trên Windows)
#ifdef _WIN32
#include <windows.h>
#define PLATFORM "Windows"
#elif defined(__APPLE__)
#define PLATFORM "macOS"
#elif defined(__linux__)
#define PLATFORM "Linux"
#else
#define PLATFORM "Unknown"
#endif

int main() {
    printf("Platform: %s\n", PLATFORM);
    printf("File: %s, line: %d\n", __FILE__, __LINE__); // macro có sẵn
    return 0;
}

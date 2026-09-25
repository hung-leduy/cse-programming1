#include <stdio.h>

// Choose code per operating system with #ifdef / #else / #endif
// (_WIN32 is predefined by the compiler when building on Windows)
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
    printf("File: %s, line: %d\n", __FILE__, __LINE__); // predefined macros
    return 0;
}

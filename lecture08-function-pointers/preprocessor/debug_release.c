#include <stdio.h>

// Debug build:   gcc -DDEBUG debug_release.c -o debug_release
// Release build: gcc debug_release.c -o debug_release
#ifdef DEBUG
#define LOG(msg, a, b) printf("[DEBUG] %s: %d, %d\n", msg, a, b)
#else
#define LOG(msg, a, b) // Release build: does nothing
#endif

int do_something(int a, int b) {
    return a * b;
}

int function(int a, int b) {
#ifdef DEBUG
    printf("%d, %d\n", a, b);
#endif
    LOG("function", a, b);
    return do_something(a, b);
}

int main() {
#if defined(DEBUG)
    printf("Build: Debug\n");
#else
    printf("Build: Release\n");
#endif
    printf("result = %d\n", function(6, 7));
    return 0;
}

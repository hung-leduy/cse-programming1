#include <stdio.h>

// Nạp hàm từ thư viện động lúc chạy (runtime) và gọi qua con trỏ hàm
#ifdef _WIN32
#include <windows.h>
HINSTANCE handle = NULL;
#define LIB_NAME "shapes.dll"
#define OPEN_LIB(name) LoadLibraryA(name)
#define GET_FUNC GetProcAddress
#define CLOSE_LIB FreeLibrary
#else
#include <dlfcn.h>
void *handle = NULL;
#define LIB_NAME "./libshapes.so"
#define OPEN_LIB(name) dlopen(name, RTLD_LAZY)
#define GET_FUNC dlsym
#define CLOSE_LIB dlclose
#endif

typedef double (*area_fn)(double);

int main() {
    handle = OPEN_LIB(LIB_NAME);
    if (handle == NULL) {
        printf("Không nạp được %s\n", LIB_NAME);
        return 1;
    }

    // Khai báo con trỏ hàm và lấy địa chỉ hàm theo tên
    area_fn circle_area = (area_fn)GET_FUNC(handle, "circle_area");
    area_fn square_area = (area_fn)GET_FUNC(handle, "square_area");
    if (circle_area == NULL || square_area == NULL) {
        printf("Không tìm thấy hàm\n");
        CLOSE_LIB(handle);
        return 1;
    }

    printf("circle_area(2) = %.4f\n", circle_area(2));
    printf("square_area(3) = %.4f\n", square_area(3));
    CLOSE_LIB(handle);
    return 0;
}

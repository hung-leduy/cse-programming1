#include <stdio.h>

// Tự cài đặt một số hàm xử lý chuỗi để hiểu cách hoạt động

int my_strlen(const char *s) {
    int n = 0;
    while (s[n] != '\0')
        n++;
    return n;
}

void my_strcpy(char *dst, const char *src) {
    while ((*dst++ = *src++) != '\0')
        ;
}

int my_strcmp(const char *a, const char *b) {
    while (*a != '\0' && *a == *b) {
        a++;
        b++;
    }
    return (unsigned char)*a - (unsigned char)*b;
}

void my_reverse(char *s) {
    for (int i = 0, j = my_strlen(s) - 1; i < j; i++, j--) {
        char t = s[i];
        s[i] = s[j];
        s[j] = t;
    }
}

int main() {
    char buf[32];
    my_strcpy(buf, "programming");
    printf("%s (len = %d)\n", buf, my_strlen(buf));
    my_reverse(buf);
    printf("reversed: %s\n", buf);
    printf("cmp(abc, abd) = %d\n", my_strcmp("abc", "abd"));
    return 0;
}

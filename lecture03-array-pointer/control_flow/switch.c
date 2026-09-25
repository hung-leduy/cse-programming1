#include <stdio.h>

void describe(int num) {
    switch (num) {
    case 1:
        printf("number 1\n");
        break;
    case 2:
        printf("number 2\n");
        break;
    case 3: // gộp case 3 và 4
    case 4:
        printf("number 3 or 4\n");
        break;
    default: // không bắt buộc
        printf("number must be from 1 to 4\n");
    }
}

int main() {
    for (int i = 0; i <= 5; i++)
        describe(i);
    return 0;
}

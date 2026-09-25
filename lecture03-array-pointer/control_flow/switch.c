#include <stdio.h>

void describe(int num) {
    switch (num) {
    case 1:
        printf("number 1\n");
        break;
    case 2:
        printf("number 2\n");
        break;
    case 3: // case 3 and 4 share the same code
    case 4:
        printf("number 3 or 4\n");
        break;
    default: // optional
        printf("number must be from 1 to 4\n");
    }
}

int main() {
    for (int i = 0; i <= 5; i++)
        describe(i);
    return 0;
}

#include <stdio.h>
#include <stdlib.h>

struct fraction {
    int numerator;
    int denominator;
};

int main() {
    struct fraction *f1_p, *f2_p;

    // Quiz: cấp phát bộ nhớ cho con trỏ tới struct
    f1_p = malloc(sizeof(struct fraction));
    f2_p = malloc(sizeof(*f2_p)); // cách viết tương đương

    // Giải tham chiếu bằng "*" (cần dấu ngoặc vì "." ưu tiên hơn "*")
    (*f1_p).numerator = 22;
    (*f1_p).denominator = 7;

    // Dùng "->" (khuyến nghị)
    f2_p->numerator = 355;
    f2_p->denominator = 113;

    printf("%d/%d  %d/%d\n", f1_p->numerator, f1_p->denominator,
           f2_p->numerator, f2_p->denominator);

    free(f1_p);
    free(f2_p);
    return 0;
}

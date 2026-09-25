#include <stdio.h>

/* Chú thích khối (block comment):
   có thể trải trên nhiều dòng */

int main() {
    // Chú thích dòng: các ký tự sau // bị bỏ qua
    printf("here is ok\n"); // here is ok //<-- phần này bị bỏ qua
    printf("here is ok\n"); /* <-- phần này bị bỏ qua --> */
    return 0;
}

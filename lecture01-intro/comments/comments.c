#include <stdio.h>

/* Block comment:
   can span multiple lines */

int main() {
    // Line comment: everything after // is ignored
    printf("here is ok\n"); // here is ok //<-- this part is ignored
    printf("here is ok\n"); /* <-- this part is ignored --> */
    return 0;
}

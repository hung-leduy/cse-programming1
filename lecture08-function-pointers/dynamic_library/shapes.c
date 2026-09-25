// Dynamic library: compiled into libshapes.so
//   gcc -shared -fPIC shapes.c -o libshapes.so

double circle_area(double r) {
    return 3.14159 * r * r;
}

double square_area(double a) {
    return a * a;
}

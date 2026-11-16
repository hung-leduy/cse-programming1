// Lab 3 (Part 5) — Input/output with <stdio.h>
//   sprintf / sscanf, command-line arguments, reading and writing text files
//
// Compile:       gcc -Wall -Wextra -g lab03_io.c -o lab03_io
// Run tests:     ./lab03_io
// Draw an ink:   ./lab03_io 18_em_1.txt              (draw to the screen)
//                ./lab03_io 18_em_1.txt ink.txt      (draw to the screen and save to ink.txt)
// Check memory:  valgrind --leak-check=full ./lab03_io 18_em_1.txt
//
// Run the program from the labs/lab03 folder: the tests open "18_em_1.txt"
// in the current working directory.
// Task: implement the functions marked TODO until all tests PASS
//       and valgrind reports 0 errors and no leaks.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// ---------------------------------------------------------------------------
// Simple test harness (no need to modify)
static int passed = 0, total = 0;
#define CHECK(expr)                                 \
    do {                                            \
        total++;                                    \
        if (expr) {                                 \
            passed++;                               \
            printf("  PASS  %s\n", #expr);          \
        } else {                                    \
            printf("  FAIL  %s\n", #expr);          \
        }                                           \
    } while (0)

// Count the lines of a text file and copy its first line (without '\n') into first.
// Returns -1 if the file cannot be opened.
static int read_back(const char *filename, char *first, int size) {
    FILE *f = fopen(filename, "r");
    if (f == NULL)
        return -1;
    char line[512];
    int lines = 0;
    first[0] = '\0';
    while (fgets(line, sizeof(line), f) != NULL) {
        if (lines == 0) {
            line[strcspn(line, "\n")] = '\0';
            snprintf(first, size, "%s", line);
        }
        lines++;
    }
    fclose(f);
    return lines;
}
// ---------------------------------------------------------------------------

// One point of a handwritten trace ("ink"), read from a line "attr x y" of an ink file
typedef struct {
    int attr; // 2 = first point of a stroke (pen down), 0 = point inside a stroke,
              // 4 = last point of a stroke (pen up)
    int x;
    int y;
} Point;

// ===========================================================================
// A. Formatted output into a string: sprintf
// ===========================================================================

// 3.10 Write the time stored in *t into out as "hh:mm:ss" (for example "09:05:30").
//      The caller allocates out (at least 9 bytes). Hint: sprintf and %02d.
void sprint_time(char *out, const struct tm *t) {
    // TODO
    (void)t;
    out[0] = '\0';
}

// 3.11 Write the date stored in *t into out as "Www, dd/mm/yyyy" (for example "Wed, 18/11/2026").
//      The caller allocates out (at least 16 bytes).
//      Careful: tm_mon counts from 0 (January = 0), tm_year counts years since 1900,
//      tm_wday is 0 for Sunday, 1 for Monday, ..., 6 for Saturday.
void sprint_date(char *out, const struct tm *t) {
    // TODO: const char *days[] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
    (void)t;
    out[0] = '\0';
}

// ===========================================================================
// B. Formatted input from a string: sscanf
// ===========================================================================

// 3.12 Read a time written as "hh:mm:ss" from the string s into *h, *m and *sec.
//      Return 1 if s starts with 3 numbers separated by ':' and the time is valid
//      (0 <= h <= 23, 0 <= m <= 59, 0 <= sec <= 59); otherwise return 0.
//      Hint: sscanf returns the number of values it managed to read.
int parse_time(const char *s, int *h, int *m, int *sec) {
    // TODO
    (void)s; (void)h; (void)m; (void)sec;
    return 0;
}

// ===========================================================================
// C. Text files: fopen, fgets, fprintf, fclose
// ===========================================================================

// 3.13 Read an ink file (see 18_em_1.txt):
//          [\sqrt 4 8]      <- a line starting with '[': the label, between '[' and ']'
//          2   0   119      <- every other line: attr x y (separated by tabs)
//          0   6   122
//          ...
//      - Copy the label (without the brackets) into label, at most label_size - 1 characters
//        plus '\0' (never write past label[label_size - 1]).
//      - Return an array with all the points, allocated on the heap. The number of points
//        is not known in advance: grow the array with realloc, as in 3.7 push_back.
//      - Store the number of points in *count.
//      - If the file cannot be opened: return NULL and set *count = 0.
//      Read line by line: fgets into a char buffer, then sscanf(line, "%d %d %d", ...).
//      Do not forget fclose.
Point *read_ink(const char *filename, char *label, int label_size, int *count) {
    // TODO
    (void)filename; (void)label_size;
    label[0] = '\0';
    *count = 0;
    return NULL;
}

// 3.14 Draw the points on a rows x cols "canvas" of characters.
//      - Allocate the canvas as char ** (like alloc_matrix in 3.8). Each row has cols + 1 chars:
//        cols spaces ' ' followed by '\0', so that every row is a string.
//      - Scale the points so that they fill the whole canvas:
//            col = (x - min_x) * (cols - 1) / (max_x - min_x)
//            row = (y - min_y) * (rows - 1) / (max_y - min_y)
//        (integer division; use 0 when max == min to avoid dividing by 0),
//        then set canvas[row][col] = '*'.
//      Return the canvas, or NULL if n == 0.
char **render_ink(const Point *pts, int n, int rows, int cols) {
    // TODO
    (void)pts; (void)n; (void)rows; (void)cols;
    return NULL;
}

// 3.14 Free the canvas: each row first, then the array of row pointers.
void free_canvas(char **canvas, int rows) {
    // TODO
    (void)canvas; (void)rows;
}

// 3.15 Write the canvas to a text file, one row per line (fopen with "w", then fprintf or fputs).
//      Return 0 on success, -1 if the file cannot be opened.
int save_canvas(const char *filename, char **canvas, int rows) {
    // TODO
    (void)filename; (void)canvas; (void)rows;
    return -1;
}

// Print the canvas to the screen inside a frame (no need to modify)
void print_canvas(char **canvas, int rows, int cols) {
    printf("+");
    for (int j = 0; j < cols; j++)
        printf("-");
    printf("+\n");
    for (int i = 0; i < rows; i++)
        printf("|%s|\n", canvas[i]);
    printf("+");
    for (int j = 0; j < cols; j++)
        printf("-");
    printf("+\n");
}

int main(int argc, char *argv[]) {
    char buf[64];
    struct tm t = {0};
    t.tm_hour = 9;
    t.tm_min = 5;
    t.tm_sec = 30;
    t.tm_mday = 18;
    t.tm_mon = 10;            // November
    t.tm_year = 2026 - 1900;
    t.tm_wday = 3;            // Wednesday

    printf("3.10 sprint_time\n");
    sprint_time(buf, &t);
    CHECK(strcmp(buf, "09:05:30") == 0);
    t.tm_hour = 23;
    t.tm_min = 59;
    t.tm_sec = 0;
    sprint_time(buf, &t);
    CHECK(strcmp(buf, "23:59:00") == 0);

    printf("3.11 sprint_date\n");
    sprint_date(buf, &t);
    CHECK(strcmp(buf, "Wed, 18/11/2026") == 0);
    t.tm_mday = 1;
    t.tm_mon = 0;             // January
    t.tm_year = 2023 - 1900;
    t.tm_wday = 0;            // Sunday
    sprint_date(buf, &t);
    CHECK(strcmp(buf, "Sun, 01/01/2023") == 0);

    printf("3.12 parse_time\n");
    int h = -1, m = -1, s = -1;
    CHECK(parse_time("09:05:30", &h, &m, &s) == 1 && h == 9 && m == 5 && s == 30);
    CHECK(parse_time("23:59:59", &h, &m, &s) == 1 && h == 23 && m == 59 && s == 59);
    CHECK(parse_time("24:00:00", &h, &m, &s) == 0);
    CHECK(parse_time("12:60:00", &h, &m, &s) == 0);
    CHECK(parse_time("12:30", &h, &m, &s) == 0);
    CHECK(parse_time("hh:mm:ss", &h, &m, &s) == 0);
    // parse, then print again with sprint_time
    if (parse_time("7:8:9", &t.tm_hour, &t.tm_min, &t.tm_sec))
        sprint_time(buf, &t);
    CHECK(strcmp(buf, "07:08:09") == 0);

    printf("3.13 read_ink\n");
    FILE *probe = fopen("18_em_1.txt", "r");
    if (probe == NULL)
        printf("  NOTE: 18_em_1.txt not found - run ./lab03_io from the labs/lab03 folder\n");
    else
        fclose(probe);
    char label[100];
    int n = -1;
    Point *pts = read_ink("18_em_1.txt", label, sizeof(label), &n);
    CHECK(pts != NULL && n == 81);
    CHECK(strcmp(label, "\\sqrt 4 8") == 0);
    CHECK(pts != NULL && n == 81 && pts[0].attr == 2 && pts[0].x == 0 && pts[0].y == 119);
    CHECK(pts != NULL && n == 81 && pts[80].attr == 4 && pts[80].x == 333 && pts[80].y == 91);
    int strokes = 0;
    for (int i = 0; pts != NULL && i < n; i++)
        if (pts[i].attr == 2)
            strokes++;
    CHECK(strokes == 4);
    char short_label[5];
    int n_short = 0;
    free(read_ink("18_em_1.txt", short_label, sizeof(short_label), &n_short));
    CHECK(strcmp(short_label, "\\sqr") == 0); // the label is cut, not overflowed
    int n_missing = -1;
    CHECK(read_ink("no_such_file.txt", label, sizeof(label), &n_missing) == NULL && n_missing == 0);

    printf("3.14 render_ink\n");
    Point corners[] = {{2, 0, 0}, {0, 10, 0}, {0, 0, 10}, {4, 10, 10}};
    char **c = render_ink(corners, 4, 3, 5);
    CHECK(c != NULL && strcmp(c[0], "*   *") == 0);
    CHECK(c != NULL && strcmp(c[1], "     ") == 0);
    CHECK(c != NULL && strcmp(c[2], "*   *") == 0);
    if (c != NULL)
        free_canvas(c, 3);
    char **canvas = render_ink(pts, n, 20, 60);
    CHECK(canvas != NULL && strlen(canvas[0]) == 60 && strlen(canvas[19]) == 60);
    CHECK(canvas != NULL && canvas[9][0] == '*'); // the first point (0, 119)

    printf("3.15 save_canvas\n");
    char first[100];
    CHECK(canvas != NULL && save_canvas("lab03_io_test.txt", canvas, 20) == 0);
    CHECK(canvas != NULL && read_back("lab03_io_test.txt", first, sizeof(first)) == 20 &&
          strcmp(first, canvas[0]) == 0);
    remove("lab03_io_test.txt");
    CHECK(canvas != NULL && save_canvas("no_such_folder/out.txt", canvas, 20) == -1);
    if (canvas != NULL)
        free_canvas(canvas, 20);
    free(pts);

    printf("\nResult: %d/%d PASS\n", passed, total);

    // Demo 1: the current date and time, printed with your sprint_time and sprint_date
    time_t now = time(NULL);
    struct tm *info = localtime(&now);
    char when[64] = "";
    sprint_time(when, info);
    printf("\nCurrent time is: %s\n", when);
    sprint_date(when, info);
    printf("Today is: %s\n", when);

    // Demo 2: command-line arguments   ./lab03_io <ink_file> [output_file]
    if (argc < 2) {
        printf("\nDraw an ink file:  %s 18_em_1.txt [output.txt]\n", argv[0]);
    } else {
        int rows = 20, cols = 60, count = 0;
        Point *ink = read_ink(argv[1], label, sizeof(label), &count);
        if (ink == NULL) {
            fprintf(stderr, "Cannot read the ink file \"%s\"\n", argv[1]);
        } else {
            printf("\n%s: label \"%s\", %d points\n", argv[1], label, count);
            char **art = render_ink(ink, count, rows, cols);
            if (art != NULL) {
                print_canvas(art, rows, cols);
                if (argc >= 3) {
                    if (save_canvas(argv[2], art, rows) == 0)
                        printf("Saved to %s\n", argv[2]);
                    else
                        fprintf(stderr, "Cannot write \"%s\"\n", argv[2]);
                }
                free_canvas(art, rows);
            }
            free(ink);
        }
    }

    return passed == total ? 0 : 1;
}

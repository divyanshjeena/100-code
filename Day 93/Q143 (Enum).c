/*
 * Find and print the student with the highest marks.
 */
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdarg.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#if defined(__MINGW32__)
static inline int c11_scanf(const char *format, ...)
    __attribute__((format(gnu_scanf, 1, 2)));
static inline int c11_scanf(const char *format, ...)
{
    va_list arguments;
    va_start(arguments, format);
    int result = vscanf(format, arguments);
    va_end(arguments);
    return result;
}
static inline int c11_fscanf(FILE *stream, const char *format, ...)
    __attribute__((format(gnu_scanf, 2, 3)));
static inline int c11_fscanf(FILE *stream, const char *format, ...)
{
    va_list arguments;
    va_start(arguments, format);
    int result = vfscanf(stream, format, arguments);
    va_end(arguments);
    return result;
}
static inline int c11_printf(const char *format, ...)
    __attribute__((format(gnu_printf, 1, 2)));
static inline int c11_printf(const char *format, ...)
{
    va_list arguments;
    va_start(arguments, format);
    int result = vprintf(format, arguments);
    va_end(arguments);
    return result;
}
#define scanf c11_scanf
#define fscanf c11_fscanf
#define printf c11_printf
#endif
struct Student { char name[128]; int roll_no; double marks; };

int main(void)
{
    int n;
    struct Student student, topper;
    if (scanf("%d", &n) != 1 || n < 1 || n > 1000) {
        fprintf(stderr, "Student count must be between 1 and 1000.\n");
        return EXIT_FAILURE;
    }
    for (int i = 0; i < n; ++i) {
        if (scanf("%127s %d %lf", student.name, &student.roll_no, &student.marks) != 3 ||
            !isfinite(student.marks) || student.marks < 0.0 || student.marks > 100.0) {
            fprintf(stderr, "Invalid student record.\n");
            return EXIT_FAILURE;
        }
        if (i == 0 || student.marks > topper.marks) topper = student;
    }
    printf("Topper: %s (Marks: %.2f)\n", topper.name, topper.marks);
    return EXIT_SUCCESS;
}

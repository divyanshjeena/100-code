/*
 * Store details of 5 students in an array of structures and print all.
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
    struct Student students[5];
    for (int i = 0; i < 5; ++i) {
        if (scanf("%127s %d %lf", students[i].name, &students[i].roll_no,
                  &students[i].marks) != 3 || !isfinite(students[i].marks) ||
            students[i].marks < 0.0 || students[i].marks > 100.0) {
            fprintf(stderr, "Expected valid name, roll number, and marks for each student.\n");
            return EXIT_FAILURE;
        }
    }
    puts("Name | Roll | Marks");
    for (int i = 0; i < 5; ++i) {
        printf("%s | %d | %.2f\n",
               students[i].name, students[i].roll_no, students[i].marks);
    }
    return EXIT_SUCCESS;
}

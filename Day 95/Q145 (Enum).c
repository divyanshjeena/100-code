/*
 * Return a structure containing top student's details from a function.
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

static struct Student top_student(const struct Student students[], int count)
{
    struct Student top = students[0];
    for (int i = 1; i < count; ++i) {
        if (students[i].marks > top.marks) top = students[i];
    }
    return top;
}

int main(void)
{
    int n;
    struct Student students[1000];
    if (scanf("%d", &n) != 1 || n < 1 || n > 1000) {
        fprintf(stderr, "Student count must be between 1 and 1000.\n");
        return EXIT_FAILURE;
    }
    for (int i = 0; i < n; ++i) {
        if (scanf("%127s %d %lf", students[i].name, &students[i].roll_no,
                  &students[i].marks) != 3 || !isfinite(students[i].marks) ||
            students[i].marks < 0.0 || students[i].marks > 100.0) {
            fprintf(stderr, "Invalid student record.\n");
            return EXIT_FAILURE;
        }
    }
    struct Student top = top_student(students, n);
    printf("Top Student: %s | Roll: %d | Marks: %.2f\n",
           top.name, top.roll_no, top.marks);
    return EXIT_SUCCESS;
}

/*
 * Use malloc() to allocate structure memory dynamically and print details.
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
    struct Student *student = malloc(sizeof *student);
    if (student == NULL) {
        perror("Could not allocate student");
        return EXIT_FAILURE;
    }
    if (scanf("%127s %d %lf", student->name, &student->roll_no, &student->marks) != 3 ||
        !isfinite(student->marks) || student->marks < 0.0 || student->marks > 100.0) {
        fprintf(stderr, "Expected name, roll number, and marks from 0 to 100.\n");
        free(student);
        return EXIT_FAILURE;
    }
    printf("Name: %s | Roll: %d | Marks: %.2f\n",
           student->name, student->roll_no, student->marks);
    free(student);
    return EXIT_SUCCESS;
}

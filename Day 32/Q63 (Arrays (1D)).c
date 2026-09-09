/*
 * Merge two arrays.
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
int main(void)
{
    int first_count, second_count, values[2000];
    if (scanf("%d", &first_count) != 1 || first_count < 0 || first_count > 1000) {
        fprintf(stderr, "First array length must be from 0 to 1000.\n");
        return EXIT_FAILURE;
    }
    for (int i = 0; i < first_count; ++i) {
        if (scanf("%d", &values[i]) != 1) {
            fprintf(stderr, "Insufficient first-array elements.\n");
            return EXIT_FAILURE;
        }
    }
    if (scanf("%d", &second_count) != 1 || second_count < 0 ||
        second_count > 1000 || first_count + second_count == 0) {
        fprintf(stderr, "Second array length must be from 0 to 1000; total length must be positive.\n");
        return EXIT_FAILURE;
    }
    for (int i = 0; i < second_count; ++i) {
        if (scanf("%d", &values[first_count + i]) != 1) {
            fprintf(stderr, "Insufficient second-array elements.\n");
            return EXIT_FAILURE;
        }
    }
    for (int i = 0; i < first_count + second_count; ++i) {
        printf("%s%d", i == 0 ? "" : " ", values[i]);
    }
    putchar('\n');
    return EXIT_SUCCESS;
}

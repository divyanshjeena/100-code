/*
 * Write a program to take two sorted arrays of size m and n as input. Merge both the arrays such that the merged array is also sorted. Print the merged array.
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
    int first_count, second_count, first[1000], second[1000];
    if (scanf("%d", &first_count) != 1 || first_count < 0 || first_count > 1000) {
        fprintf(stderr, "First array length must be from 0 to 1000.\n");
        return EXIT_FAILURE;
    }
    for (int i = 0; i < first_count; ++i) {
        if (scanf("%d", &first[i]) != 1 ||
            (i > 0 && first[i] < first[i - 1])) {
            fprintf(stderr, "Expected a sorted first array.\n");
            return EXIT_FAILURE;
        }
    }
    if (scanf("%d", &second_count) != 1 || second_count < 0 || second_count > 1000 ||
        first_count + second_count == 0) {
        fprintf(stderr, "Second array length must be 0..1000 and total length positive.\n");
        return EXIT_FAILURE;
    }
    for (int i = 0; i < second_count; ++i) {
        if (scanf("%d", &second[i]) != 1 ||
            (i > 0 && second[i] < second[i - 1])) {
            fprintf(stderr, "Expected a sorted second array.\n");
            return EXIT_FAILURE;
        }
    }
    int i = 0, j = 0, printed = 0;
    while (i < first_count || j < second_count) {
        int value;
        if (j == second_count || (i < first_count && first[i] <= second[j])) {
            value = first[i++];
        } else {
            value = second[j++];
        }
        printf("%s%d", printed++ == 0 ? "" : " ", value);
    }
    putchar('\n');
    return EXIT_SUCCESS;
}

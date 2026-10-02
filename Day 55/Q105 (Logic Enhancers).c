/*
 * Write a program to take an integer array nums of size n, and print the majority element. The majority element is the element that appears strictly more than âŒŠn / 2âŒ‹ times. Print -1 if no such element exists. Note: Majority Element is not necessarily the element that is present most number of times.
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
    int n, values[1000], candidate = 0, votes = 0;
    if (scanf("%d", &n) != 1 || n < 1 || n > 1000) {
        fprintf(stderr, "Array length must be between 1 and 1000.\n");
        return EXIT_FAILURE;
    }
    for (int i = 0; i < n; ++i) {
        if (scanf("%d", &values[i]) != 1) {
            fprintf(stderr, "Insufficient array elements.\n");
            return EXIT_FAILURE;
        }
        if (votes == 0) candidate = values[i];
        votes += values[i] == candidate ? 1 : -1;
    }
    int occurrences = 0;
    for (int i = 0; i < n; ++i) if (values[i] == candidate) ++occurrences;
    printf("%d\n", occurrences > n / 2 ? candidate : -1);
    return EXIT_SUCCESS;
}

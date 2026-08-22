/*
 * Write a program to print the product of even numbers from 1 to n.
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
    int n;
    unsigned long long product = 1;
    int count = 0;
    if (scanf("%d", &n) != 1 || n < 0 || n > 64) {
        fprintf(stderr, "n must be between 0 and 64.\n");
        return EXIT_FAILURE;
    }
    for (int value = 2; value <= n; value += 2) {
        if (product > ULLONG_MAX / (unsigned)value) {
            fprintf(stderr, "Product exceeds the supported integer range.\n");
            return EXIT_FAILURE;
        }
        product *= (unsigned)value;
        ++count;
    }
    printf("%llu", product);
    if (count > 0) {
        printf(" (");
        int printed = 0;
        for (int value = 2; value <= n; value += 2) {
            printf("%s%d", printed++ == 0 ? "" : " * ", value);
        }
        putchar(')');
    }
    putchar('\n');
    return EXIT_SUCCESS;
}

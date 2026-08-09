/*
 * Write a program to input two numbers and display their sum, difference, product, and quotient.
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
    long long a, b;
    if (scanf("%lld %lld", &a, &b) != 2 || a < -1000000000LL || a > 1000000000LL ||
        b < -1000000000LL || b > 1000000000LL) {
        fprintf(stderr, "Expected two integers in range -1000000000..1000000000.\n");
        return EXIT_FAILURE;
    }
    printf("Sum=%lld, Diff=%lld, Product=%lld", a + b, a - b, a * b);
    if (b == 0) {
        printf(", Quotient=undefined (division by zero)\n");
    } else {
        printf(", Quotient=%lld\n", a / b);
    }
    return EXIT_SUCCESS;
}

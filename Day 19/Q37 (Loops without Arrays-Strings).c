/*
 * Write a program to find the LCM of two numbers.
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
    unsigned long long x, y, gcd;
    if (scanf("%lld %lld", &a, &b) != 2) {
        fprintf(stderr, "Expected two integers.\n");
        return EXIT_FAILURE;
    }
    x = a < 0 ? (unsigned long long)(-(a + 1)) + 1ULL : (unsigned long long)a;
    y = b < 0 ? (unsigned long long)(-(b + 1)) + 1ULL : (unsigned long long)b;
    if (x == 0ULL || y == 0ULL) {
        puts("0");
        return EXIT_SUCCESS;
    }
    unsigned long long left = x, right = y;
    while (right != 0ULL) {
        unsigned long long remainder = left % right;
        left = right;
        right = remainder;
    }
    gcd = left;
    if (x / gcd > ULLONG_MAX / y) {
        fprintf(stderr, "LCM exceeds the supported range.\n");
        return EXIT_FAILURE;
    }
    printf("%llu\n", (x / gcd) * y);
    return EXIT_SUCCESS;
}

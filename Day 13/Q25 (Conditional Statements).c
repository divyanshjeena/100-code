/*
 * Write a program to implement a basic calculator using switch-case for +, -, *, /, %.
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
    char operation;
    if (scanf("%lld %lld %c", &a, &b, &operation) != 3 ||
        a < -1000000000LL || a > 1000000000LL ||
        b < -1000000000LL || b > 1000000000LL) {
        fprintf(stderr, "Expected two integers in range +/-1000000000 and an operator.\n");
        return EXIT_FAILURE;
    }
    switch (operation) {
    case '+': printf("%lld\n", a + b); break;
    case '-': printf("%lld\n", a - b); break;
    case '*': printf("%lld\n", a * b); break;
    case '/':
        if (b == 0) {
            fprintf(stderr, "Division by zero is undefined.\n");
            return EXIT_FAILURE;
        }
        printf("%lld\n", a / b);
        break;
    case '%':
        if (b == 0) {
            fprintf(stderr, "Remainder by zero is undefined.\n");
            return EXIT_FAILURE;
        }
        printf("%lld\n", a % b);
        break;
    default:
        fprintf(stderr, "Unsupported operator.\n");
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

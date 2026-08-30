/*
 * Write a program to check if a number is a strong number.
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
    unsigned long long value, remaining, sum = 0ULL;
    if (scanf("%llu", &value) != 1 || value > 1000000000ULL) {
        fprintf(stderr, "Expected a non-negative integer no greater than 1000000000.\n");
        return EXIT_FAILURE;
    }
    remaining = value;
    do {
        unsigned digit = (unsigned)(remaining % 10ULL);
        unsigned long long factorial = 1ULL;
        for (unsigned i = 2U; i <= digit; ++i) factorial *= i;
        sum += factorial;
        remaining /= 10ULL;
    } while (remaining != 0ULL);
    puts(sum == value ? "Strong number" : "Not strong number");
    return EXIT_SUCCESS;
}

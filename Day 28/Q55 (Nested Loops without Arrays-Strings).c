/*
 * Write a program to print all the prime numbers from 1 to n.
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
    if (scanf("%d", &n) != 1 || n < 2 || n > 10000000) {
        fprintf(stderr, "n must be between 2 and 10000000.\n");
        return EXIT_FAILURE;
    }
    for (int value = 2; value <= n; ++value) {
        int prime = 1;
        for (int divisor = 2; divisor <= value / divisor; ++divisor) {
            if (value % divisor == 0) {
                prime = 0;
                break;
            }
        }
        if (prime) printf("%s%d", value == 2 ? "" : " ", value);
    }
    putchar('\n');
    return EXIT_SUCCESS;
}

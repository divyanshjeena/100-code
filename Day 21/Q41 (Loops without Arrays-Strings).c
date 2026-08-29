/*
 * Write a program to swap the first and last digit of a number.
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
    long long value;
    unsigned long long magnitude, place = 1ULL, first, last, middle;
    int negative;
    if (scanf("%lld", &value) != 1) {
        fprintf(stderr, "Expected an integer.\n");
        return EXIT_FAILURE;
    }
    negative = value < 0;
    magnitude = negative ? (unsigned long long)(-(value + 1)) + 1ULL
                         : (unsigned long long)value;
    if (magnitude < 10ULL) {
        printf("%lld\n", value);
        return EXIT_SUCCESS;
    }
    while (magnitude / place >= 10ULL) place *= 10ULL;
    first = magnitude / place;
    last = magnitude % 10ULL;
    middle = (magnitude % place) / 10ULL;
    magnitude = last * place + middle * 10ULL + first;
    if (negative) printf("-%llu\n", magnitude);
    else printf("%llu\n", magnitude);
    return EXIT_SUCCESS;
}

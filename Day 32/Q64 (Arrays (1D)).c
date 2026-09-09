/*
 * Find the digit that occurs the most times in an integer number.
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
    unsigned long long value;
    int frequency[10] = {0};
    if (scanf("%llu", &value) != 1) {
        fprintf(stderr, "Expected a non-negative integer.\n");
        return EXIT_FAILURE;
    }
    do {
        ++frequency[value % 10ULL];
        value /= 10ULL;
    } while (value != 0ULL);
    int most_frequent = 0;
    for (int digit = 1; digit < 10; ++digit) {
        if (frequency[digit] > frequency[most_frequent]) most_frequent = digit;
    }
    printf("%d\n", most_frequent);
    return EXIT_SUCCESS;
}

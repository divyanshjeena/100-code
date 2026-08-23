/*
 * Write a program to reverse a given number.
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
    unsigned long long magnitude, reversed = 0;
    int negative;
    if (scanf("%lld", &value) != 1) {
        fprintf(stderr, "Expected an integer.\n");
        return EXIT_FAILURE;
    }
    negative = value < 0;
    magnitude = negative ? (unsigned long long)(-(value + 1)) + 1ULL
                         : (unsigned long long)value;
    do {
        unsigned digit = (unsigned)(magnitude % 10ULL);
        if (reversed > (ULLONG_MAX - digit) / 10ULL) {
            fprintf(stderr, "Reversed value exceeds the supported range.\n");
            return EXIT_FAILURE;
        }
        reversed = reversed * 10ULL + digit;
        magnitude /= 10ULL;
    } while (magnitude != 0ULL);
    if (negative) {
        if (reversed > (unsigned long long)LLONG_MAX + 1ULL) {
            fprintf(stderr, "Reversed value exceeds the supported range.\n");
            return EXIT_FAILURE;
        }
        if (reversed == (unsigned long long)LLONG_MAX + 1ULL) printf("%lld\n", LLONG_MIN);
        else printf("-%llu\n", reversed);
    } else {
        if (reversed > (unsigned long long)LLONG_MAX) {
            fprintf(stderr, "Reversed value exceeds the supported range.\n");
            return EXIT_FAILURE;
        }
        printf("%llu\n", reversed);
    }
    return EXIT_SUCCESS;
}

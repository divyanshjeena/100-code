/*
 * Write a program to find the product of odd digits of a number.
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
    unsigned long long magnitude;
    unsigned long long product = 1ULL;
    unsigned int odd_digits[20];
    size_t odd_count = 0;
    int found = 0;
    if (scanf("%lld", &value) != 1) {
        fprintf(stderr, "Expected an integer.\n");
        return EXIT_FAILURE;
    }
    magnitude = value < 0 ? (unsigned long long)(-(value + 1)) + 1ULL
                          : (unsigned long long)value;
    do {
        unsigned digit = (unsigned)(magnitude % 10ULL);
        if (digit % 2U != 0U) {
            if (product > ULLONG_MAX / digit) {
                fprintf(stderr, "Product exceeds the supported range.\n");
                return EXIT_FAILURE;
            }
            product *= digit;
            odd_digits[odd_count++] = digit;
            found = 1;
        }
        magnitude /= 10ULL;
    } while (magnitude != 0ULL);
    if (!found) {
        puts("1 (no odd digits, assume 1)");
        return EXIT_SUCCESS;
    }
    printf("%llu (", product);
    for (size_t i = odd_count; i > 0; --i) {
        printf("%s%u", i == odd_count ? "" : "*", odd_digits[i - 1]);
    }
    puts(")");
    return EXIT_SUCCESS;
}

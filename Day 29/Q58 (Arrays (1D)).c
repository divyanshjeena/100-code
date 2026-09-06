/*
 * Find the maximum and minimum element in an array.
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
    long long value, maximum, minimum;
    if (scanf("%d", &n) != 1 || n < 1 || n > 1000 ||
        scanf("%lld", &value) != 1) {
        fprintf(stderr, "Expected an array length from 1 to 1000 and its elements.\n");
        return EXIT_FAILURE;
    }
    maximum = minimum = value;
    for (int i = 1; i < n; ++i) {
        if (scanf("%lld", &value) != 1) {
            fprintf(stderr, "Insufficient array elements.\n");
            return EXIT_FAILURE;
        }
        if (value > maximum) maximum = value;
        if (value < minimum) minimum = value;
    }
    printf("Max=%lld, Min=%lld\n", maximum, minimum);
    return EXIT_SUCCESS;
}

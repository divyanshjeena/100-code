/*
 * Find the second largest element in an array.
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
    int n, values[1000];
    if (scanf("%d", &n) != 1 || n < 2 || n > 1000) {
        fprintf(stderr, "At least two array elements are required (maximum 1000).\n");
        return EXIT_FAILURE;
    }
    for (int i = 0; i < n; ++i) {
        if (scanf("%d", &values[i]) != 1) {
            fprintf(stderr, "Insufficient array elements.\n");
            return EXIT_FAILURE;
        }
    }
    int largest = values[0], second = 0, found_second = 0;
    for (int i = 1; i < n; ++i) {
        if (values[i] > largest) {
            second = largest;
            found_second = 1;
            largest = values[i];
        } else if (values[i] < largest && (!found_second || values[i] > second)) {
            second = values[i];
            found_second = 1;
        }
    }
    if (!found_second) {
        fprintf(stderr, "A distinct second-largest element does not exist.\n");
        return EXIT_FAILURE;
    }
    printf("%d\n", second);
    return EXIT_SUCCESS;
}

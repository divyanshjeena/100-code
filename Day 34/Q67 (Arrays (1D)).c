/*
 * Insert an element in an array at a given position.
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
    int n, position, value, values[1001];
    if (scanf("%d", &n) != 1 || n < 1 || n >= 1000) {
        fprintf(stderr, "Array length must be between 1 and 999.\n");
        return EXIT_FAILURE;
    }
    for (int i = 0; i < n; ++i) {
        if (scanf("%d", &values[i]) != 1) {
            fprintf(stderr, "Insufficient array elements.\n");
            return EXIT_FAILURE;
        }
    }
    if (scanf("%d %d", &position, &value) != 2 || position < 0 || position > n) {
        fprintf(stderr, "Insertion index must be between 0 and the array length.\n");
        return EXIT_FAILURE;
    }
    for (int i = n; i > position; --i) values[i] = values[i - 1];
    values[position] = value;
    for (int i = 0; i <= n; ++i) printf("%s%d", i == 0 ? "" : " ", values[i]);
    putchar('\n');
    return EXIT_SUCCESS;
}

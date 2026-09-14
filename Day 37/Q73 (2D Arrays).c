/*
 * Find the sum of each row of a matrix and store it in an array.
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
    int rows, columns;
    long long sums[100];
    if (scanf("%d %d", &rows, &columns) != 2 ||
        rows < 1 || rows > 100 || columns < 1 || columns > 100) {
        fprintf(stderr, "Matrix dimensions must be from 1 to 100.\n");
        return EXIT_FAILURE;
    }
    for (int row = 0; row < rows; ++row) {
        sums[row] = 0;
        for (int column = 0; column < columns; ++column) {
            int value;
            if (scanf("%d", &value) != 1) {
                fprintf(stderr, "Insufficient matrix elements.\n");
                return EXIT_FAILURE;
            }
            sums[row] += value;
        }
    }
    for (int row = 0; row < rows; ++row) printf("%s%lld", row == 0 ? "" : " ", sums[row]);
    putchar('\n');
    return EXIT_SUCCESS;
}

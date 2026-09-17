/*
 * Multiply two matrices.
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
    int rows_a, columns_a, rows_b, columns_b;
    int first[100][100], second[100][100];
    long long result[100][100] = {{0}};
    if (scanf("%d %d", &rows_a, &columns_a) != 2 ||
        rows_a < 1 || rows_a > 100 || columns_a < 1 || columns_a > 100) {
        fprintf(stderr, "First matrix dimensions must be from 1 to 100.\n");
        return EXIT_FAILURE;
    }
    for (int row = 0; row < rows_a; ++row) {
        for (int column = 0; column < columns_a; ++column) {
            if (scanf("%d", &first[row][column]) != 1) {
                fprintf(stderr, "Insufficient elements in the first matrix.\n");
                return EXIT_FAILURE;
            }
        }
    }
    if (scanf("%d %d", &rows_b, &columns_b) != 2 ||
        rows_b < 1 || rows_b > 100 || columns_b < 1 || columns_b > 100 ||
        columns_a != rows_b) {
        fprintf(stderr, "Matrix dimensions are incompatible for multiplication.\n");
        return EXIT_FAILURE;
    }
    for (int row = 0; row < rows_b; ++row) {
        for (int column = 0; column < columns_b; ++column) {
            if (scanf("%d", &second[row][column]) != 1) {
                fprintf(stderr, "Insufficient elements in the second matrix.\n");
                return EXIT_FAILURE;
            }
        }
    }
    for (int row = 0; row < rows_a; ++row) {
        for (int column = 0; column < columns_b; ++column) {
            for (int k = 0; k < columns_a; ++k) {
                result[row][column] += (long long)first[row][k] * second[k][column];
            }
        }
    }
    for (int row = 0; row < rows_a; ++row) {
        for (int column = 0; column < columns_b; ++column) {
            printf("%s%lld", column == 0 ? "" : " ", result[row][column]);
        }
        putchar('\n');
    }
    return EXIT_SUCCESS;
}

/*
 * Add two matrices.
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
    int rows, columns, first[100][100], second[100][100];
    if (scanf("%d %d", &rows, &columns) != 2 ||
        rows < 1 || rows > 100 || columns < 1 || columns > 100) {
        fprintf(stderr, "Matrix dimensions must be from 1 to 100.\n");
        return EXIT_FAILURE;
    }
    for (int row = 0; row < rows; ++row) {
        for (int column = 0; column < columns; ++column) {
            if (scanf("%d", &first[row][column]) != 1) {
                fprintf(stderr, "Insufficient elements in the first matrix.\n");
                return EXIT_FAILURE;
            }
        }
    }
    int other_rows, other_columns;
    if (scanf("%d %d", &other_rows, &other_columns) != 2 ||
        other_rows != rows || other_columns != columns) {
        fprintf(stderr, "Both matrices must have the same dimensions.\n");
        return EXIT_FAILURE;
    }
    for (int row = 0; row < rows; ++row) {
        for (int column = 0; column < columns; ++column) {
            if (scanf("%d", &second[row][column]) != 1) {
                fprintf(stderr, "Insufficient elements in the second matrix.\n");
                return EXIT_FAILURE;
            }
        }
    }
    for (int row = 0; row < rows; ++row) {
        for (int column = 0; column < columns; ++column) {
            printf("%s%d", column == 0 ? "" : " ",
                   first[row][column] + second[row][column]);
        }
        putchar('\n');
    }
    return EXIT_SUCCESS;
}

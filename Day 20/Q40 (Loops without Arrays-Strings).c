/*
 * Write a program to find the 1â€™s complement of a binary number and print it.
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
    char binary[10001];
    size_t length;
    if (scanf("%10000s", binary) != 1) {
        fprintf(stderr, "Expected a binary number.\n");
        return EXIT_FAILURE;
    }
    length = strlen(binary);
    for (size_t i = 0; i < length; ++i) {
        if (binary[i] != '0' && binary[i] != '1') {
            fprintf(stderr, "Input must contain only 0 and 1.\n");
            return EXIT_FAILURE;
        }
        binary[i] = binary[i] == '0' ? '1' : '0';
    }
    puts(binary);
    return EXIT_SUCCESS;
}

/*
 * Create an enum for months and print how many days each month has.
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
enum Month { JAN = 1, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC };

int main(void)
{
    char input[32];
    if (scanf("%31s", input) != 1) {
        fprintf(stderr, "Expected a month abbreviation.\n");
        return EXIT_FAILURE;
    }
    if (strcmp(input, "FEB") == 0) puts("28 or 29 days");
    else if (strcmp(input, "APR") == 0 || strcmp(input, "JUN") == 0 ||
             strcmp(input, "SEP") == 0 || strcmp(input, "NOV") == 0) puts("30 days");
    else if (strcmp(input, "JAN") == 0 || strcmp(input, "MAR") == 0 ||
             strcmp(input, "MAY") == 0 || strcmp(input, "JUL") == 0 ||
             strcmp(input, "AUG") == 0 || strcmp(input, "OCT") == 0 ||
             strcmp(input, "DEC") == 0) puts("31 days");
    else {
        fprintf(stderr, "Unknown month abbreviation.\n");
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

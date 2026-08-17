/*
 * Write a program that accepts a percentage (0-100) and assigns a grade based on the following criteria: 
 * 90-100: Grade A 
 * 80-89: Grade B 
 * 70-79: Grade C 
 * 60-69: Grade D 
 * below 60: Grade F.
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
    double percentage;
    if (scanf("%lf", &percentage) != 1 || !isfinite(percentage) ||
        percentage < 0.0 || percentage > 100.0) {
        fprintf(stderr, "Percentage must be between 0 and 100.\n");
        return EXIT_FAILURE;
    }
    if (percentage >= 90.0) puts("Grade A");
    else if (percentage >= 80.0) puts("Grade B");
    else if (percentage >= 70.0) puts("Grade C");
    else if (percentage >= 60.0) puts("Grade D");
    else puts("Grade F");
    return EXIT_SUCCESS;
}

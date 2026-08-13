/*
 * Write a program to calculate simple and compound interest for given principal, rate, and time.
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
    double principal, rate, years;
    if (scanf("%lf %lf %lf", &principal, &rate, &years) != 3 ||
        !isfinite(principal) || !isfinite(rate) || !isfinite(years) ||
        principal < 0.0 || rate < 0.0 || years < 0.0) {
        fprintf(stderr, "Expected non-negative finite principal, rate, and time.\n");
        return EXIT_FAILURE;
    }
    printf("Simple Interest=%.10g, Compound Interest=%.10g\n",
           principal * rate * years / 100.0,
           principal * (pow(1.0 + rate / 100.0, years) - 1.0));
    return EXIT_SUCCESS;
}

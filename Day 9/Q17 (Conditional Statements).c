/*
 * Write a program to find the roots of a quadratic equation and categorize them.
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
    double a, b, c, discriminant;
    if (scanf("%lf %lf %lf", &a, &b, &c) != 3 ||
        !isfinite(a) || !isfinite(b) || !isfinite(c) || a == 0.0) {
        fprintf(stderr, "Expected finite coefficients and a non-zero quadratic coefficient.\n");
        return EXIT_FAILURE;
    }
    discriminant = b * b - 4.0 * a * c;
    if (discriminant > 0.0) {
        double root1 = (-b + sqrt(discriminant)) / (2.0 * a);
        double root2 = (-b - sqrt(discriminant)) / (2.0 * a);
        printf("Roots are real and different: %.6g, %.6g\n", root1, root2);
    } else if (discriminant == 0.0) {
        printf("Roots are real and same: %.6g\n", -b / (2.0 * a));
    } else {
        puts("Roots are complex");
    }
    return EXIT_SUCCESS;
}

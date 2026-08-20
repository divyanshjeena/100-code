/*
 * Write a program to calculate library fine based on late days as follows: 
 * First 5 days late: â‚¹2/day 
 * Next 5 days late: â‚¹4/day 
 * Next 20 days days late: â‚¹6/day 
 * More than 30 days: Membership Cancelled.
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
    int days;
    int fine;
    if (scanf("%d", &days) != 1 || days < 0) {
        fprintf(stderr, "Late days must be non-negative.\n");
        return EXIT_FAILURE;
    }
    if (days > 30) {
        puts("Membership Cancelled");
        return EXIT_SUCCESS;
    }
    fine = (days < 5 ? days : 5) * 2;
    if (days > 5) fine += (days < 10 ? days - 5 : 5) * 4;
    if (days > 10) fine += (days - 10) * 6;
    printf("Fine â‚¹%d\n", fine);
    return EXIT_SUCCESS;
}

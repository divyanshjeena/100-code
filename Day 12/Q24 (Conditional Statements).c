/*
 * Write a program to calculate electricity bill based on units consumed with these rates: 
 * First 100 units at â‚¹5/unit 
 * Next 100 units at â‚¹7/unit 
 * Next 100 units at â‚¹10/unit 
 * Above at â‚¹12/unit
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
    long long units, bill;
    if (scanf("%lld", &units) != 1 || units < 0 || units > 1000000000LL) {
        fprintf(stderr, "Units must be between 0 and 1000000000.\n");
        return EXIT_FAILURE;
    }
    if (units <= 100) bill = units * 5;
    else if (units <= 200) bill = 500 + (units - 100) * 7;
    else if (units <= 300) bill = 1200 + (units - 200) * 10;
    else bill = 2200 + (units - 300) * 12;
    printf("Bill: â‚¹%lld\n", bill);
    return EXIT_SUCCESS;
}

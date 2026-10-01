/*
 * Write a Program to take a positive integer n as input, and find the pivot integer x such that the sum of all elements between 1 and x inclusively equals the sum of all elements between x and n inclusively. Print the pivot integer x. If no such integer exists, print -1. Assume that it is guaranteed that there will be at most one pivot integer for the given input.
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
    unsigned long long n;
    if (scanf("%llu", &n) != 1 || n == 0ULL || n > 1000000000ULL) {
        fprintf(stderr, "n must be from 1 to 1000000000.\n");
        return EXIT_FAILURE;
    }
    unsigned long long target = n * (n + 1ULL) / 2ULL;
    unsigned long long low = 1ULL, high = n;
    while (low <= high) {
        unsigned long long middle = low + (high - low) / 2ULL;
        unsigned long long square = middle * middle;
        if (square == target) {
            printf("%llu\n", middle);
            return EXIT_SUCCESS;
        }
        if (square < target) low = middle + 1ULL;
        else high = middle - 1ULL;
    }
    puts("-1");
    return EXIT_SUCCESS;
}

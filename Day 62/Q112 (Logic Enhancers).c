/*
 * Write a program to take an integer array arr as input. The task is to find the maximum sum of any contiguous subarray using Kadane's algorithm. Print the maximum sum as output. If all elements are negative, print the largest (least negative) element.
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
    int n, value;
    long long maximum_ending, maximum_sum;
    if (scanf("%d", &n) != 1 || n < 1 || n > 1000 ||
        scanf("%d", &value) != 1) {
        fprintf(stderr, "Expected 1 to 1000 array elements.\n");
        return EXIT_FAILURE;
    }
    maximum_ending = maximum_sum = value;
    for (int i = 1; i < n; ++i) {
        if (scanf("%d", &value) != 1) {
            fprintf(stderr, "Insufficient array elements.\n");
            return EXIT_FAILURE;
        }
        long long extended = maximum_ending + value;
        maximum_ending = extended > value ? extended : value;
        if (maximum_ending > maximum_sum) maximum_sum = maximum_ending;
    }
    printf("%lld\n", maximum_sum);
    return EXIT_SUCCESS;
}

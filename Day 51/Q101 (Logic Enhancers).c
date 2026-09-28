/*
 * Write a Program to take a sorted array(say nums[]) and an integer (say target) as inputs. The elements in the sorted array might be repeated. You need to print the first and last occurrence of the target and print the index of first and last occurrence. Print -1, -1 if the target is not present.
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
    int n, target, values[1000];
    if (scanf("%d", &n) != 1 || n < 1 || n > 1000) {
        fprintf(stderr, "Array length must be between 1 and 1000.\n");
        return EXIT_FAILURE;
    }
    for (int i = 0; i < n; ++i) {
        if (scanf("%d", &values[i]) != 1 ||
            (i > 0 && values[i] < values[i - 1])) {
            fprintf(stderr, "Expected a sorted array.\n");
            return EXIT_FAILURE;
        }
    }
    if (scanf("%d", &target) != 1) {
        fprintf(stderr, "Expected a target value.\n");
        return EXIT_FAILURE;
    }
    int low = 0, high = n, first = -1;
    while (low < high) {
        int middle = low + (high - low) / 2;
        if (values[middle] < target) low = middle + 1;
        else high = middle;
    }
    if (low < n && values[low] == target) first = low;
    int last = -1;
    if (first >= 0) {
        low = first;
        high = n;
        while (low < high) {
            int middle = low + (high - low) / 2;
            if (values[middle] <= target) low = middle + 1;
            else high = middle;
        }
        last = low - 1;
    }
    printf("%d,%d\n", first, last);
    return EXIT_SUCCESS;
}

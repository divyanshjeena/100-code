/*
 * A file numbers.txt contains a list of integers separated by spaces. Read all integers, compute their sum and average, and print both.
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
    FILE *file = fopen("numbers.txt", "r");
    if (file == NULL) {
        perror("Could not open numbers.txt");
        return EXIT_FAILURE;
    }
    long long value, sum = 0;
    unsigned long long count = 0;
    while (fscanf(file, "%lld", &value) == 1) {
        if ((value > 0 && sum > LLONG_MAX - value) ||
            (value < 0 && sum < LLONG_MIN - value)) {
            fprintf(stderr, "Sum exceeds the supported range.\n");
            fclose(file);
            return EXIT_FAILURE;
        }
        sum += value;
        ++count;
    }
    if (!feof(file)) {
        fprintf(stderr, "numbers.txt contains invalid data.\n");
        fclose(file);
        return EXIT_FAILURE;
    }
    if (ferror(file)) {
        perror("Could not read numbers.txt");
        fclose(file);
        return EXIT_FAILURE;
    }
    if (fclose(file) != 0) {
        perror("Could not close numbers.txt");
        return EXIT_FAILURE;
    }
    if (count == 0) {
        fprintf(stderr, "numbers.txt contains no integers.\n");
        return EXIT_FAILURE;
    }
    printf("Sum = %lld\nAverage = %.2f\n", sum, (double)sum / (double)count);
    return EXIT_SUCCESS;
}

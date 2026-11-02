/*
 * Use enum to represent menu choices (ADD, SUBTRACT, MULTIPLY) and perform operations using switch.
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
enum Operation { ADD, SUBTRACT, MULTIPLY };

int main(void)
{
    char input[32];
    long long a, b;
    if (scanf("%31s %lld %lld", input, &a, &b) != 3) {
        fprintf(stderr, "Expected an operation name and two integers.\n");
        return EXIT_FAILURE;
    }
    enum Operation operation;
    if (strcmp(input, "ADD") == 0) operation = ADD;
    else if (strcmp(input, "SUBTRACT") == 0) operation = SUBTRACT;
    else if (strcmp(input, "MULTIPLY") == 0) operation = MULTIPLY;
    else {
        fprintf(stderr, "Unknown operation.\n");
        return EXIT_FAILURE;
    }
    switch (operation) {
    case ADD: printf("%lld\n", a + b); break;
    case SUBTRACT: printf("%lld\n", a - b); break;
    case MULTIPLY: printf("%lld\n", a * b); break;
    }
    return EXIT_SUCCESS;
}

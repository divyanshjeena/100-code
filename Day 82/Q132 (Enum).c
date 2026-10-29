/*
 * Define an enum for traffic lights (RED, YELLOW, GREEN) and print 'Stop', 'Wait', or 'Go' based on its value.
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
enum TrafficLight { RED, YELLOW, GREEN };

int main(void)
{
    char input[32];
    if (scanf("%31s", input) != 1) {
        fprintf(stderr, "Expected RED, YELLOW, or GREEN.\n");
        return EXIT_FAILURE;
    }
    if (strcmp(input, "RED") == 0) puts("Stop");
    else if (strcmp(input, "YELLOW") == 0) puts("Wait");
    else if (strcmp(input, "GREEN") == 0) puts("Go");
    else {
        fprintf(stderr, "Unknown traffic light value.\n");
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

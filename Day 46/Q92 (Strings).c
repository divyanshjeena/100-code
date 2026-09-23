/*
 * Find the first repeating lowercase alphabet in a string.
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
    char text[4096];
    int counts[26] = {0};
    if (fgets(text, sizeof text, stdin) == NULL) {
        fprintf(stderr, "Expected a lowercase string.\n");
        return EXIT_FAILURE;
    }
    for (size_t i = 0; text[i] != '\0' && text[i] != '\n'; ++i) {
        if (text[i] < 'a' || text[i] > 'z') {
            fprintf(stderr, "Input must contain only lowercase letters.\n");
            return EXIT_FAILURE;
        }
        if (++counts[text[i] - 'a'] == 2) {
            printf("%c\n", text[i]);
            return EXIT_SUCCESS;
        }
    }
    puts("No repeating lowercase alphabet");
    return EXIT_SUCCESS;
}

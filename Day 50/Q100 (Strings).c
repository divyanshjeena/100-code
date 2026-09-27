/*
 * Print all sub-strings of a string.
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
    char text[1024];
    if (fgets(text, sizeof text, stdin) == NULL) {
        fprintf(stderr, "Expected a non-empty string.\n");
        return EXIT_FAILURE;
    }
    text[strcspn(text, "\n")] = '\0';
    size_t length = strlen(text);
    if (length == 0) {
        fprintf(stderr, "Expected a non-empty string.\n");
        return EXIT_FAILURE;
    }
    for (size_t start = 0; start < length; ++start) {
        for (size_t end = start + 1; end <= length; ++end) {
            printf("%s%.*s", start == 0 && end == 1 ? "" : ",",
                   (int)(end - start), text + start);
        }
    }
    putchar('\n');
    return EXIT_SUCCESS;
}

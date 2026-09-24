/*
 * Find the longest word in a sentence.
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
    char text[4096], longest[4096] = "";
    if (fgets(text, sizeof text, stdin) == NULL) {
        fprintf(stderr, "Expected a sentence.\n");
        return EXIT_FAILURE;
    }
    size_t best_length = 0;
    size_t i = 0;
    while (text[i] != '\0') {
        while (isspace((unsigned char)text[i])) ++i;
        size_t start = i;
        while (text[i] != '\0' && !isspace((unsigned char)text[i])) ++i;
        size_t length = i - start;
        if (length > best_length) {
            memcpy(longest, text + start, length);
            longest[length] = '\0';
            best_length = length;
        }
    }
    puts(longest);
    return EXIT_SUCCESS;
}

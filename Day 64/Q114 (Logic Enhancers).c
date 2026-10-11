/*
 * Write a program to take a string s as input. The task is to find the length of the longest substring without repeating characters. Print the length as output.
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
    size_t last_seen[256];
    for (size_t i = 0; i < 256; ++i) last_seen[i] = SIZE_MAX;
    if (fgets(text, sizeof text, stdin) == NULL) {
        fprintf(stderr, "Expected a string.\n");
        return EXIT_FAILURE;
    }
    size_t start = 0, longest = 0;
    for (size_t i = 0; text[i] != '\0' && text[i] != '\n'; ++i) {
        unsigned char ch = (unsigned char)text[i];
        if (last_seen[ch] != SIZE_MAX && last_seen[ch] >= start) {
            start = last_seen[ch] + 1;
        }
        last_seen[ch] = i;
        if (i - start + 1 > longest) longest = i - start + 1;
    }
    printf("%zu\n", longest);
    return EXIT_SUCCESS;
}

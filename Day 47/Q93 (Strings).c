/*
 * Check if two strings are anagrams of each other.
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
    char first[4096], second[4096];
    int counts[256] = {0};
    if (fgets(first, sizeof first, stdin) == NULL ||
        fgets(second, sizeof second, stdin) == NULL) {
        fprintf(stderr, "Expected two strings on separate lines.\n");
        return EXIT_FAILURE;
    }
    first[strcspn(first, "\n")] = '\0';
    second[strcspn(second, "\n")] = '\0';
    for (size_t i = 0; first[i] != '\0'; ++i) ++counts[(unsigned char)first[i]];
    for (size_t i = 0; second[i] != '\0'; ++i) --counts[(unsigned char)second[i]];
    for (int i = 0; i < 256; ++i) {
        if (counts[i] != 0) {
            puts("Not anagrams");
            return EXIT_SUCCESS;
        }
    }
    puts("Anagrams");
    return EXIT_SUCCESS;
}

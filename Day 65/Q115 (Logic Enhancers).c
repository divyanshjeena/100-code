/*
 * Write a program to take two strings s and t as inputs (assume all characters are lowercase). The task is to determine if s and t are valid anagrams, meaning they contain the same characters with the same frequencies. Print "Anagram" if they are, otherwise "Not Anagram".
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
    int counts[26] = {0};
    if (fgets(first, sizeof first, stdin) == NULL ||
        fgets(second, sizeof second, stdin) == NULL) {
        fprintf(stderr, "Expected two lowercase strings on separate lines.\n");
        return EXIT_FAILURE;
    }
    for (size_t i = 0; first[i] != '\0' && first[i] != '\n'; ++i) {
        if (first[i] < 'a' || first[i] > 'z') {
            fprintf(stderr, "Strings must contain only lowercase letters.\n");
            return EXIT_FAILURE;
        }
        ++counts[first[i] - 'a'];
    }
    for (size_t i = 0; second[i] != '\0' && second[i] != '\n'; ++i) {
        if (second[i] < 'a' || second[i] > 'z') {
            fprintf(stderr, "Strings must contain only lowercase letters.\n");
            return EXIT_FAILURE;
        }
        --counts[second[i] - 'a'];
    }
    int anagram = 1;
    for (int i = 0; i < 26; ++i) if (counts[i] != 0) anagram = 0;
    puts(anagram ? "Anagram" : "Not Anagram");
    return EXIT_SUCCESS;
}

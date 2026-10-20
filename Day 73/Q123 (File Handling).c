/*
 * Read a text file and count the total number of characters, words, and lines. A word is defined as a sequence of non-space characters separated by spaces or newlines.
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
    char filename[256];
    if (scanf("%255s", filename) != 1) {
        fprintf(stderr, "Expected a filename.\n");
        return EXIT_FAILURE;
    }
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Could not open input file");
        return EXIT_FAILURE;
    }
    unsigned long long characters = 0, words = 0, lines = 0;
    int in_word = 0, ch, last = EOF;
    while ((ch = fgetc(file)) != EOF) {
        ++characters;
        if (ch == '\n') ++lines;
        if (isspace((unsigned char)ch)) in_word = 0;
        else if (!in_word) {
            ++words;
            in_word = 1;
        }
        last = ch;
    }
    if (ferror(file)) {
        perror("Could not read input file");
        fclose(file);
        return EXIT_FAILURE;
    }
    if (characters > 0 && last != '\n') ++lines;
    if (fclose(file) != 0) {
        perror("Could not close input file");
        return EXIT_FAILURE;
    }
    printf("Characters: %llu\nWords: %llu\nLines: %llu\n", characters, words, lines);
    return EXIT_SUCCESS;
}

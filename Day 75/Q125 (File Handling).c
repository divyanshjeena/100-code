/*
 * Open an existing file in append mode and allow the user to enter a new line of text. Append the text at the end without overwriting existing content.
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
    char filename[256], text[4096];
    if (scanf("%255s", filename) != 1) {
        fprintf(stderr, "Expected a filename.\n");
        return EXIT_FAILURE;
    }
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF) { }
    if (fgets(text, sizeof text, stdin) == NULL) {
        fprintf(stderr, "Expected a line of text to append.\n");
        return EXIT_FAILURE;
    }
    FILE *file = fopen(filename, "a");
    if (file == NULL) {
        perror("Could not open file for appending");
        return EXIT_FAILURE;
    }
    int failed = fputs(text, file) == EOF;
    if (text[strlen(text) - 1] != '\n' && fputc('\n', file) == EOF) failed = 1;
    if (fclose(file) != 0) failed = 1;
    if (failed) {
        fprintf(stderr, "Could not append to file.\n");
        return EXIT_FAILURE;
    }
    puts("File updated successfully with appended text.");
    return EXIT_SUCCESS;
}

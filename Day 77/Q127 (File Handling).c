/*
 * Write a program that reads text from input.txt, converts all lowercase letters to uppercase, and writes the result to output.txt.
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
    FILE *source = fopen("input.txt", "r");
    if (source == NULL) {
        perror("Could not open input.txt");
        return EXIT_FAILURE;
    }
    FILE *destination = fopen("output.txt", "w");
    if (destination == NULL) {
        perror("Could not open output.txt");
        fclose(source);
        return EXIT_FAILURE;
    }
    int ch, failed = 0;
    while ((ch = fgetc(source)) != EOF) {
        if (fputc(toupper((unsigned char)ch), destination) == EOF) {
            failed = 1;
            break;
        }
    }
    if (ferror(source)) failed = 1;
    if (fclose(source) != 0) failed = 1;
    if (fclose(destination) != 0) failed = 1;
    if (failed) {
        fprintf(stderr, "Could not convert input.txt.\n");
        return EXIT_FAILURE;
    }
    puts("Converted text written to output.txt");
    return EXIT_SUCCESS;
}

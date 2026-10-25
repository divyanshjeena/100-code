/*
 * Read a text file and count how many vowels and consonants are in the file. Ignore digits and special characters.
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
    unsigned long long vowels = 0, consonants = 0;
    int ch;
    while ((ch = fgetc(file)) != EOF) {
        unsigned char lower = (unsigned char)tolower((unsigned char)ch);
        if (lower >= 'a' && lower <= 'z') {
            if (lower == 'a' || lower == 'e' || lower == 'i' ||
                lower == 'o' || lower == 'u') ++vowels;
            else ++consonants;
        }
    }
    if (ferror(file)) {
        perror("Could not read input file");
        fclose(file);
        return EXIT_FAILURE;
    }
    if (fclose(file) != 0) {
        perror("Could not close input file");
        return EXIT_FAILURE;
    }
    printf("Vowels: %llu\nConsonants: %llu\n", vowels, consonants);
    return EXIT_SUCCESS;
}

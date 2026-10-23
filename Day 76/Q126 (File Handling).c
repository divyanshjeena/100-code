/*
 * Ask the user for a filename. Check if it exists by trying to open it in read mode. If the file pointer is NULL, print an error message; otherwise, read and display its content.
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
    char filename[256], line[1024];
    if (scanf("%255s", filename) != 1) {
        fprintf(stderr, "Expected a filename.\n");
        return EXIT_FAILURE;
    }
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        puts("Error: File does not exist!");
        return EXIT_FAILURE;
    }
    puts("File opened successfully.");
    while (fgets(line, sizeof line, file) != NULL) fputs(line, stdout);
    if (ferror(file)) {
        perror("Could not read file");
        fclose(file);
        return EXIT_FAILURE;
    }
    if (fclose(file) != 0) {
        perror("Could not close file");
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

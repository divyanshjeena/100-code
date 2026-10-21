/*
 * Take two filenames from the user â€“ a source file and a destination file. Copy all the content from the source file to the destination file using fgetc() and fputc().
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
    char source_name[256], destination_name[256];
    if (scanf("%255s %255s", source_name, destination_name) != 2) {
        fprintf(stderr, "Expected source and destination filenames.\n");
        return EXIT_FAILURE;
    }
    if (strcmp(source_name, destination_name) == 0) {
        fprintf(stderr, "Source and destination filenames must differ.\n");
        return EXIT_FAILURE;
    }
    FILE *source = fopen(source_name, "rb");
    if (source == NULL) {
        perror("Could not open source file");
        return EXIT_FAILURE;
    }
    FILE *destination = fopen(destination_name, "wb");
    if (destination == NULL) {
        perror("Could not open destination file");
        fclose(source);
        return EXIT_FAILURE;
    }
    int ch, failed = 0;
    while ((ch = fgetc(source)) != EOF) {
        if (fputc(ch, destination) == EOF) {
            failed = 1;
            break;
        }
    }
    if (ferror(source)) failed = 1;
    if (fclose(source) != 0) failed = 1;
    if (fclose(destination) != 0) failed = 1;
    if (failed) {
        fprintf(stderr, "File copy failed.\n");
        return EXIT_FAILURE;
    }
    printf("File copied successfully to %s\n", destination_name);
    return EXIT_SUCCESS;
}

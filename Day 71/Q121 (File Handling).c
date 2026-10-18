/*
 * Write a C program that creates a text file named info.txt in write mode. The program should take the userâ€™s name and age as input, and write them to the file using fprintf(). After writing, display a message confirming that the data was successfully saved.
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
    char name[128];
    int age;
    if (scanf("%127s %d", name, &age) != 2 || age < 0 || age > 150) {
        fprintf(stderr, "Expected a one-word name and age from 0 to 150.\n");
        return EXIT_FAILURE;
    }
    FILE *file = fopen("info.txt", "w");
    if (file == NULL) {
        perror("Could not create info.txt");
        return EXIT_FAILURE;
    }
    int write_failed = fprintf(file, "Name: %s\nAge: %d\n", name, age) < 0;
    if (fclose(file) != 0 || write_failed) {
        perror("Could not write info.txt");
        return EXIT_FAILURE;
    }
    puts("File created successfully! Data written to info.txt");
    return EXIT_SUCCESS;
}

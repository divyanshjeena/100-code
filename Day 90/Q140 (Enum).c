/*
 * Define a struct with enum Gender and print person's gender.
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
enum Gender { MALE, FEMALE, OTHER };
struct Person { enum Gender gender; };

int main(void)
{
    char input[32];
    struct Person person;
    if (scanf("%31s", input) != 1) {
        fprintf(stderr, "Expected MALE, FEMALE, or OTHER.\n");
        return EXIT_FAILURE;
    }
    if (strcmp(input, "MALE") == 0) person.gender = MALE;
    else if (strcmp(input, "FEMALE") == 0) person.gender = FEMALE;
    else if (strcmp(input, "OTHER") == 0) person.gender = OTHER;
    else {
        fprintf(stderr, "Unknown gender.\n");
        return EXIT_FAILURE;
    }
    static const char *labels[] = {"Male", "Female", "Other"};
    puts(labels[person.gender]);
    return EXIT_SUCCESS;
}

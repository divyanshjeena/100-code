/*
 * Print initials of a name with the surname displayed in full.
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
    char name[4096], words[100][128];
    int count = 0;
    if (fgets(name, sizeof name, stdin) == NULL) {
        fprintf(stderr, "Expected a name.\n");
        return EXIT_FAILURE;
    }
    size_t i = 0;
    while (name[i] != '\0') {
        while (isspace((unsigned char)name[i])) ++i;
        if (name[i] == '\0') break;
        if (count == 100) {
            fprintf(stderr, "Name contains too many words.\n");
            return EXIT_FAILURE;
        }
        size_t length = 0;
        while (name[i] != '\0' && !isspace((unsigned char)name[i])) {
            if (length + 1 >= sizeof words[0]) {
                fprintf(stderr, "A name component is too long.\n");
                return EXIT_FAILURE;
            }
            words[count][length++] = name[i++];
        }
        words[count++][length] = '\0';
    }
    if (count == 0) {
        fprintf(stderr, "Name must not be empty.\n");
        return EXIT_FAILURE;
    }
    if (count == 1) {
        puts(words[0]);
    } else {
        for (int word = 0; word < count - 1; ++word) printf("%c.", words[word][0]);
        printf(" %s\n", words[count - 1]);
    }
    return EXIT_SUCCESS;
}

/*
 * Create Employee structure with nested Date structure for joining date and print details.
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
struct Date { int day; int month; int year; };
struct Employee { char name[128]; int id; struct Date joining_date; };

int main(void)
{
    struct Employee employee;
    if (scanf("%127s %d %d %d %d", employee.name, &employee.id,
              &employee.joining_date.day, &employee.joining_date.month,
              &employee.joining_date.year) != 5 ||
        employee.joining_date.day < 1 || employee.joining_date.day > 31 ||
        employee.joining_date.month < 1 || employee.joining_date.month > 12 ||
        employee.joining_date.year < 1) {
        fprintf(stderr, "Expected employee details and a valid joining date.\n");
        return EXIT_FAILURE;
    }
    printf("Name: %s | ID: %d | Joining Date: %02d/%02d/%04d\n",
           employee.name, employee.id, employee.joining_date.day,
           employee.joining_date.month, employee.joining_date.year);
    return EXIT_SUCCESS;
}

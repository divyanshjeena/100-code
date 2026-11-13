/*
 * Store employee data in a binary file using fwrite() and read using fread().
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
struct Employee { char name[128]; int id; double salary; };

int main(void)
{
    struct Employee employee;
    if (scanf("%127s %d %lf", employee.name, &employee.id, &employee.salary) != 3 ||
        !isfinite(employee.salary) || employee.salary < 0.0) {
        fprintf(stderr, "Expected employee name, ID, and non-negative salary.\n");
        return EXIT_FAILURE;
    }
    FILE *file = fopen("employee.bin", "wb");
    if (file == NULL) {
        perror("Could not create employee.bin");
        return EXIT_FAILURE;
    }
    int failed = fwrite(&employee, sizeof employee, 1, file) != 1;
    if (fclose(file) != 0) failed = 1;
    if (failed) {
        fprintf(stderr, "Could not write employee record.\n");
        return EXIT_FAILURE;
    }
    file = fopen("employee.bin", "rb");
    if (file == NULL) {
        perror("Could not read employee.bin");
        return EXIT_FAILURE;
    }
    struct Employee loaded;
    failed = fread(&loaded, sizeof loaded, 1, file) != 1;
    if (fclose(file) != 0) failed = 1;
    if (failed) {
        fprintf(stderr, "Could not read employee record.\n");
        return EXIT_FAILURE;
    }
    printf("Name: %s | ID: %d | Salary: %.2f\n",
           loaded.name, loaded.id, loaded.salary);
    return EXIT_SUCCESS;
}

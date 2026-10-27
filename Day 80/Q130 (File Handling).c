/*
 * Store multiple student records (name, roll number, marks) into a file using fprintf(). Then read them using fscanf() and display each record.
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
    int count;
    if (scanf("%d", &count) != 1 || count < 1 || count > 100) {
        fprintf(stderr, "Student count must be between 1 and 100.\n");
        return EXIT_FAILURE;
    }
    FILE *file = fopen("students.txt", "w");
    if (file == NULL) {
        perror("Could not create students.txt");
        return EXIT_FAILURE;
    }
    for (int i = 0; i < count; ++i) {
        char name[128];
        int roll;
        double marks;
        if (scanf("%127s %d %lf", name, &roll, &marks) != 3 ||
            !isfinite(marks) || marks < 0.0 || marks > 100.0 ||
            fprintf(file, "%s %d %.2f\n", name, roll, marks) < 0) {
            fprintf(stderr, "Invalid student record or file write failure.\n");
            fclose(file);
            return EXIT_FAILURE;
        }
    }
    if (fclose(file) != 0) {
        perror("Could not close students.txt");
        return EXIT_FAILURE;
    }
    file = fopen("students.txt", "r");
    if (file == NULL) {
        perror("Could not reopen students.txt");
        return EXIT_FAILURE;
    }
    char name[128];
    int roll;
    double marks;
    while (fscanf(file, "%127s %d %lf", name, &roll, &marks) == 3) {
        printf("Name: %s | Roll: %d | Marks: %.2f\n", name, roll, marks);
    }
    if (ferror(file)) {
        perror("Could not read students.txt");
        fclose(file);
        return EXIT_FAILURE;
    }
    if (fclose(file) != 0) {
        perror("Could not close students.txt");
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

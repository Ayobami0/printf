#ifndef MAIN_H_
#define MAIN_H_

#include <stdarg.h>
#include <unistd.h>

typedef struct {
	char specifier;
	int (*s_handler)(va_list ap);
} sp_h;

int num_len(int n);
void itoa(int n, char *str_rep);
int _strlen(const char *str);
int handleSpecifier(const char *specifier, va_list ap);
void write_to_stdout(const char *buf, int size);
int _printf(const char *format, ...);
int char_s(va_list ap);
int str_s(va_list ap);
int int_s(va_list ap);
int float_s(va_list ap);
#endif /* MAIN_H_ */

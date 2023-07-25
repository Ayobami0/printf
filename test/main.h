#ifndef MAIN_H_
#define MAIN_H_

#include <stdarg.h>
#include <unistd.h>

#define BUFFSIZE 1024

typedef struct {
	char specifier;
	int (*s_handler)(va_list ap, char *str_buf, unsigned int *buf_idx);
} sp_h;

int num_len(int n);
void itoa(int n, char *str_rep);
int _strlen(const char *str);
int handleSpecifier(const char *specifier, va_list ap, char *str_buf, unsigned int *buf_idx);
void write_to_stdout(const char *buf, int size);
int _printf(const char *format, ...);
int char_s(va_list ap, char *str_buf, unsigned int *buf_idx);
int str_s(va_list ap, char *str_buf, unsigned int *buf_idx);
int int_s(va_list ap, char *str_buf, unsigned int *buf_idx);
int percent_s(va_list __attribute__((__unused__))ap, char *str_buf, unsigned int *buf_idx);
int float_s(va_list ap, char *str_buf, unsigned int *buf_idx);
#endif /* MAIN_H_ */

#ifndef MAIN_H
#define MAIN_H
#include <unistd.h>
#include <stdarg.h>
#define BUFFER 1024
int _printf(const char *format, ...);
char *cast_char(va_list);
char *cast_string(va_list);
char *cast_percent(va_list);
char *cast_int(va_list na);
char *cast_binary(va_list);
char *cast_uint(va_list ui);
char *cast_uoct(va_list ui);
char *cast_uhex(va_list ui);
char *cast_uHex(va_list ui);
void _output(char *str, int str_len);
int _len(char *str);
char *cast_cs(char c);
char *_memcpy(char *dest, char *src, unsigned int n);
char *_not(char t);
char *_strcat(char *dest, char *src);
void _parse(va_list vp, char y, char *p_str, char *p);
char *_parse_num(int n, char *num_buf);
void rev_string(char *s, int len);
char *_parse_num(int n, char* num_buf);
char *_parse_uint(unsigned int n, char *num_buf);
char *_parse_uhex(unsigned int n, char *num_buf, int hex_type);
char *_parse_uoct(unsigned int n, char *num_buf);
/**
 * struct format_specifier_and_func - hold the type and function
 * @_type: specifier type
 * @f: function to return the string equivalent of the type
 */
typedef struct format_specifier_and_func
{
	char _type;
	char *(*f)(va_list);
} s_f;
#endif

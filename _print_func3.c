#include "main.h"
#include <stdarg.h>

char *cast_uint(va_list ui)
{
	unsigned int num;
	char buffer[32];

	num = va_arg(ui, unsigned int);

	return (_parse_uint(num, buffer));
}

char *cast_uoct(va_list ui)
{
	unsigned int num;
	char buffer[32];

	num = va_arg(ui, unsigned int);

	return (_parse_uoct(num, buffer));
}
char *cast_uhex(va_list ui)
{
	unsigned int num;
	char buffer[32];

	num = va_arg(ui, unsigned int);

	return (_parse_uhex(num, buffer, 1));
}
char *cast_uHex(va_list ui)
{
	unsigned int num;
	char buffer[32];

	num = va_arg(ui, unsigned int);

	return (_parse_uhex(num, buffer, 0));
}

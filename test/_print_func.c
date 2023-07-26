#include "main.h"
#include <stdio.h>
/**
 * cast_char - convert char to string
 * @c: char to be converted
 * Return: string
 */
char *cast_char(va_list c)
{
	char str[2];
	char *p;

	p = str;
	*p = va_arg(c, int);
	*(p + 1) = '\0';
	return (p);
}

/**
 * cast_string - return string
 * @str: string to be returned
 * Return: string
 */

char *cast_string(va_list str)
{
	char *p = va_arg(str, char *);

	if (p == NULL)
		return ("(null)");
	return (p);
}

/**
 * cast_percent - convert char to string
 * @pc: nothing
 * Return: string
 */
char *cast_percent(va_list pc)
{
	char str[2];
	char *p;

	(void)pc;
	p = str;
	*p = '%';
	*(p + 1) = '\0';
	return (p);
}

/**
 * cast_int - convert int to string
 * @na: decimal argument
 * Return: string
 */
char *cast_int(va_list na)
{
	char int_buf[32];
	int num;

	num = va_arg(na, int);

	return (_parse_num(num, int_buf));
}

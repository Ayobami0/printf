#include "main.h"
#include <stdarg.h>

/**
 * cast_uint - Convert an unsigned integer to its string representation.
 * @ui: va_list containing the unsigned integer to convert.
 *
 * Return: Pointer to buffer with the string representation.
 */
char *cast_uint(va_list ui)
{
	unsigned int num;
	char buffer[32];

	num = va_arg(ui, unsigned int);

	return (_parse_uint(num, buffer));
}
/**
 * cast_uoct - Convert an unsigned integer to its octal string representation.
 * @ui: va_list containing the unsigned integer to convert.
 *
 * Return: Pointer to buffer with the octal representation.
 */
char *cast_uoct(va_list ui)
{
	unsigned int num;
	char buffer[32];

	num = va_arg(ui, unsigned int);

	return (_parse_uoct(num, buffer));
}
/**
 * cast_uhex - Convert an unsigned integer to lowercase
 * hexadecimal representation.
 * @ui: va_list containing the unsigned integer to convert.
 *
 * Return: Pointer to buffer with the lowercase hexadecimal representation.
 */
char *cast_uhex(va_list ui)
{
	unsigned int num;
	char buffer[32];

	num = va_arg(ui, unsigned int);

	return (_parse_uhex(num, buffer, 1));
}
/**
 * cast_uHex - Convert an unsigned integer to
 * uppercase hexadecimal representation.
 * @ui: va_list containing the unsigned integer to convert.
 *
 * Return: Pointer to buffer with the uppercase hexadecimal representation.
 */
char *cast_uHex(va_list ui)
{
	unsigned int num;
	char buffer[32];

	num = va_arg(ui, unsigned int);

	return (_parse_uhex(num, buffer, 0));
}

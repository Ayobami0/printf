#include "main.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * handleSpecifier - Handle format specifiers and call the correct function.
 * @specifier: A pointer to a string containing the format specifier character
 * @ap: va_list containing the arguments corresponding to the format specifier.
 *
 * This function takes a format specifier character and
 * a va_list containing the arguments corresponding to the specifier.
 * It matches the specifier character with the
 * appropriate handler function and calls that
 * function to process the argument.
 * The supported format specifiers and their corresponding handler functions are:
 *   - 'c': char_s - Print a character from va_list to standard output.
 *   - 's': str_s - Print a string from va_list to standard output.
 *   - 'i' or 'd': int_s - Convert and print an integer from va_list to standard output.
 *   - '%': Print a '%' character to standard output.
 *
 * Return: The number of characters printed for the corresponding specifier,
 *         or 0 if the specifier is not recognized or an error occurs.
 */
int handleSpecifier(const char *specifier, va_list ap)
{
	sp_h specifiers[] = {
		{'c', char_s},
		{'s', str_s},
		{'i', int_s},
	};

	switch (*specifier)
	{
		case 'c':
			return (specifiers->s_handler(ap));
		case 's':
			return (specifiers[1].s_handler(ap));
		case '%':
			write_to_stdout("%", 1);
			return (1);
		case 'd':
		case 'i':
			return (specifiers[2].s_handler(ap));
		default:
			return (0);
	}
}
/**
 * char_s - Print a character from va_list to standard output.
 * @ap: va_list containing the character to be printed.
 *
 * This function takes a va_list containing a character
 * and prints it to the standard output
 * using the write_to_stdout function.
 *
 * Return: The number of characters printed (always 1).
 */
int char_s(va_list ap)
{
	char c;

	c = va_arg(ap, int);
	write_to_stdout(&c, 1);

	return (1);
}

/**
 * str_s - Convert and print a string from va_list to standard output.
 * @ap: va_list containing the string to be printed.
 *
 * This function takes a va_list containing a string and prints it to the
 * standard output using the write_to_stdout function. If the string is NULL,
 * it will print "(null)" to the standard output.
 *
 * Return: The number of characters printed (excluding the null byte),
 *         or 0 if the string is NULL.
 */
int str_s(va_list ap)
{
	char *str;
	unsigned int len;

	str = va_arg(ap, char*);
	if (str == NULL)
		write_to_stdout("(null)", 6);
	len = _strlen(str);
	write_to_stdout(str, len);

	return (len);
}

/**
 * int_s - Convert and print an integer from va_list to standard output.
 * @ap: va_list containing the integer to be converted and printed.
 *
 * Description:
 * This function takes a va_list containing an integer and converts it
 * to a string representation using the itoa function. The resulting string
 * is then written to the standard output using the write_to_stdout function.
 *
 * Return: The number of characters printed (excluding the null byte),
 *         or 0 if there was an error or if the integer is 0.
 */
int int_s(va_list ap)
{
	int is_negative, int_val, len;
	char *int_buf; /*Buffer to hold the int string*/

	is_negative = 0;
	int_val = va_arg(ap, int);
	if (int_val < 0)
		is_negative = 1;
	int_buf = malloc(num_len(int_val) + 1 + is_negative);
	if (int_buf == NULL)
		return (0);
	itoa(int_val, int_buf);
	len = _strlen(int_buf);
	write_to_stdout(int_buf, len);
	free(int_buf);

	return (len);
}

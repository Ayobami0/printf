#include "main.h"
#include <stdlib.h>
/**
 * _printf - Custom printf function that prints
 * formatted output to standard output.
 * @format: A pointer to a null-terminated string containing the
 *          format string.
 *          This string may contain format specifiers like %s, %c, %d, etc.
 *          See supported specifiers in handleSpecifier function
 *          documentation.
 * @...: A variable number of arguments corresponding
 *       to the format specifiers.
 *
 * This function mimics the behavior of the standard
 * printf function and prints formatted output to the
 * standard output. It supports the following format specifiers:
 *   - %c: Prints a single character from the va_list.
 *   - %s: Prints a null-terminated string from the va_list.
 *   - %d or %i: Prints a signed integer from the va_list.
 *   - %%: Prints a single '%' character.
 * If the format is NULL, the function will print
 * "(null)" to the standard output.
 *
 * Return: The total number of characters printed (excluding the null byte),
 *         or 0 if the format string is NULL or an error occurs.
 */
int _printf(const char *format, ...)
{
	int str_count, i;
	va_list ap;

	if (format == NULL)
	{
		write_to_stdout("(null)", 6);
		return (0);
	}
	va_start(ap, format);

	str_count = 0;
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			/*If a format specifier is found run the handler*/
			str_count += handleSpecifier(format + i + 1, ap);
			i = i + 1;
		}
		else
		{
			write_to_stdout(format + i, 1);
			str_count++;
		}
	}

	va_end(ap);
	return (str_count);
}

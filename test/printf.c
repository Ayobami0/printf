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
	unsigned int i, buf_idx;
	int specifier_return;
	va_list ap;
	char str_buf[BUFFSIZE];

	if (format == NULL)
	{
		return (-1);
	}
	va_start(ap, format);

	buf_idx = 0; 
	for (i = 0; format[i] != '\0'; i++)
	{
		if (buf_idx >= BUFFSIZE)
		{
			write_to_stdout(str_buf, BUFFSIZE);
			buf_idx = 0;
		}

		if (format[i] == '%')
		{
				if (_strlen(format) == 1)
					return (-1);
			/*If a format specifier is found run the handler*/
			specifier_return = handleSpecifier(format + i + 1, ap, str_buf, &buf_idx);
			if (specifier_return < 0)
					return (-1);
			i = i + 1;
		}
		else
		{
			str_buf[buf_idx++] = format[i];
		}
	}
	
	write_to_stdout(str_buf, buf_idx);
	va_end(ap);
	return (buf_idx);
}

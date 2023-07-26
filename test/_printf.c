#include "main.h"
#include <stdarg.h>
#include <stdio.h>
/**
 * _printf -  produces output according to a format.
 * @format: charcter to be printed
 * @...: variable list arguement
 * Return: length of the output
 */
int _printf(const char *format, ...)
{
	va_list vp;
	char *p_str;
	char *p;
	int len_str, j, total_len;
	char buf[BUFFER] = "";

	p_str = buf;
	len_str = j = total_len = 0;
	va_start(vp, format);
	if (!format)
		return (-1);
	while (format[j] && format)
	{
		/*Handle cases of buffer overflow*/
		if (_len(p_str) >= BUFFER)
		{
			_output(p_str, BUFFER);
			total_len += _len(buf) + 1;
			buf[0] = '\0';
		}

		if (format[j] == '%')
		{
			j++;
			if (!format[j])
				return (-1);
			_parse(vp, format[j], p_str, p);
		}
		else
		{
			p = cast_cs(format[j]);
			_strcat(p_str, p);
		}
		j++;
	}
	va_end(vp);
	len_str = _len(p_str);
	total_len += len_str;
	_output(p_str, len_str);
	return (total_len);
}

/**
 * _parse - expands specifier to its value and add to buffer
 * @vp: variable list
 * @y: character key for specifier
 * @p_str: pointer to the buffer
 * @p: pointer to the new buffer
 */
void _parse(va_list vp, char y, char *p_str, char *p)
{
	int k;
	s_f spec[] = {
	{'c', cast_char},
	{'s', cast_string},
	{'%', cast_percent},
	{'i', cast_int},
	{'d', cast_int},
	};
	for (k = 0; spec[k]._type; k++)
	{
		if (y == spec[k]._type)
		{
			p = spec[k].f(vp);
			break;
		}
	}
	if (!spec[k]._type)
		p = _not(y);
	_strcat(p_str, p);
}

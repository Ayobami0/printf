#include "main.h"
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
	int len_str, j;
	char buf[1025] = "";

	p_str = buf;
	len_str = j = 0;
	va_start(vp, format);
	while (format[j] && format)
	{
		if (format[j] == '%')
		{
			j++;
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
	_output(p_str, len_str);
	return (len_str);
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
	{'%', cast_percent}
	};
	for (k = 0; spec[k]._type; k++)
	{
		if (y == spec[k]._type)
		{
			p = spec[k].f(vp);
			break;
		}
	}
	if (!p)
	p = _not(y);
	_strcat(p_str, p);
}

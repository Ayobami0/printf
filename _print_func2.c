#include "main.h"
#include <stdio.h>

/**
*	_parse_num - converts an int number to string
*	@n: the number
*	@num_buf: a buffer to store the string
*
*	Return: the int as a string
*/
char *_parse_num(int n, char *num_buf)
{
	int is_negative, i;
	
	is_negative = 0;
	if (n < 0)
	{
		is_negative = 1;
		n = -n;
	}

	i = 0;
	while (n > 0)
	{
		num_buf[i++] = '0' + (n % 10);
		n /= 10;
	}
	if (is_negative)
		num_buf[i++] = '-';
	num_buf[i] = '\0';

	rev_string(num_buf, i);
	return (num_buf);
}

char *_parse_uint(unsigned int n, char *num_buf)
{
	int i, j;
	char temp;

	i = 0;
	while (n > 0)
	{
		num_buf[i++] = '0' + (n % 10);
		n /= 10;
	}
	num_buf[i] = '\0';

	for (j = 0; j < i / 2; j++)
	{
		temp = num_buf[j];
		num_buf[j] = num_buf[i - j - 1];
		num_buf[i - j - 1] = temp;
	}

	return (num_buf);
}

char *_parse_uoct(unsigned int n, char *num_buf)
{
	int i, j;
	char temp;

	i = 0;
	while (n > 0)
	{
		num_buf[i++] = '0' + (n % 8);
		n /= 8;
	}
	num_buf[i] = '\0';

	for (j = 0; j < i / 2; j++)
	{
		temp = num_buf[j];
		num_buf[j] = num_buf[i - j - 1];
		num_buf[i - j - 1] = temp;
	}

	return (num_buf);
}
char *_parse_uhex(unsigned int n, char *num_buf, int hex_type)
{
	int i, j, _hex;
	char temp;

	_hex = 65;
	if (hex_type != 0)
		_hex = 97;
	i = 0;
	while (n > 0)
	{
		/*A = 65 B C D E F*/
		num_buf[i++] = (n % 16) < 10
			? '0' + (n % 16)
			: ((n % 16) - 10) + _hex;
		n /= 16;
	}
	num_buf[i] = '\0';

	for (j = 0; j < i / 2; j++)
	{
		temp = num_buf[j];
		num_buf[j] = num_buf[i - j - 1];
		num_buf[i - j - 1] = temp;
	}

	return (num_buf);
}

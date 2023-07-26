#include "main.h"

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

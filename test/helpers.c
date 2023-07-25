#include "main.h"
#include <stdio.h>
/**
 * _strlen - Calculate the length of a null-terminated string.
 * @str: A pointer to the null-terminated string.
 *
 * Return: The length of the string (excluding the null terminator).
 */
int _strlen(const char *str)
{
	int i, total;

	total = i = 0;
	while (str[i] != '\0')
	{
		total++;
		i++;
	}

	return (total);
}
/**
 * num_len - Calculate the number of digits in an integer.
 * @n: The integer for which to calculate the number of digits.
 *
 * Return: The number of digits in the integer.
 */
int num_len(int n)
{
	int count;

	count = 0;
	while (n > 0)
	{
		count++;
		n /= 10;
	}
	return (count);
}

/**
 * itoa - Convert an integer to its string representation.
 * @n: The integer to be converted.
 * @str_rep: A pointer to the buffer where the string
 * representation will be stored.
 */
void itoa(int n, char *str_rep)
{
	char temp;
	int i, cp_n, str_len, is_negative;

	is_negative = 0;
	if (n < 0)
	{
		is_negative = 1;
		n = -n;
	}
	cp_n = n;

	for (i = 0; cp_n > 0; i++)
	{
		str_rep[i] = '0' + (cp_n % 10);
		cp_n /= 10;
	}
	if (is_negative == 1)
		str_rep[i++] = '-';
	str_rep[i] = '\0';
	str_len = i;
	for (i = 0; i < str_len / 2; i++)
	{
		temp = str_rep[i];
		str_rep[i] = str_rep[str_len - 1 - i];
		str_rep[str_len - 1 - i] = temp;
	}
}
/**
 * write_to_stdout - Write a buffer to the standard output.
 * @buf: A pointer to the buffer to be written.
 * @size: The number of bytes to be written.
 */
void write_to_stdout(const char *buf, int size)
{
	write(1, buf, size);
}

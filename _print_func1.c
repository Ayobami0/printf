#include "main.h"

/**
 * _output - output the string to the standard output
 * @str: string to be printed
 * @str_len: length of the string
 */
void _output(char *str, int str_len)
{
	write(1, str, str_len);
}

/**
 * _len - return the len of a string
 * @str: the string
 * Return: the length of the string
 */
int _len(char *str)
{
	int i;

	for (i = 0; str[i] && str; i++)
		;
	return (i);
}

/**
 * cast_cs - convert char to string
 * @c: char to be converted
 * Return: string
 */
char *cast_cs(char c)
{
	char str[2];
	char *p;

	p = str;
	*p = c;
	*(p + 1) = '\0';
	return (p);
}

/**
 * _not - no matches found but
 * @t: character unmatched to return and store
 * Return: string with percent and character.
 */
char *_not(char t)
{
	char str[3];
	char *p;

	p = str;
	*p = '%';
	*(p + 1) = t;
	*(p + 2) = '\0';
	return (p);
}
/**
 * _strcat - appends the src string to the dest string, overwriting
 * the terminating null byte (\0) at the end of dest, and then adds a
 * terminating null byte
 * @dest: pointer to a char
 * @src: pointer to a char
 * Return: chararacter
 */
char *_strcat(char *dest, char *src)
{
	int i;

	i = 0;
	while (dest[i])
		i++;
	while (*src)
		dest[i++] = *src++;
	dest[i] = '\0';
	return (dest);
}

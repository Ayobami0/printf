#include "main.h"
/**
 * cast_binary - convert unsigned int to binary and to string
 * @b: integer to be converted
 * Return: a string
*/
char *cast_binary(va_list b)
{
    char buf_bin[32];
    unsigned n, i;
    char *str;

    str = buf_bin;
    i = 0;
    n = va_arg(b, unsigned int);
    if (n == 0)
        buf_bin[i] = '0';
    for ( i = 0; n > 0; i++)
    {
        buf_bin[i] = (n % 2) + '0';
        n /= 2;
    }
    buf_bin[i] = '\0';
    rev_string(str, i);
    return (str);
}

/**
 * rev_string - string is reverse
 * @s: char type pointer
 * @len: length of the string
 * Return: nothing
 */
void rev_string(char *s, int len)
{
	int j;
	char temp;

	for (j = 0; j < (len / 2); j++)
	{
		temp = s[j];
		s[j] = s[len - j - 1];
		s[len - j - 1] = temp;
	}
}
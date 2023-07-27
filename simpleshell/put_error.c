#include "mash.h"

/**
 *_eputs - puts input string
 * @str: str
 *
 * Return: void
 */
void _eputs(char *str)
{
	int k = 0;

	if (!str)
		return;
	while (str[k] != '\0')
	{
		_eputchar(str[k]);
		k++;
	}
}

/**
 * _eputchar - put character to stderr
 * @c: c
 *
 * Return: up On success 1 On error -1 is returned
 */
int _eputchar(char c)
{
	static int i;
	static char buf[BUF_SIZE];

	if (c == FLUSH || i >= BUF_SIZE)
	{
		write(2, buf, i);
		i = 0;
	}
	if (c != FLUSH)
		buf[i++] = c;
	return (1);
}

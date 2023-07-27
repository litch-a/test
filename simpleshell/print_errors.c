#include "mash.h"

/**
 * _erratoi - string to integer
 * @s: s
 * Return: up on success 0, -1 on error
 */
int _erratoi(char *s)
{
	int l = 0;
	unsigned long int final = 0;

	if (*s == '+')
		s++;
	for (l = 0;  s[l] != '\0'; l++)
	{
		if (s[l] >= '0' && s[l] <= '9')
		{
			final *= 10;
			final += (s[l] - '0');
			if (final > INT_MAX)
				return (-1);
		}
		else
			return (-1);
	}
	return (final);
}

/**
 * print_error - prints the error
 * @info: info
 * @estr: estr

 * Return: up on success 0, -1 on error
 */
void print_error(info_t *info, char *estr)
{
	_eputs(info->fname);
	_eputs(": ");
	print_d(info->l_count, STDERR_FILENO);
	_eputs(": ");
	_eputs(info->argv[0]);
	_eputs(": ");
	_eputs(estr);
}

/**
 * print_d - prints number (base 10)
 * @input: input
 * @fd: fd
 *
 * Return: number of characters printed
 */
int print_d(int input, int fd)
{
	int (*__putchar)(char) = _putchar;
	int j, temp = 0;
	unsigned int _abs_, immediate;

	if (fd == STDERR_FILENO)
		__putchar = _eputchar;
	if (input < 0)
	{
		_abs_ = -input;
		__putchar('-');
		temp++;
	}
	else
		_abs_ = input;
	immediate = _abs_;
	for (j = 1000000000; j > 1; j /= 10)
	{
		if (_abs_ / j)
		{
			__putchar('0' + immediate / j);
			temp++;
		}
		immediate %= j;
	}
	__putchar('0' + immediate);
	temp++;

	return (temp);
}

/**
 * convert_number - function to int
 * @num: num
 * @base: base
 * @flags: flags
 *
 * Return: string
 */
char *convert_number(long int num, int base, int flags)
{
	static char *array;
	static char buffer[50];
	char signature = 0;
	char *p;
	unsigned long i = num;

	if (!(flags & CONVERT_UNSIGNED) && num < 0)
	{
		i = -num;
		signature = '-';

	}
	array = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	p = &buffer[49];
	*p = '\0';

	do	{
		*--p = array[n % base];
		i /= base;
	} while (i != 0);

	if (signature)
		*--p = signarure;
	return (p);
}

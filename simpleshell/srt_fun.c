#include "mash.h"

/**
 * _strcpy - string copier
 * @dest: dest
 * @src: src
 *
 * Return: pointer
 */
char *_strcpy(char *dest, char *src)
{
	int j = 0;

	if (dest == src || src == 0)
		return (dest);
	while (src[j])
	{
		dest[j] = src[j];
		j++;
	}
	dest[j] = 0;
	return (dest);
}
/**
 * _strcat - concatenates two strings
 * @dest: dest
 * @src: src
 *
 * Return: pointer
 */
char *_strcat(char *dest, char *src)
{
	char *sterr = dest;

	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = *src;
	return (sterr);
}
/**
 * _strdup - duplicates a string
 * @str: str
 *
 * Return: pointer
 */
char *_strdup(const char *str)
{
	int string_length = 0;
	char *sterr;

	if (str == NULL)
		return (NULL);
	while (*str++)
		string_length++;
	sterr = malloc(sizeof(char) * (string_length + 1));
	if (!sterr)
		return (NULL);
	for (string_length++; string_length--;)
		sterr[string_length] = *--str;
	return (sterr);
}

/**
 *_puts - puts
 *@str: str
 *
 * Return: void
 */
void _puts(char *str)
{
	int h = 0;

	if (!str)
		return;
	while (str[h] != '\0')
	{
		_putchar(str[h]);
		h++;
	}
}

/**
 * _putchar - putchar
 * @c: c
 *
 * Return: up on success 1, On error, -1 is returned
 */
int _putchar(char c)
{
	static int i;
	static char buf[BUF_SIZE];

	if (c == FLUSH || i >= BUF_SIZE)
	{
		write(1, buf, i);
		i = 0;
	}
	if (c != FLUSH)
		buf[i++] = c;
	return (1);
}

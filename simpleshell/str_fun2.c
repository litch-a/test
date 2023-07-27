#include "mash.h"
/**
 * interactive - interactive mode
 * @info: info
 *
 * Return: for interactive 1 or 0
 */
int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_delim - checks character to be a delimeter
 * @c: c
 * @delim: delims
 * Return: if its 1 or 0
 */
int is_delim(char c, char *delim)
{
	while (*delim)
		if (*delim++ == c)
			return (1);
	return (0);
}

/**
 * _strlen - string length
 * @s: s
 *
 * Return: len
 */
int _strlen(char *s)
{
	int m = 0;

	if (!s)
		return (0);

	while (*s++)
		m++;
	return (m);
}

/**
 * _strcmp - compare string
 * @s1: s1
 * @s2: s2
 *
 * Return: -ve for s1 < s2, +ve for s1 > s2, 0 for s1 == s2
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	if (*s1 == *s2)
		return (0);
	else
		return (*s1 < *s2 ? -1 : 1);
}

/**
 * starts_with - checks for string
 * @haystack: haystack
 * @needle: needle
 *
 * Return: address or NULL
 */
char *starts_with(const char *haystack, const char *needle)
{
	while (*needle)
		if (*needle++ != *haystack++)
			return (NULL);
	return ((char *)haystack);
}

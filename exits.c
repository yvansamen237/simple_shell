#include "shell.h"

/**
 **_strncpy - It copies a string
 *@dest: the destination in which the string is to be copied to
 *@src: the source of the string
 *@n: the number of characters to be copied
 *Return: Concatenated string
 */
char *_strncpy(char *dest, char *src, int n)
{
	int i, k;
	char *s = dest;

	i = 0;
	while (src[i] != '\0' && i < n - 1)
	{
		dest[i] = src[i];
		i++;
	}
	if (i < n)
	{
		k = i;
		while (k < n)
		{
			dest[k] = '\0';
			k++;
		}
	}
	return (s);
}

/**
 **_strncat - concatenates two strings
 *@dest: This is the first string
 *@src: This is the second string
 *@n: the number of bytes to be maximally used
 *Return: the concatenated string
 */
char *_strncat(char *dest, char *src, int n)
{
	int h, j;
	char *s = dest;

	h = 0;
	j = 0;
	while (dest[h] != '\0')
		h++;
	while (src[j] != '\0' && j < n)
	{
		dest[h] = src[j];
		h++;
		j++;
	}
	if (j < n)
		dest[j] = '\0';
	return (s);
}

/**
 **_strchr - locates a character in a string
 *@s: The string to be parsed
 *@c: The character to look for
 *Return: (s) a pointer to the memory area s
 */
char *_strchr(char *s, char c)
{
	do {
		if (*s == c)
			return (s);
	} while (*s++ != '\0');

	return (NULL);
}

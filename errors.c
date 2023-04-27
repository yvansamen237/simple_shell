#include "shell.h"

/**
 * _eputs - It prints an input string as shown
 * @str: The string to be printed actually
 *
 * Return: Nothing
 */
void _eputs(char *str)
{
	int _i = 0;

	if (!str)
		return;
	while (str[_i] != '\0')
	{
		_eputchar(str[_i]);
		_i++;
	}
}

/**
 * _eputchar - It writes the character c to stderr
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately as shown.
 */
int _eputchar(char c)
{
	static int _i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || _i >= WRITE_BUF_SIZE)
	{
		write(2, buf, _i);
		_i = 0;
	}
	if (c != BUF_FLUSH)
		buf[_i++] = c;
	return (1);
}

/**
 * _putfd - writes the character c to given fd
 * @c: The character to print
 * @fd: The filedescriptor to write to
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putfd(char _c, int _fd)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (_c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(_fd, buf, i);
		i = 0;
	}
	if (_c != BUF_FLUSH)
		buf[i++] = _c;
	return (1);
}

/**
 * _putsfd - prints an input string
 * @str: the string to be printed
 * @fd: the filedescriptor to write to
 *
 * Return: the number of chars put
 */
int _putsfd(char *str, int fd)
{
	int i = 0;

	if (!str)
		return (0);
	while (*str)
	{
		i += _putfd(*str++, fd);
	}
	return (i);
}

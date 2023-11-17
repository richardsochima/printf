#include "main.h"
/**
   * my_putchar - writes the character c to stdout
   * @c: The character to print
   * Return: On success 1, else -1
   */
int my_putchar(char c)
{
	static char buf[1024];
	static int i;

	if (c == -1 || i >= 1024)
	{
		write(1, &buf, i);
		i = 0;
	}
	if (c != -1)
	{
		buf[i] = c;
		i++;
	}
	return (1);
}

/**
  * _putss - prints a string to stdout
  * @s: pointer to the string to print
  * Return: number of chars written
  */
int _putss(char *s)
{
	register int i;

	for (i = 0; s[i] != '\0'; i++)
		my_putchar(s[i]);
	return (i);
}

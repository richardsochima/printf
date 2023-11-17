#include "main.h"
/**
 * prints_char - prints a character
 * @c: character to be printed
 *
 * Return: Nothing
 */
int prints_char(char c)
{
	return (write(1, &c, c));
}

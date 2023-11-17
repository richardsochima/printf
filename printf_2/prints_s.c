#include "main.h"

/**
 * prints_str - prints a string
 * @str: string to be printed
 *
 * Return: Nothing
 */
int prints_str(char *str)
{
	return (write(1, str, strlen(str)));
}

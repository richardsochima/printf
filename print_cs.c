#include "main.h"
/**
  * print_str - prints a string
  * @e: va_list arguments from _printf
  * @p: pointer to the struct flags
  * Return: number of char printed
  */
int print_str(va_list e, flags_t *p)
{
	char *s = va_arg(e, char *);

	(void)p;

	if (!s)
		s = "(null)";
	return (_putss(s));
}

/**
  * print_char - prints a character
  * @e: va_list arguments from _printf
  * @p: pointer to the struct flags
  * Return: number of char printed
  */
int print_char(va_list e, flags_t *p)
{
	(void)p;
	my_putchar(va_arg(e, int));
	return (1);
}

#include "main.h"
/**
  * print_addy - prints address of input in hexa format
  * @e: va_list arguments from _printf
  * @p: pointer to the struct flags
  * Return: number of char printed
  */
int print_addy(va_list e, flags_t *p)
{
	char *s;
	unsigned long int a = va_arg(e, unsigned long int);

	register int count = 0;

	(void)p;

	if (!a)
		return (_putss("(nil)"));
	s = convert(a, 16, 1);
	count += _putss("0x");
	count += _putss(s);
	return (count);
}

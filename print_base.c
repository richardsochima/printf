#include "main.h"
/**
  * print_hex - prints a number in hexadecimal base,
  * @e: va_list arguments from _printf
  * @p: pointer to the struct flags
  * Return: the number of char printed
  */
int print_hex(va_list e, flags_t *p)
{
	unsigned int num = va_arg(e, unsigned int);
	char *s = convert(num, 16, 1);
	int count = 0;

	if (p->hash == 1 && s[0] != '0')
		count += _putss("0x");
	count += _putss(s);
	return (count);
}

/**
  * print_HEX - prints a number in hexadecimal base,
  * @e: va_list arguments from _printf
  * @p: pointer to the struct flags
  * Return: the number of char printed
  */
int print_HEX(va_list e, flags_t *p)
{
	unsigned int num = va_arg(e, unsigned int);
	char *s = convert(num, 16, 0);
	int count = 0;

	if (p->hash == 1 && s[0] != '0')
		count += _putss("0X");
	count += _putss(s);
	return (count);
}

/**
  * print_bin - prints a number in base 2
  * @e: va_list arguments from _printf
  * @p: pointer to the struct flags
  * Return: the number of char printed
  */
int print_bin(va_list e, flags_t *p)
{
	unsigned int num = va_arg(e, unsigned int);
	char *s = convert(num, 2, 0);

	(void)p;
	return (_putss(s));
}

/**
  * print_oct - prints a number in base 8
  * @e: va_list arguments from _printf
  * @p: pointer to the struct flags
  * Return: the number of char printed
  */
int print_oct(va_list e, flags_t *p)
{
	unsigned int num = va_arg(e, unsigned int);
	char *s = convert(num, 8, 0);
	int count = 0;

	if (p->hash == 1 && s[0] != '0')
		count += my_putchar('0');
	count += _putss(s);
	return (count);
}

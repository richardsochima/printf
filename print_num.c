#include "main.h"
/**
  * print_int - prints an integer
  * @e: va_list of arguments from _printf
  * @p: pointer to the struct flags
  * Return: number of char printed
  */
int print_int(va_list e, flags_t *p)
{
	int n = va_arg(e, int);
	int r = count_digit(n);

	if (p->space == 1 && p->plus == 0 && n >= 0)
		r += my_putchar(' ');
	if (p->plus == 1 && n >= 0)
		r += my_putchar('+');
	if (n <= 0)
		r++;
	print_num(n);
	return (r);
}

/**
  * print_unsigned - prints an unsigned integer
  * @e: va_list of arguments from _printf
  * @p: pointer to the struct flags
  * Return: number of char printed
  */
int print_unsigned(va_list e, flags_t *p)
{
	unsigned int u = va_arg(e, unsigned int);
	char *s = convert(u, 10, 0);

	(void)p;
	return (_putss(s));
}

/**
  * print_num - helper function that loops through
  * an integer and prints all its digits
  * @n: integer to be printed
  */
void print_num(int n)
{
	unsigned int n1;

	if (n < 0)
	{
		my_putchar('-');
		n1 = -n;
	}
	else
		n1 = n;

	if (n1 / 10)
		print_num(n1 / 10);
	my_putchar((n1 % 10) + '0');
}

/**
  * count_digit - returns the number of digits in an integer
  * @i: integer to evaluate
  * Return: number of digits
  */
int count_digit(int i)
{
	unsigned int d = 0;
	unsigned int u;

	if (i < 0)
		u = i * -1;
	else
		u = i;
	while (u != 0)
	{
		u /= 10;
		d++;
	}
	return (d);
}

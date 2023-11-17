#include "main.h"
/**
   * _printf - produces output according to a format
   * @format: format string containing the characters and the specifiers
   * Return: length of the formatted output string
   */
int _printf(const char *format, ...)
{
	int (*pf)(va_list, flags_t *);
	const char *a;
	va_list args;
	flags_t flags = {0, 0, 0, 0, 0};

	register int count = 0;

	va_start(args, format);
	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	for (a = format; *a; a++)
	{
		if (*a == '%')
		{
			a++;
			if (*a == '%')
			{
				count += my_putchar('%');
				continue;
																								}
			while (get_flag(*a, &flags))
				a++;
			pf = get_print(*a);
			count += (pf)
				? pf(args, &flags)
				: _printf("%%%c", *a);
		} else
			count += my_putchar(*a);
	}
	my_putchar(-1);
	va_end(args);
	return (count);
}

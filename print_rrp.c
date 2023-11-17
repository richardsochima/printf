#include "main.h"
/**
  * print_s - Non printable characters
  * @e: va_list arguments from _printf
  * @p: pointer to the struct flags that determines
  * Return: number of char printed
  */
int print_s(va_list e, flags_t *p)
{
	int i, count = 0;
	char *r;
	char *s = va_arg(e, char *);

	(void)p;
	if (!s)
		return (_putss("(null)"));

	for (i = 0; s[i]; i++)
	{
		if (s[i] > 0 && (s[i] < 32 || s[i] >= 127))
		{
			_putss("\\x");
			count += 2;
			r = convert(s[i], 16, 0);
			if (!r[1])
				count += my_putchar('0');
			count += _putss(r);
		}
		else
			count += my_putchar(s[i]);
	}
	return (count);
}

/**
  * print_rev - prints a string in reverse
  * @e: argument from _printf
  * @p: pointer to the struct flags
  * Return: length of the printed string
  */
int print_rev(va_list e, flags_t *p)
{
	int i = 0, j;
	char *s = va_arg(e, char *);

	(void)p;
	if (!s)
		s = "(null)";

	while (s[i])
		i++;

	for (j = i - 1; j >= 0; j--)
		my_putchar(s[j]);

	return (i);
}

/**
  * print_rot13 - prints a string using rot13
  * @e: list of arguments from _printf
  * @p: pointer to the struct flags
  * Return: length of the printed string
  */
int print_rot13(va_list e, flags_t *p)
{
	int i, j;
	char rot13[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char ROT13[] = "nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM";
	char *s = va_arg(e, char *);

	(void)p;
	for (j = 0; s[j]; j++)
	{
		if (s[j] < 'A' || (s[j] > 'Z' && s[j] < 'a') || s[j] > 'z')
			my_putchar(s[j]);
		else
		{
			for (i = 0; i <= 52; i++)
			{
				if (s[j] == rot13[i])
					my_putchar(ROT13[i]);
			}
		}
	}

	return (j);
}

/**
  * print_per - prints a percent
  * @e: va_list arguments from _printf
  * @p: pointer to the struct flags in which we turn the flags on
  * Return: number of char printed
  */
int print_per(va_list e, flags_t *p)
{
	(void)e;
	(void)p;
	return (my_putchar('%'));
}

#include "main.h"
/**
  * convert - converts number and base into string
  * @num: input number
  * @base: input base
  * @lc: flag if hexa values need to be lowercase
  * Return: result string
  */
char *convert(unsigned long int num, int base, int lc)
{
	static char *rep;
	static char buffer[50];
	char *ptr;

	rep = (lc)
		? "0123456789abcdef"
		: "0123456789ABCDEF";
	ptr = &buffer[49];
	*ptr = '\0';
	do {
		*--ptr = rep[num % base];
		num /= base;
	} while (num != 0);

	return (ptr);
}

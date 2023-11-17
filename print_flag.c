#include "main.h"
/**
  * get_flag - turns on flags if _printf finds
  * @s: character that holds the flag specifier
  * @p: pointer to the struct flags in which we turn the flags on
  * Return: 1 if a flag has been turned on, 0 otherwise
  */
int get_flag(char s, flags_t *p)
{
	int i = 0;

	switch (s)
	{
		case '+':
			p->plus = 1;
			i = 1;
			break;
		case ' ':
			p->space = 1;
			i = 1;
			break;
		case '#':
			p->hash = 1;
			i = 1;
			break;
		case '-':
			p->minus = 1;
			i = 1;
			break;
		case '0':
			p->zero = 1;
			i = 1;
			break;
	}

	return (i);
}

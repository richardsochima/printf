#include "main.h"
/**
  * get_print - selects the right printf function
  * @s: character
  * Return: a pointer to the matching printing function
  */
int (*get_print(char s))(va_list, flags_t *)
{
	hr func_arr[] = {
	{'i', print_int},
	{'s', print_str},
	{'c', print_char},
	{'d', print_int},
	{'u', print_unsigned},
	{'x', print_hex},
	{'X', print_HEX},
	{'b', print_bin},
	{'o', print_oct},
	{'R', print_rot13},
	{'r', print_rev},
	{'S', print_s},
	{'p', print_addy},
	{'%', print_per}
	};
	int flags = 14;

	register int i;

	for (i = 0; i < flags; i++)
		if (func_arr[i].c == s)
			return (func_arr[i].p);
	return (NULL);
}

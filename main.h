#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>

/**
  * struct flags - struct containing flags to use
  * when a flag specifier is passed to _printf()
  * @add: flag for the '+' character
  * @spc: flag for the ' ' character
  * @hash: flag for the '#' character
  */
typedef struct flags
{
	int plus;
	int space;
	int hash;
	int minus;
	int zero;
} flags_t;

/**
  * struct handler - struct to choose the right function depending
  * on the format specifier passed to _printf()
  * @c: format specifier
  * @p: pointer to the correct printing function
  */
typedef struct handler
{
	char c;
	int (*p)(va_list pr, flags_t *p);
} hr;

/* print_nums */
int print_int(va_list e, flags_t *p);
void print_num(int n);
int print_unsigned(va_list e, flags_t *p);
int count_digit(int i);

/* print_bases */
int print_hex(va_list e, flags_t *p);
int print_HEX(va_list e, flags_t *p);
int print_bin(va_list e, flags_t *p);
int print_oct(va_list e, flags_t *p);

/* converter */
char *convert(unsigned long int num, int base, int lc);

/* _printf */
int _printf(const char *format, ...);

/* get_print */
int (*get_print(char s))(va_list, flags_t *);

/* get_flag */
int get_flag(char s, flags_t *p);

/* print_alpha */
int print_str(va_list e, flags_t *p);
int print_char(va_list e, flags_t *p);

/* write_funcs */
int my_putchar(char c);
int _putss(char *s);

/* print_custom */
int print_rot13(va_list e, flags_t *p);
int print_rev(va_list e, flags_t *p);
int print_s(va_list e, flags_t *p);

/* print_address */
int print_addy(va_list e, flags_t *p);

/* print_percent */
int print_per(va_list e, flags_t *p);

#endif

#include "main.h"
/**
 * _printf - ...
 * @format: a character string composing of zero or directives
 *
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
    int print_char = 0;
    va_list fmat_lists;

    if (format == NULL)
        return (-1);
    va_start(fmat_lists, format);
    while (*format)
    {
        if (*format != '%')
        {
            write(1, format, 1);
            print_char++;
        }
        else
        {
            format++;
            if (*format == '\0')
                break;
            if (*format == '%')
            {
                write(1, format, 1);
                print_char++;
            }
            else if (*format == 'c')
            {
                char c = va_arg(fmat_lists, int);

                write(1, &c, 1);
                print_char++;
            }
            else if (*format == 's')
            {
                char *str = va_arg(fmat_lists, char*);
                int str_len = 0;

                while (str[str_len] != '\0')
                    str_len++;
                write(1, str, str_len);
                print_char += str_len;
            }
            else if (*format == 'd' || *format == 'i')
            {
                int num = va_arg(fmat_lists, int);
                int num_len = 0;

                if (num < 0)
                {
                    write(1, "-", 1);
                    print_char++;
                    num = -num;
                }

                if (num == 0)
                {
                    write(1, "0", 1);
                    print_char++;
                }

                while (num != 0)
                {
                    int digit = num % 10 + '0';
                    write(1, &digit, 1);
                    num_len++;
                    num /= 10;
                }

                while (num_len > 0)
                {
                    num_len--;
                    print_char++;
                }
            }
        }
        format++;
    }
    va_end(fmat_lists);
    return (print_char);
}

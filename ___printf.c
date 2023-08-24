#include "main.h"

/**
 * _printf - Custom printf function that supports %c, %s, and %% specifiers
 * @format: The format string containing conversion specifiers
 * @...: Arguments corresponding to the conversion specifiers
 *
 * Return: The number of characters printed (excluding the null byte)
 */
int _printf(const char *format, ...)
{
    va_list args;
    va_start(args, format);

    int count = 0;

    while (*format != '\0')
    {
        if (*format == '%')
        {
            format++;

            if (*format == 'c')
            {
                int c = va_arg(args, int);
                write(1, &c, 1);
                count++;
            }
            else if (*format == 's')
            {
                char *s = va_arg(args, char *);
                while (*s != '\0')
                {
                    write(1, s, 1);
                    s++;
                    count++;
                }
            }
            else if (*format == '%')
            {
                write(1, format, 1);
                count++;
            }
            else
            {
            
            }
        }
        else
        {
            write(1, format, 1);
            count++;
        }

        format++;
    }
    va_end(args);
    return (count);
}

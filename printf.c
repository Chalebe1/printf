#include <stdio.h>
#include <stdarg.h>
#include <unistd.h> // Include for the write function

/**
 * _printf - produces output according to a format
 *
 * @format: character format string
 *
 * Return: number of characters printed, excluding the null byte
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
            format++; // Move past the '%'

            if (*format == 'c')
            {
                int c = va_arg(args, int);
                write(1, &c, 1); // Write the character directly
                count++;
            }
            else if (*format == 's')
            {
                char *string = va_arg(args, char *);
                while (*string != '\0')
                {
                    write(1, string, 1); // Write each character of the string
                    string++;
                    count++;
                }
            }
            else if (*format == '%')
            {
                write(1, format, 1); // Write a literal '%'
                count++;
            }
            else
            {
                // Invalid conversion specifier, ignore
            }
        }
        else
        {
            write(1, format, 1); // Write regular characters
            count++;
        }

        format++;
    }

    va_end(args);
    return count + ; // Add 1 for the newline cha
}

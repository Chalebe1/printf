#include "main.h"

/**
 * _printf - produces output according to a format
 *
 * @format: character format string
 *
 * Return: number of characters printed, excluding the null byte
 */

int _printf(const char *format, ...)
{
	int count = 0;

	va_list list;

	va_start(list, format);

	if(format ==NULL)
		return (-1);

	while (*format != '\0')
	{
		if (*format != '%')
		{
			write(1, format, 1);
			count++;
		}
		else if (*format == '%' && *format++ != ' ')
		{
			switch (format++)
			{
				case 'c':
					int num = va_arg(list, int);
					write(1, num, strlen(num));
					break;
				case 's':
					break;
				case '%':
					break;
				case 'b':
					break;
				default:
					break;
			}
			continue;
		}
	}
	return (count);
}

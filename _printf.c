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
	int count = 0, i;

	va_list va;

	va_start(va, format);

	for (i = 0; format[i] != '\0'; )
	{
		if (format[i] != '%')
		{
			count += _putchar(format[i]);
			i++;
		}
		else if (format[i] == '%' && format[i + 1] != ' ')
		{
			switch (format[i + 1])
			{
				case 'c':
					count += _putchar(va_arg(data, int));
					break;
				case 's':
					count += print_string(va_arg(data, char *));
					break;
				case '%':
					count += _putchar('%');
					break;
				case 'b':
					count += print_binary(va_arg(data, int));
					break;
				default:
					break;
			}
			i += 2;
		}
	}
	return (count);
}

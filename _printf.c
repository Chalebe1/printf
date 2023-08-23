:ww::ww: "main.h"

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
	char c;
	const char *s;
	va_list list;

	va_start(list, format);
	while (*format != '\0')
	{
		if (*format != '%')
		{
			write(1,format,1);
			count++;
		}
		else
		{
			format++;
			switch (*format)
			{
				case 'c':
					c = va_arg(list, int);
					write(1,&c,1);
					count++;
					break;
				case 's':
					s = va_arg(list, const char *);
					while (*s != '\0')
					{
						write(1,s,1);
						s++;
						count++;
					}
					break;
				case '%':
					write(1,'%',1);
					count++;
					break;
			}
		}
		format++;
	}
	va_end(list);
	return (count);
:wq


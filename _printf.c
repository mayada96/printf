#include "main.h"
#include <stdarg.h>
#include <stdlib.h>

/**
 * vprintk - handling printf cases
 * @fm: the case
 * @org: the char after the case
 *
 * Return: nothing
 */

void vprintk(const char *fm, va_list org)
{
	int state = 0;
	char ch;
	const char *s;

	while (*fm)
	{
		if (state == 0)
		{
			if (*fm == '%')
				state = 1;
			else
				putchar(*fm);
		}
		else if (state == 1)
		{
			switch (*fm)
			{
				case 'c':
					ch = va_arg(org, int);
					putchar(ch);
					break;
				case 's':
					s = va_arg(org, const char *);
					while (*s)
					{
						putchar(*s++);
					}
					break;
			}
				state = 0;
		}
		fm++;
	}
}


/**
 * _printf - produces output according to a format.
 * @format: the format to be printed
 *
 * Return: the espicifide string or number
 */

int _printf(const char *format, ...)
{
	va_list op;

	va_start(op, format);
	vprintk(format, op);
	va_end(op);
	return (0);
}

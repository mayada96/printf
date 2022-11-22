#include "main.h"
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

/**
 * _printf - print the chareckter
 * @format: the format to be printed
 *
 * Return: the espicifide string or number
 */

int _printf(const char *format, ...)
{
	va_list op;
	unsigned int i = 0, len = 0, ibuf = 0;
	int (*function)(va_list, char *, unsigned int);
	char *buffer;

	va_start(op, format);
	buffer = malloc(sizeof(char) * 1024);
	if (!format || !buffer || (format[i] == '%' && !format[i + 1]))
		return (-1);
	if (!format[i])
		return (0);
	for (i = 0; format && format[i]; i++)
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == '\0')
			{
				print_buf(buffer, ibuf), free(buffer), va_end(op);
				return (-1);
			}
			else
			{	function = get_print_func(format, i + 1);
				if (function == NULL)
				{
					if (format[i + 1] == ' ' && !format[i + 2])
						return (-1);
					handl_buf(buffer, format[i], ibuf), len++, i--;
				}
				else
					len += function(op, buffer, ibuf);
					i += ev_print_func(format, i + 1);
			} i++;
		}
		else
			handl_buf(buffer, format[i], ibuf), len++;
		for (ibuf = len; ibuf > 1024; ibuf -= 1024)
			;
	}
	print_buf(buffer, ibuf), free(buffer), va_end(op);
	return (len);
}

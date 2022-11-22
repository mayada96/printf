#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

/**
 * struct convert - converting to the right format
 * @sym: identifier
 * @f: pointer to a printer functions
 *
 */
typedef struct convert
{
	char *sym;
	int (*f)(va_list);
} conver_t;

int _printf(const char *format, ...);
int print_percent(va_list);
int unsigned_integer(va_list);
int parser(const char *format, conver_t f_list[], va_list arg_list);
int _write_char(char);
int print_char(va_list);
int print_string(va_list);
int print_integer(va_list);
int print_number(va_list);
int print_binary(va_list);
int print_reversed(va_list arg);
int rot13(va_list);
int print_octal(va_list list);
int print_hex(va_list list);
int print_heX(va_list list);
int hex_check(int num, char x);

unsigned int base_len(unsigned int, int);
char *rev_string(char *);
void write_base(char *str);
char *_memcpy(char *dest, char *src, unsigned int n);
int print_unsgined_number(unsigned int);

#endif

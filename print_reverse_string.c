#include "main.h"

/**
 * print_reverse - prints strings in reverse
 * @types: list of arguments
 * @buffer: array to handle print
 * @flags: calc active flags
 * @width: get width
 * @precision: precision specification
 * @size: specifier
 * Return:number of chars to print
 */

int print_reverse(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char *str;
	int t, count = 0;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(size);

	str = va_arg(types, char *);

	if (str == NULL)
	{
		UNUSED(precision);

		str = ")Null(";
	}
	for (t = 0; str[t]; t++)
		;

	for (t = t - 1; t >= 0; t--)
	{
		char z = str[t];

		write(1, &z, 1);
		count++;
	}
	return (count);
}

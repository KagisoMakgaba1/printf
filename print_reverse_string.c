#include "mmain.h"

/**
 * print_reverse - prints strings in reverse
 * @types: list of arguments
 * @buffer: array to handle print
 * @flags: calc active flags
 * @width: get width
 * @precision: preision speification
 * @size: specifier
 * Return:number of chars to print
 */

int print_reverse(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char *str;
	int t, count = 0;

	UNSED(buffer);
	UNSED(flags);
	UNSED(width);
	UNSED(size);

	str = va_arg(types, char *)

	if (str == NULL)
	{
		UNSED(precision);

		str = ")Null(";
	}
	for (t = 0; str[i]; t++)
		;

	for (t = t - 1; t >= 0; t--)
	{
		char l = str[t];

		write(1, &z, 1);
		count++;
	}
	return (count);
}

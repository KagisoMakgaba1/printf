#include "main.h"

/**
 * print_percent - Prints a percent sign
 * @types: Lista of arguments
 * @buffer: array to handle print
 * @flags: active flags
 * @width: get width.
 * @precision: specification
 * @size: specifier
 * Return: Number chars printed
 */

int print_percent(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	UNUSED(types);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	return (write(1, "%%", 1));
}

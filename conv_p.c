#include "main.h"

/**
 * print_pointer - value of a pointer variable
 * @types: list of arguments
 * @buffer: array to handle print
 * @flags: calculate flags
 * @width: get with
 * @precision: specification
 * @size: size specifier
 * Return: number of char printed
 */

int print_pointer(va_list types, char buffer[], int flags,
		int width, int precision, int size)
{

	char extra_a = 0, padd = ' ';
	int index = BUFF_SIZE - 2, length = 2, padd_start = 1;
	/** length = 2, for '0x'*/
	unsigned long num_addrs;
	char map_to[] = "0123456789abcdef";
	void *addrs = va_arg(types, void *);

	UNUSED(width);
	UNUSED(size);

	if (addrs == NULL)
		return (write(1, "(nil)", 5));

	buffer[BUFF_SIZE - 1] = '\0';

	UNUSED(precision);
	num_addrs = (unsigned long)addrs;

	while (num_addrs > 0)
	{
		buffer[index--] = map_to[num_addrs % 16];
		num_addrs /= 16;
		length++;
	}
	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padd = '0';
	if (flags & F_PLUS)
		extra_a = '+', length++;
	else if (flags & F_SPACE)
		extra_a = ' ', length++;
	index++;

	/** return (write(1, &buffer[t], BUFF_SIZE - t - 1)); */
	return (write_pointer(buffer, index, length, width, flags,
				padd, extra_a, padd_start));
}

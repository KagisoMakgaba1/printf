#include "main.h"

/**
*print_binary - prints an unsigned number
*@types: lists of arguments
*@buffer: buffer array
*@flags: calculates active flags
*@width: get width
*@precision: precision specification
*@size: size specifier
*
*Return: numbers of char printed
*/

int print_binary(va_list types, char buffer[], int flags,
		int width, int precision, int size)
{
	unsigned int a, b, k, sum;
	unsigned int n[32];
	int count;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	a = va_arg(types, unsigned int);
	b = 2147483648; /* (2 ^ 31) */
	n[0] = a / b;
	for (k = 1; k < 32; k++)
	{
		b /= 2;
		n[k] = (a / b) % 2;
	}
	for (k = 0, sum = 0, count = 0; k < 32; k++)
	{
		sum += n[k];
		if (sum || k == 31)
		{
			char z = '0' + n[k];

			write(1, &z, 1);
			count++;
		}
	}
	return (count);
}

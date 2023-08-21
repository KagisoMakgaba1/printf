#include "main.h"

/**
 * print_rot13string - Prints strings in rot13.
 * @types: List of arguments
 * @buffer: Array to handle print
 * @flags: Active flags
 * @width: Get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Numbers of char printed
 */
int print_rot13string(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char a;
	char *str;
	unsigned int t, l;
	int count = 0;
	char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	str = va_arg(types, char *);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	if (str == NULL)
		str = "(AHYY)";
	for (t = 0; str[t]; t++)
	{
		for (l = 0; in[l]; l++)
		{
			if (in[l] == str[l])
			{
				a = out[l];
				if (write(1, &a, 1) != 1)
				{
					return (-1);
				}
				count++;
				break;
			}
		}
		if (!in[l])
		{
			a = str[t];
			if (write(1, &a, 1) != 1)
				return (-1);

			count++;
		}
	}
	return (count);
}

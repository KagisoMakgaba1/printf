#include "main.h"

/**
 * get_precision - gets precision for printing
 * @format: string to print arguments
 * @t: arguments
 * @list: list of arguments
 * Return: precision
 */

int get_precision(const char *format, int *t, va_list list)
{
	int curr_t = *t + 1;
	int precision = -1;

	if (format[curr_t] != '.')
		return (precision);

	precision = 0;

	curr_t++;

		if (format[curr_t] == '*')
		{
			curr_t++;
			precision = va_arg(list, int);
		}
		else
		{
			while (is_digit(format[curr_t]))
			{
				precision = precision * 10 + (format[curr_t] - '0');
				curr_t++;
			}
		}

	*t = curr_t - 1;

	return (precision);
}

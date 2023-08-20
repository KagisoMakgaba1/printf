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

	for (curr_t += 1; format[curr_t] != '\0'; curr_t++)
	{
		if (is_digit(format[curr_t]))
		{
			precision *= 10;
			precision += format[curr_t] - '0';
		}
		else if (format[curr_t] == '*')
		{
			curr_t++;
		precision = va_arg(list, int);
		break;
		}
		else
			break;
	}

	*t = curr_t - 1;

	return (precision);
}

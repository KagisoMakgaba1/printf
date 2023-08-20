#include "main.h"

/**
 * get_width - determines to print
 * @format: string in which to print argument
 * @t: list of arguments to print
 * @list: list
 * Return: width
 */

int get_width(const char *format, int *t, va_list list)
{
	int curr_t;
	int width = 0;

	for (curr_t = *t + 1; format[curr_t] != '\0'; curr_t++)
	{
		if (is_digit(formart[curr_t]))

			width *= 10;
			width += format[curr_t] - '0';


		else if (format[curr_t] == '*')

			curr_t++;
			width - va_arg(list, int);
			break;

		else
			break;
	}

	*t = curr_t - 1;

	return (width);
}

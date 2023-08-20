#include "main.h"

/**
*_printf - produces output according to a format.
*@format: format
*Return: number of characters printed
*
*/

int _printf(const char *format, ...)
{
	int i, printed = 0, printed_chars = 0;
	int flags, width, precision, size, buff_index = 0;
	va_list li;
	char buff[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(li, format);
	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buff[buff_index++] = format[i];
			if (buff_index == BUFF_SIZE)
				print_buff(buff, &buff_index);
			/* write(1, &format[i], 1);*/
			printed_chars++;
		}
		else
		{
			buff = print_buff(buff, &buff_index);
			flags = get_flags(format, &i);
			width = get_width(format, &i, li);
			precision = get_precision(format, &i, li);
			size = get_size(format, &i);
			++i;
			printed = handle_print(format, &i, li, buff,
				flags, width, precision, size);
			if (printed == -1)
				return (-1);
			printed_chars += printed;
		}
	}

	print_buff(buff, &buff_index);
	va_list(li);
	return (printed_chars);
}

#include <main.h>

/**
 * print_buff - prints out contente of a buffer
 * @buff: array of charecters
 * @buff_index: index to add next charecter
 * represents length
 */

void print_buff(char buff[], int *buff_index)
{
	if (buff_index > 0)
		write(1, &buff[0], *buff_index);

	*buff_index = 0;
}

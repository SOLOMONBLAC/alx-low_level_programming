#include "main.h"

/**
 * get_bit - returns the value of a bit at an index in a decimal number
 * @n: number to search
 * @index: index of the bit
 *
 * Return: value of the bit
 */
int get_bit(unsigned long int n, unsigned int index)
{
	unsigned long int mask = 1;
	int bitvalue_1;

	if (index > 63)
		return (-1);

	mask <<= index;
	bitvalue_1 = (n & mask) ? 1 : 0;

	return (bitvalue_1);
}

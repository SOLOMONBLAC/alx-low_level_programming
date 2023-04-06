#include <stdio.h>
#include "main.h"

/**
 * _print_rev_recursion - Prints a string in reverse.
 * @s: The string to be printed.
 */

void _puts_recursion(char *s)
{
	if (*s)
{
	_putchar(*s);
	_puts_recursion(s + 1);
}

else
	_putchar('\n');
}


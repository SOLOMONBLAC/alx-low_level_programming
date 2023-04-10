#include <stdlib.h>
#include <stdio.h>
#include "main.h"

/**
 * main - Prints the name of arguments passed into main
 * @argc: Number of command line arguments
 * @argv: Array name
 * Return: 0
 */

int main(int argc, char *argv[])
{
	(void)argc;
	printf("%s\n", argv[0]);
	return (0);
}

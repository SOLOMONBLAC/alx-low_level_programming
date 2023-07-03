#include <stdio.h>
#include <stdlib.h>

void first(void);
void printBeforeMain(void);

/**
 * first - prints a sentence before the main
 * function is executed
 */
void first(void)
{
	printf("You're beat! and yet, you must allow,\n");
	printf("I bore my house upon my back!\n");
}

/**
 * printBeforeMain - function to be called before
 * program exit
 */
void printBeforeMain(void)
{
	first();
}

/**
 * main - Entry point of the program
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	atexit(printBeforeMain);

	printf("Main function\n");

	return (0);
}


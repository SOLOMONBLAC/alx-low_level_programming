#include <stdio.h>
#include <stdlib.h>

void printNumbers(int n)
{
	int i;

	for (i = 1; i <= n; i++)
	{
	printf("%d ", i);
	}
	printf("\n");
}

int main(void)
{
	int num;

	printf("Enter a number: ");
	scanf("%d", &num);
	printNumbers(num);
	return (0);
}

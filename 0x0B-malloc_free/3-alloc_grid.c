#include "main.h"
#include <stdlib.h>

/**
 * alloc_grid - nested loop to make grid
 * @width: width input
 * @height: height input
 * Return: pointer to 2 dim. array
 */

int **alloc_grid(int width, int height)

{
	int **aaa;
	int b, c;

	if (width <= 0 || height <= 0)
	return (NULL);

	aaa = malloc(sizeof(int *) * height);
	if (aaa == NULL)
	return (NULL);

	for (b = 0; b < height; b++)
	{
	aaa[b] = malloc(sizeof(int) * width);

	if (aaa[b] == NULL)
	{
	for (; b >= 0; b--)
	free(aaa[b]);
	free(aaa);
	return (NULL);
	}
	}
	for (b = 0; b < height; b++)
	{
	for (c = 0; c < width; c++)
	aaa[b][c] = 0;
	}
	return (aaa);
}

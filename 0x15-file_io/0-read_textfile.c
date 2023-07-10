#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * read_textfile- Read text file print to STDOUT.
 * @filename: text file being read
 * @letters: number of letters to be read
 * Return: w- actual number of bytes read and printed
 *         0 when function fails or filename is NULL.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	FILE *file;
	char *buf;
	ssize_t w;

	if (filename == NULL)
		return (0);

	file = fopen(filename, "r");
	if (file == NULL)
		return (0);

	buf = malloc(sizeof(char) * (letters + 1));
	if (buf == NULL)
	{
		fclose(file);
		return (0);
	}

	w = fread(buf, sizeof(char), letters, file);
	buf[w] = '\0'; /* Null-terminate the buffer */

	printf("%s", buf);

	free(buf);
	fclose(file);

	return (w);
}

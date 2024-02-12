#include "main.h"

/**
 * read_textfile - reads the text file and prints it to the POSIX stdr output
 * @filename: file name
 * @letters: number of letters it should read and print
 *
 * Return: the actual number of letters it could read and print, 0 if failed
 */

ssize_t read_textfile(const char *filename, size_t letters)
{

	ssize_t fl, lt, wr;
	char *txt;

	txt = malloc(letters);
	if (!txt)
		return (0);

	if (!filename)
		return (0);

	fl = open(filename, O_RDONLY);

	if (fl == -1)
	{
		free(txt);
		return (0);
	}

	lt = read(fl, txt, letters);

	wr = write(STDOUT_FILENO, txt, lt);

	close(fl);

	return (wr);
}

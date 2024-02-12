#include "main.h"


/**
* main - program that copies the content of a file to another file
* @argc: num argument
* @argv: string argument
* Return: 0
*/

int main(int argc, char *argv[])
{
int f_from, f_to;
int n1 = 1024, n2 = 0;
char buf[1024];

if (argc != 3)
	dprintf(STDERR_FILENO, "Usage: cp f_from f_to\n"), exit(97);
f_from = open(argv[1], O_RDONLY);
if (f_from == -1)
{
	dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
	exit(98);
}
f_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR
	| S_IRGRP | S_IWGRP | S_IROTH);
if (f_to == -1)
{
	dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
	close(f_from), exit(99);
}
while (n1 == 1024)
{
	n1 = read(f_from, buf, 1024);
	if (n1 == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}
	n2 = write(f_to, buf, n1);
	if (n2 < n1)
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]), exit(99);
}

if (close(f_from) == -1)
	dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", f_from), exit(100);

if (close(f_to) == -1)
	dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", f_to), exit(100);

return (0);
}

#include "main.h"

#define BUF_SIZE 1024

void print_error_and_exit(int code, const char *format, const char *arg)
{
	dprintf(STDERR_FILENO, format, arg);
	exit(code);
}

void close_file_descriptor(int fd)
{
	if (close(fd) == -1)
		print_error_and_exit(100, "Error: Can't close fd %d\n", fd);
}

int main(int argc, char *argv[])
{
	if (argc != 3)
		print_error_and_exit(97, "Usage: cp file_from file_to\n", NULL);

	int f_from = open(argv[1], O_RDONLY);
	if (f_from == -1)
		print_error_and_exit(98, "Error: Can't read from file %s\n", argv[1]);

	int f_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH);
	if (f_to == -1)
		print_error_and_exit(99, "Error: Can't write to %s\n", argv[2]);

	char buf[BUF_SIZE];
	ssize_t bytes_read, bytes_written;

	while ((bytes_read = read(f_from, buf, BUF_SIZE)) > 0)
	{
		bytes_written = write(f_to, buf, bytes_read);
		if (bytes_written != bytes_read)
			print_error_and_exit(99, "Error: Can't write to %s\n", argv[2]);
	}

	if (bytes_read == -1)
		print_error_and_exit(98, "Error: Can't read from file %s\n", argv[1]);

	close_file_descriptor(f_from);
	close_file_descriptor(f_to);

	return 0;
}

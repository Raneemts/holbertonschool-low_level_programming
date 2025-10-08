#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

#define BUF_SIZE 1024

/**
 * close_or_die - close a file descriptor or exit with code 100
 * @fd: file descriptor to close
 */
static void close_or_die(int fd)
{
	if (close(fd) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(100);
	}
}

/**
 * main - copy the content of one file to another
 * @ac: argument count
 * @av: argument vector
 *
 * Return: 0 on success, exits with 97/98/99/100 on error
 */
int main(int ac, char **av)
{
	int fd_from, fd_to;
	ssize_t r, w, off;
	char buf[BUF_SIZE];

	if (ac != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	fd_from = open(av[1], O_RDONLY);
	if (fd_from == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", av[1]);
		exit(98);
	}

	fd_to = open(av[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (fd_to == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", av[2]);
		close_or_die(fd_from);
		exit(99);
	}

	while (1)
	{
		do {
			r = read(fd_from, buf, BUF_SIZE);
		} while (r == -1 && errno == EINTR);

		if (r == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", av[1]);
			close_or_die(fd_from);
			close_or_die(fd_to);
			exit(98);
		}
		if (r == 0)
			break;

		off = 0;
		while (off < r)
		{
			do {
				w = write(fd_to, buf + off, r - off);
			} while (w == -1 && errno == EINTR);

			if (w == -1)
			{
				dprintf(STDERR_FILENO, "Error: Can't write to %s\n", av[2]);
				close_or_die(fd_from);
				close_or_die(fd_to);
				exit(99);
			}
			off += w;
		}
	}

	close_or_die(fd_from);
	close_or_die(fd_to);
	return (0);
}

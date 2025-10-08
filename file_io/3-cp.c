#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

#define BUF 1024

/**
 * close_or_die - close a file descriptor or exit with code 100
 * @fd: file descriptor
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
 * open_from - open source file for reading or exit with code 98
 * @path: source file path
 * Return: opened fd
 */
static int open_from(const char *path)
{
	int fd = open(path, O_RDONLY);

	if (fd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", path);
		exit(98);
	}
	return (fd);
}

/**
 * open_to - open destination file for writing or exit with code 99
 * @path: destination file path
 * Return: opened fd
 */
static int open_to(const char *path)
{
	int fd = open(path, O_WRONLY | O_CREAT | O_TRUNC, 0664);

	if (fd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", path);
		exit(99);
	}
	return (fd);
}

/**
 * copy_loop - copy data from fd_from to fd_to using a 1KB buffer
 * @fd_from: source fd
 * @fd_to: destination fd
 * @from_name: source file name (for error messages)
 * @to_name: destination file name (for error messages)
 *
 * Exits with 98 on read error, 99 on write error.
 */
static void copy_loop(int fd_from, int fd_to,
		      const char *from_name, const char *to_name)
{
	ssize_t r, w, off;
	char buf[BUF];

	for (;;)
	{
		do {
			r = read(fd_from, buf, BUF);
		} while (r == -1 && errno == EINTR);

		if (r == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't read from file %s\n",
				from_name);
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
				dprintf(STDERR_FILENO, "Error: Can't write to %s\n",
					to_name);
				exit(99);
			}
			off += w;
		}
	}
}

/**
 * main - copy the content of a file to another
 * @ac: argument count
 * @av: argument vector
 * Return: 0 on success, exits with 97/98/99/100 on error
 */
int main(int ac, char **av)
{
	int f_from, f_to;

	if (ac != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	f_from = open_from(av[1]);
	f_to = open_to(av[2]);

	copy_loop(f_from, f_to, av[1], av[2]);

	close_or_die(f_from);
	close_or_die(f_to);
	return (0);
}

#include "function_pointers.h"

/**
 * print_name - prints a name using the given function
 * @name: string to print
 * @f: pointer to a function that takes a char * and returns void
 *
 * Return: Nothing.
 */
void print_name(char *name, void (*f)(char *))
{
	if (name && f)
		f(name);
}

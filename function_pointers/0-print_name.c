#include "function_pointers.h"
#include <stdlib.h>

/**
 * print_name - prints a name using the given function
 * @name: string to print
 * @f: function pointer to printing function
 *
 * Return: Nothing
 */
void print_name(char *name, void (*f)(char *))
{
	if (name != NULL && f != NULL)
		f(name);
}

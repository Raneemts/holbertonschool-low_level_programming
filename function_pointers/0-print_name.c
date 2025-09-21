#include <stdio.h>
/**
  * print_name - calls function that prints a name
  * @name: pointer to the name to print
  * @f: pointer to a function that prints a name
  * Return: Nothing
  */
void print_name(char *name, void (*f)(char *))
{
if (name != NULL && f != NULL)
f(name);
}

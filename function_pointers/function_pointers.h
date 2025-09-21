#ifndef FUNCTION_POINTERS_H
#define FUNCTION_POINTERS_H

/**
 * print_name - prints a name using a callback
 * @name: string to print
 * @f: function pointer
 */
void print_name(char *name, void (*f)(char *));

#endif /* FUNCTION_POINTERS_H */

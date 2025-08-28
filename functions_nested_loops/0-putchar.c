#include<stdio.h>
#include"main.h"
/**
 * main - Check description
 * Description: It prints the word putchar, followed by a new line.
 * Return: 0.
 */
int main(void)
{
	char str[8] = "_putchar";
	int i;

	for (i = 0; i < 8; i++)
		_putchar(str[i]);
	_putchar('\n');

	return (0);
}

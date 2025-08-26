#include<stdio.h>

/**
 * main - Entry point
 *
 * Description: Prints the alphabet in lowercase
 * followed by a new line using putchar.
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	char low;

	for (low = 'a'; low <= 'z'; low++)
		putchar(low);
	putchar('\n');

	return (0);
}

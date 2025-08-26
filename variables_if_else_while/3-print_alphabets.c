#include<stdio.h>
/**
 * main - Entry point
 *
 * Description: Prints the alphabet in lowercase then uppercase
 * followed by a new line using putchar.
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	char low;
	char up;

	for (low = 'a'; low <= 'z'; low++)
		putchar(low);
	for (up = 'A'; up <= 'Z'; up++)
		putchar(up);
	putchar('\n');

	return (0);
}

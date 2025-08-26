#include<stdio.h>
/**
 * main - Entry point
 *
 * Description: Prints the alphabet in lowercase except e and q
 * followed by a new line using putchar.
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	char low, e, q;

	e = 'e';
	q = 'q';

	for (low = 'a'; low <= 'z' ; low++)
	{
		if (low != e && low != q)
			putchar(low);
	}
	putchar('\n');

	return (0);
}

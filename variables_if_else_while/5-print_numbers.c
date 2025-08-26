#include<stdio.h>
/**
 * main - Entry point
 *
 * prints all single digit numbers of base 10 starting from 0, followed by a new line.
 * followed by a new line using putchar.
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int i;

	for (i = 0; i <= 9; i++)
		printf("%d", i);
	printf("\n");

	return (0);
}

#include "lists.h"
#include<stdio.h>

/**
 * dlistint_len - A function that returns the number of elements int the list
 * @h: A pointer to dlistint_t structure
 * Return: number of elemtnts
 */
size_t dlistint_len(const dlistint_t *h)
{
	size_t nodes = 0;

	while (h != NULL)
	{
		h = h->next;
		nodes++;
	}

	return (nodes);
}

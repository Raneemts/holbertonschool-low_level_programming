#include"lists.h"

/**
 * sum_dlistint - return the sum of all data (n) in dlistint_t list
 * @head: pointer to the head of list
 * Return: sum of all data (n), or 0 if the list is empty
 */
int sum_dlistint(dlistint_t *head)
{
	int sum = 0;

	while (head != NULL)
	{
		sum = sum + head->n;
		head = head->next;
	}

	return (sum);
}

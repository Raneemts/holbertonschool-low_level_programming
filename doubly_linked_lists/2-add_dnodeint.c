#include"lists.h"
#include<stdio.h>

/**
 * add_dnodeint - A function that adda a new node at the begining of a list
 * @head: A pointer to dlist_t structure
 * @n: AN integer data to put it in the new node
 * Return: the address of the new element, or NULL when failure
 */
dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
	dlistint_t *new_node;

	new_node = *head;
	*head = malloc(sizeof(dlistint_t));

	if (!*head)
		return (NULL);

	(*head)->n = n;
	(*head)->next = new_node;
	return (*head);
}

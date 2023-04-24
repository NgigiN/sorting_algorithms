#include "sort.h"

/**
 * insertion_sort_list - sorts a double linked list
 * of integers in asceding sort
 *
 * @list: double pointer list to be sorted
 *
 * Swap the nodes themselves
 * prints the list after each time a swap occurs
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *current, *previous, *next;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (current = (*list)->next; current != NULL; current = next)
	{
		next = current->next;
		previous = current->prev;
		while (previous != NULL && current->n < previous->n)
		{
			previous->next = current->next;
			if (current->next != NULL)
				current->next->prev = previous;
			current->next = previous;
			current->prev = previous->prev;
			if (previous->prev != NULL)
				previous->prev->next = current;
			else
				*list = current;
			previous->prev = current;
			print_list(*list);
			previous = current->prev;
		}
	}
}

#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm
 * @list: Pointer to the head of the doubly linked list
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *current, *prev, *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	
	current = (*list)->next;
	while (current)
	{
		/*Store the necessary pointers for swapping*/
		temp = current;
		prev = current->prev;

		/* Compare and swap nodes if needed */
		while (prev != NULL && temp->n <prev->n)
		{
			/*Adjust pointers to swap nodes*/
			temp->prev = prev->prev;
			prev->next =temp->next;

			if (temp->next != NULL)
				temp->next->prev = prev;
			temp->next = prev;
			prev->prev = temp;

			if (temp->prev != NULL)
				temp->prev->next = temp;
			else
				/* Update head if needed */
				*list = temp;
			/* Print list after each swap */
			print_list(*list);
			/* Update pointers for the next iteration */
			prev = temp->prev;
		}

		current = current->next;
	}
}

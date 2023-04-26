nclude "sort.h"

/**
 * swap - function that swaps nodes in a doubly linked list of integers
 * @a: first node to be swapped
 * @b: second node to be swapped
 * @list: doubly linked list of integers
 * Return: void
 */
void swap(listint_t *a, listint_t *b, listint_t **list)
{
	/* Update the next and previous pointers of the nodes being swapped */
	a->next = b->next;
	b->prev = a->prev;
	if (a->next)
		a->next->prev = a;
	if (b->prev)
		b->prev->next = b;

	/* Update the next and previous pointers of the nodes surrounding the swapped nodes */
	a->prev = b;
	b->next = a;
	if (a == *list)
		*list = b;

	print_list(*list);
}

/**
 * cocktail_sort_list - function that sorts a doubly linked list of integers
 * in ascending order using the Cocktail shaker sort algorithm
 * @list: doubly linked list of integers
 * Return: void
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *left, *right;
	int swapped = 1;

	if (list == NULL || *list == NULL)
		return;

	left = *list;
	right = NULL;

	while (swapped == 1)
	{
		/* Here we are going forward */
		swapped = 0;
		while (left->next != right)
		{
			if (left->n > left->next->n)
			{
				swapped = 1;
				swap(left, left->next, list);
			}
			else
				left = left->next;
		}

		right = left;
		if (swapped == 0)
			break;

		/* Here we are going backward */
		swapped = 0;
		while (right->prev != NULL)
		{
			if (right->n < right->prev->n)
			{
				swapped = 1;
				swap(right->prev, right, list);
			}
			else
				right = right->prev;
		}

		left = right;
	}
}

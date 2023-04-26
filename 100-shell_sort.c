#include "sort.h"

/**
 * shell_sort - sorts an array of integers in ascending order using the Shell sort algorithm
 * @array: array of integers
 * @size: length of array
 */
void shell_sort(int *array, size_t size)
{
	size_t interval = 1, i, j;
	int temp;

	if (array == NULL || size < 2)
		return;

	/* Calculate initial interval size using Knuth's formula */
	while (interval <= size / 3)
	{
		interval = interval * 3 + 1;
	}

	while (interval > 0)
	{
		for (i = interval; i < size; i++)
		{
			temp = array[i];
			j = i;

			/* Shift elements to the right */
			while (j >= interval && array[j - interval] > temp)
			{
				array[j] = array[j - interval];
				j = j - interval;
			}

			/* Insert element at the correct position */
			array[j] = temp;
		}

		/* Calculate the next interval size */
		interval = (interval - 1) / 3;

		/* Print the current state of the array */
		print_array(array, size);
	}
}


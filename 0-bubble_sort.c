#include "sort.h"

/**
 * bubble_sort - Sorts an array of integers in ascending order using Bubble sort
 * @array: The array to be sorted
 * @size: Number of element in array
 *
 */
void bubble_sort(int *array, size_t size)
{
	int swapped;
	int temp;
	size_t i, j;

	if (array == NULL || size < 2)
		return;

	/*number of passes required to sort the array*/
	for (i = 0; i < size - 1; i++)
	{
		/* check if any swaps occurred in this pass*/
		swapped = 0;
		
		/*Compare and swap adjacent elements*/
		for (j = 0; j < size - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				/* Swap elements */
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				/*set swapped flag*/
				swapped = 1;
				/* Print array after each swap */
				print_array(array, size);
			}
		}

		/* If no two elements were swapped, the array is already sorted */
		if (swapped == 0)
			break;
	}
}


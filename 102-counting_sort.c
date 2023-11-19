#include "sort.h"
#include <stdlib.h>

/**
* counting_sort - Sorts an array of integers in ascending order
*                 using the Counting sort algorithm
*
* @array: The array to be sorted
* @size: Number of elements in the array
*/
void counting_sort(int *array, size_t size)
{
int *count_array, *output_array;
int max, i;

if (array == NULL || size < 2)
return;

max = array[0];

/* Find the maximum value in the array */
for (i = 1; i < (int)size; ++i)
{
if (array[i] > max)
max = array[i];
}

/* Allocate memory for the counting array */
count_array = malloc((max + 1) * sizeof(int));
if (count_array == NULL)
return;

/* Initialize the counting array to 0 */
for (i = 0; i <= max; ++i)
count_array[i] = 0;

/* Count occurrences of each element in the array */
for (i = 0; i < (int)size; ++i)
count_array[array[i]]++;

/* Print the counting array */
print_array(count_array, max + 1);

/* Update the counting array to store the cumulative count */
for (i = 1; i <= max; ++i)
count_array[i] += count_array[i - 1];

/* Allocate memory for the output array */
output_array = malloc(size * sizeof(int));
if (output_array == NULL)
{
free(count_array);
return;
}

/* Build the output array using the counting array */
for (i = (int)size - 1; i >= 0; --i)
{
output_array[count_array[array[i]] - 1] = array[i];
count_array[array[i]]--;
}

/* Copy the sorted elements back to the original array */
for (i = 0; i < (int)size; ++i)
array[i] = output_array[i];

/* Print the sorted array */
print_array(array, size);

/* Free allocated memory */
free(count_array);
free(output_array);
}


#include "sort.h"

/**
* shell_sort - Sorts an array of integers in ascending order
*              using the Shell sort algorithm with Knuth sequence
*
* @array: The array to be sorted
* @size: Number of elements in the array
*/
void shell_sort(int *array, size_t size)
{
size_t gap = 1, i, j;
int temp;

if (array == NULL || size < 2)
return;

/* Calculate the initial gap using the Knuth sequence */
while (gap < size / 3)
gap = gap * 3 + 1;

/* Start with the largest gap and reduce it until gap is 1 */
for (; gap > 0; gap /= 3)
{
for (i = gap; i < size; ++i)
{
/* Perform insertion sort on elements with the current gap */
temp = array[i];

for (j = i; j >= gap && array[j - gap] > temp; j -= gap)
{
array[j] = array[j - gap];

/* Print array after each decrease in the interval */
print_array(array, size);
}

array[j] = temp;
}
}
}


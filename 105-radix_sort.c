#include "sort.h"
/**
 *get_max - gets the maximum integer in an array
 *@array:array to loop
 *@size:size of array
 *Return:max element
 */
int get_max(int *array, int size)
{
	int max = array[0], i;

	for (i = 0; i < size; i++)
		if (array[i] > max)
			max = array[i];
	return max;
}
/**
 *countingSort - sorts elements in terms of significant places
 *@array:array to sort
 *@size:size of array
 *@place:place value
 */
void countingSort(int *array, int size, int place)
{
	int *output, *count, i, max;

	output = malloc(sizeof(int) * size);
	if (output == NULL)
		return;
	max = (array[0] / place) % 10;
	for (i = 1; i < size; i++)
	{
		if (((array[i] / place) % 10) > max)
			max = array[i];
	}
	count = malloc(sizeof(int) * max);
	if (count == NULL)
		return;
	/*calculating count of elements*/
	for (i = 0; i < size; i++)
		count[(array[i] / place) % 10]++;
	/*cumulative count*/
	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];
	/*place the elements in sorted order*/
	for (i = size - 1; i >= 0; i--)
	{
		output[count[(array[i] / place) % 10] - 1] = array[i];
		count[(array[i] / place) % 10]--;
	}
	for (i = 0; i < size; i++)
		array[i] = output[i];
}
/**
 *radix_sort - sorts an array using radix sort
 *@array:array to sort
 *@size:size of our array
 */
void radix_sort(int *array, size_t size)
{
	int max, place;

	size = (int)size;
	max = get_max(array, size);

	for (place = 1; max / place > 0; place *= 10)
	{
		countingSort(array, size, place);
		print_array(array, size);
	}
}

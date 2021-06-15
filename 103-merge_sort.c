#include "sort.h"
/**
 *merge - merges two subarrays into one array
 *@array:ojr array
 *@p:index of first element of first array
 *@q:division point L[p, q] M[q+1, r]
 *@r:last element of second array
 *Return:void
 */
void merge(int *array, int p, int q, int r)
{
	int *l, *m, n1, n2, i, j, k;

	n1 = q - p + 1;
	n2 = r - q;
	l = malloc(sizeof(int) * n1);
	if (l == NULL)
		return;
	m = malloc(sizeof(int) * n2);
	if (m == NULL)
		return;
	printf("Merging...\n[left]: ");
	print_array(array + p, n1);
	printf("[right]: ");
	print_array(array + q + 1, n2);
	for (i = 0; i < n1; i++)
	{
		l[i] = array[p + i];
	}
	for (i = 0; i < n2; i++)
		m[i] = array[q + 1 + i];
	/*maintain current index of sub-arrays and main array*/
	i = 0;
	j = 0;
	k = p;
	/*until we reach the end of either arrays l and m, place */
	/*place them in the correct positions*/
	while (i < n1 && j < n2)
	{
		if (l[i] <= m[j])
		{
			array[k] = l[i];
			i++;
		}
		else
		{
			array[k] = m[j];
			j++;
		}
		k++;
	}
	/* when we run out of elements in either arrays, pick*/
	/*remainders place them in array[p...q]*/
	while (i < n1)
	{
		array[k] = l[i];
		i++;
		k++;
	}
	while (j < n2)
	{
		array[k] = m[j];
		j++;
		k++;
	}
	printf("[Done]: ");
	print_array(array + p, r - p + 1);
}
/**
 *merge_recursive - merges an array recursively
 *@l:first index
 *@r: last index
 */
void merge_recursive(int *array, int front, int back)
{
	int m;

	if (front < back)
	{
		m = front + (back - front) / 2;
		merge_recursive(array, front, m);
		merge_recursive(array, m + 1, back);
		merge(array, front, m, back);
	}
}
/**
 *merge_sort - sorts an array using merge_sort algorithm
 *@array:array to sort
 *@size:size of array
 */
void merge_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	merge_recursive(array, 0, (int)size);
}
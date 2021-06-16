#include "sort.h"
/**
 *swap - swaps two integers in an array
 *@a:first int to swap
 *@b: second int to swap
 */
void swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

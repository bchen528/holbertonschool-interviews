#include "slide_line.h"

/**
 * swap - swap two values
 *
 * @arr: array of integers
 * @a: first element
 * @b: second element
 */
void swap(int *arr, int a, int b)
{
	int temp;

	temp = arr[a];
	arr[a] = arr[b];
	arr[b] = temp;
}

/**
 * slide_line - slide and merge integers to left or right
 *
 * @line: pointer to array of integers to be slided & merged left or right
 * @size: number of elements in line
 * @direction: left or right
 * Return: 0 on failure, 1 on success
 */
int slide_line(int *line, size_t size, int direction)
{
	size_t i, j, k, m;

	if (!line)
		return (0);

	if (direction == 1) /*slide left*/
	{
		for (i = 0; i < size - 1; i++)
			for (j = 0; j < size - i - 1; j++)
				if (line[j] == 0)
					swap(line, j, j + 1);
		for (k = 0; line[k + 1] != 0 && k < size; k++)
		{
			if (line[k] == line[k + 1])
			{
				line[k] += line[k + 1];
				line[k + 1] = 0;
				for (m = 0; m < size - k - 1; m++)
					if (line[m] == 0)
						swap(line, m, m + 1);
			}
		}
	}
	else /*slide right*/
	{
		for (i = 0; i < size - 1; i++)
			for (j = size - 1; j > 0; j--)
				if (line[j] == 0)
					swap(line, j, j - 1);
		for (k = size - 1; line[k - 1] != 0 && k > 0; k--)
		{
			if (line[k] == line[k - 1])
			{
				line[k] += line[k - 1];
				line[k - 1] = 0;
			}
			for (m = size - 1; m > 0; m--)
				if (line[m] == 0)
					swap(line, m, m - 1);
		}

	}
	return (1);
}

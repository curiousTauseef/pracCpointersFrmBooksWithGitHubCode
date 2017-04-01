#include <stdio.h>

#define SIZE 6

int main()
{
	int i, j, arr[SIZE][SIZE] = {0}; /* Initialize the arr elements with 0. */
	for(i = 0; i < SIZE; i++)
	{
		for(j = 0; j < SIZE; j++)
		{
			if(i == j) /* Check if it is an element of the main diagonal. */
				arr[i][j] = 1;

			printf("%3d", arr[i][j]);
		}
		printf("\n"); /* Add it to separate the array rows. */
	}
	return 0;
}
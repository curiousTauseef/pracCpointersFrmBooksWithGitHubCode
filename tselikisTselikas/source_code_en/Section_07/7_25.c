#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 5

int main()
{
	int i, j, determ, arr[SIZE][SIZE];

	determ = 1; /* Initialize with 1 the variable which calculates the product of the main diagonal’s elements and is equal to the determinant of the matrix. */
	srand(time(NULL)); 
	for(i = 0; i < SIZE; i++)
	{
		for(j = 0; j < SIZE; j++)
		{
			if(i > j) 
				arr[i][j] = 0; /* Initialize with 0 the elements under the main diagonal. We could have initialized arr with 0, but we do it here to make it clearer. */
			else 
				arr[i][j] = rand()%7-3; /* The result of the expression rand()%7 is an integer within [0,6]. By subtracting 3, the integer is constrained in [-3,3]. */
			printf("%5d", arr[i][j]);
			if(i == j)
				determ *= arr[i][j]; 
		}
		printf("\n");
	}
	printf("\nThe determinant is: %d\n", determ);
	return 0;
}
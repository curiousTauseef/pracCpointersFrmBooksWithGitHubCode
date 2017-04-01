#include <stdio.h>

#define SIZE 5

int main()
{
	int i, j, num, t[SIZE][SIZE]; 

	for(i = 0; i < SIZE; i++)
	{
		printf("Enter number: ");
		scanf("%d", &num);

		t[0][i] = num; /* The elements of the first row become equal to the input numbers. */
		t[i][0] = num; /* The elements of the first column become equal to the input numbers. */
	}
	/* Create the Toeplitz matrix.  */
	for(i = 0; i < SIZE-1; i++)
		for(j = 0; j < SIZE-1; j++)
			t[i+1][j+1] = t[i][j]; /* We traverse the array t and make each element equal to the upper left.  */
	for(i = 0; i < SIZE; i++)
	{
		for(j = 0; j < SIZE; j++)
			printf("%3d", t[i][j]);
		printf("\n"); 
	}
	return 0;
}
#include <stdio.h>

#define ROWS 2
#define COLS 4

int main()
{
	int i, j, tot_sum, tmp, arr[ROWS][COLS];

	tot_sum = 0;
	for(i = 0; i < ROWS; i++)
	{
		/* Initialize with 0 when start calculating the sum of a row’s elements. */
		tmp = 0;
		for(j = 0; j < COLS; j++)
		{
			printf("Enter the element arr[%d][%d]: ",i,j);
			scanf("%d", &arr[i][j]);

			tot_sum += arr[i][j];
			tmp += arr[i][j];
		}
		printf("Row_%d: Sum = %d\n", i+1, tmp);
	}
	printf("\n");
	for(i = 0; i < COLS; i++)
	{
		/* Initialize with 0 when start calculating the sum of a column’s elements. */
		tmp = 0;
		for(j = 0; j < ROWS; j++)
			tmp += arr[j][i];

		printf("Col_%d: Sum = %d\n", i+1, tmp);
	}
	printf("\nTotal_Sum = %d\n", tot_sum);
	return 0;
}
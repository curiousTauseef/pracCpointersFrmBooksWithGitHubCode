#include <stdio.h>
#include <stdlib.h>

int main()
{
	int i, j, rows, cols;
	double **arr; /* We handle the two-dimensional array as pointer to pointer. */

	while(1)
	{
		printf("\nEnter dimensions of array[N][M] (zero or less to terminate): ");
		scanf("%d%d", &rows, &cols);

		if(rows <= 0 || cols <= 0)
			return 0;

		arr = (double**) malloc(rows * sizeof(double*)); /* We allocate memory for 'rows? pointers to doubles. For example, if rows is 3, we allocate memory for arr[0], arr[1] and arr[2] pointers. */
		if(arr == NULL)
		{
			printf("Error: Not available memory\n");
			exit(1);
		}
		for(j = 0; j < rows; j++)
		{
			arr[j] = (double*) malloc(cols * sizeof(double)); /* Allocate memory to store the elements of each row. Each row contains 'cols? elements. */
			if(arr[j] == NULL)
			{
				printf("Error: Not available memory\n");
				exit(1);
			}
		}
		for(i = 0; i < rows; i++)
			for(j = 0; j < cols; j++)
			{
				printf("Set arr[%d][%d]: ", i, j);
				scanf("%lf", &arr[i][j]);
				printf("arr[%d][%d] = %f\n", i, j, arr[i][j]);
			}
		for(j = 0; j < rows; j++)
			free(arr[j]);

		free(arr);
	}
	return 0;
}
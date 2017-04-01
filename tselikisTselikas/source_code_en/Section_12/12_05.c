#include <stdio.h>

#define SIZE 10 

void sel_sort(double arr[], int size);

int main()
{
	int i;
	double a[SIZE];

	for(i = 0; i < SIZE; i++)
	{
		printf("Enter number: ");
		scanf("%lf", &a[i]);
	}
	sel_sort(a, SIZE);

	printf("\n***** Sorted array *****\n");
	for(i = 0; i < SIZE; i++)
		printf("%f\n", a[i]);
	return 0;
}

void sel_sort(double arr[], int size)
{
	int i, j; 
	double temp;

	for(i = 0; i < size; i++)
	{
		for(j = i+1; j < size; j++)
		{
			if(arr[i] > arr[j])
			{
				/* Swap values. */
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}
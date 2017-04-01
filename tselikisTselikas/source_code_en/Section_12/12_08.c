#include <stdio.h>

#define SIZE 5

void insert_sort(int arr[], int size);

int main()
{
	int i, a[SIZE];

	for(i = 0; i < SIZE; i++)
	{
		printf("Enter number: ");
		scanf("%d", &a[i]);
	}
	insert_sort(a, SIZE);
	printf("\n***** Sorted array *****\n");
	for(i = 0; i < SIZE; i++)
		printf("%d\n", a[i]);
	return 0;
}

void insert_sort(int arr[], int size)
{
	int i, j, temp;

	for(i = 1; i < size; i++)
	{
		temp = arr[i];
        	j = i;
        	while((j > 0) && (arr[j-1] > temp))
        	{
			arr[j] = arr[j-1]; /* Shift this element one position to the right. */
            	j--;
        	}
        	arr[j] = temp;
	}
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void fill_table(int arr[], int size);
void find_inter(int arr1[], int arr2[], int size);
void find_union(int arr1[], int arr2[], int size);

int main()
{
	int *arr1, *arr2, sel, size;

	arr1 = arr2 = NULL;
	while(1) 
	{
		printf("\nMenu selections\n");
		printf("---------------\n");

		printf("1. Intersection\n");
		printf("2. Union\n");
		printf("3. Exit\n");

		printf("\nEnter choice: ");
		scanf("%d", &sel);

		switch(sel)
		{
			case 1:
				do
				{
					printf("\nEnter size: ");
					scanf("%d", &size);
				} while(size <= 0);

				/* Free the allocated memory. */
				if(arr1 != NULL)
					free(arr1);
				if(arr2 != NULL)
					free(arr2);

				arr1 = (int *) malloc(size * sizeof(int));
				arr2 = (int *) malloc(size * sizeof(int));
				if(arr1 == NULL || arr2 == NULL)
				{
					printf("Not available memory");
					exit(1);
				}
				printf("\nArray_1 elements\n");
				fill_table(arr1, size);

				printf("\nArray_2 elements\n");
				fill_table(arr2, size);

				find_inter(arr1, arr2, size);
			break;

			case 2:
				if(arr1 && arr2) /* Check that memory has been allocated. */
					find_union(arr1, arr2, size);
			break;

			case 3:
				if(arr1 != NULL)
					free(arr1);
				if(arr2 != NULL)
					free(arr2);
			return 0; /* Program termination. */
		}
	}
	return 0;
}

void fill_table(int arr[], int size)
{
	int i, j, num, found;

	i = 0; /* It counts how many numbers are stored in the array. */
	while(i < size)
	{
		printf("Enter number: ");
		scanf("%d", &num);

		found = 0;
		/* Check if the input number is already stored in the array. If it is, the loop terminates. */
		for(j = 0; j < i; j++)
		{
			if(arr[j] == num)
			{
				printf("Error: %d is in array\n", num);
				found = 1;
				break;
			}
		}
		/* If the number isn’t found, store it. */
		if(found == 0)
		{
			arr[i] = num;
			i++;
		}
	}
}

void find_inter(int arr1[], int arr2[], int size)
{
	int *arr3, i, j, k;

	arr3 = (int *) malloc(size * sizeof(int));
	if(arr3 == NULL)
	{
		printf("Error: Not available memory\n");
		exit(1);
	}

	k = 0;
	for(i = 0; i < size; i++)
	{
		/* If a common element is found, store it in arr3 and increase k, which counts the number of stored items. */
		for(j = 0; j < size; j++)
		{
			if(arr1[i] == arr2[j])
			{
				arr3[k] = arr1[i];
				k++;
				break; /* This loop terminates and the external loop continues with the next arr1 element. */
			}
		}
	}
	if(k == 0)
		printf("\nResult: There is no common elements\n");
	else
	{
		printf("\nIntersection: ");
		for(i = 0; i < k; i++)
			printf("%d ", arr3[i]);
		printf("\n");
	}
	free(arr3);
}

void find_union(int arr1[], int arr2[], int size)
{
	int *arr3, i, j, k, found;

	/* The maximum memory size that may be needed is 2*size, which covers the worst case that the arrays have no common elements. */
	arr3 = (int *)malloc(2*size*sizeof(int));
	if(arr3 == NULL)
	{
		printf("Error: Not available memory\n");
		exit(1);
	}
	k = size;
	memcpy(arr3, arr1, size * sizeof(int)); /* First, store the arr1 elements. Other elements may be stored after the k-th place. */
	for(j = 0; j < size; j++)
	{
		found = 0;
		/* Check if arr2[j] exists in arr3. If it doesn’t, it is stored in arr3 and k, which counts the number of the stored items, is increased. */
		for(i = 0; i < size; i++)
		{
			if(arr2[j] == arr3[i])
			{
				found = 1;
				break;
			}
		}
		if(found == 0)
		{
			arr3[k] = arr2[j];
			k++;
		}
	}
	printf("\nUnion: ");
	for(i = 0; i < k; i++)
		printf("%d ", arr3[i]);

	printf("\n");
	free(arr3);
}
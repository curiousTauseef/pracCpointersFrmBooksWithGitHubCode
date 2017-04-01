#include <stdio.h>

#define SIZE 10

int main()
{
	int i, j, cmn, arr1[SIZE], arr2[SIZE];

	for(i = 0; i < SIZE; i++)
	{
		printf("Enter number for the 1st array: ");
		scanf("%d", &arr1[i]); 

		printf("Enter number for the 2nd array: ");
		scanf("%d", &arr2[i]);
	}
	cmn = 0;/* This variable counts the common elements. */
	for(i = 0; i < SIZE; i++)  
	{
		for(j = 0; j < SIZE; j++) /* This for loop checks if an element of the first array exists in the second one.  */ 
		{
			if(arr1[i] == arr2[j]) 
			{
				cmn++;
				printf("Cmn = %d (Pos_1 = %d Pos_2 = %d)\n", arr1[i], i, j);
			}
		}
	}
	printf("%d common elements were found\n", cmn);
	return 0;
}
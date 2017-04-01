#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

int main()
{
	int *ptr1, *ptr2, i, arr1[SIZE], arr2[SIZE];

	srand((unsigned)time(NULL));
	for(i = 0; i < SIZE; i++)
	{
		*(arr1+i) = rand(); 
		*(arr2+i) = rand(); 
	}
	ptr1 = arr1; 
	ptr2 = arr2; 
	for(i = 0; i < SIZE; i++)
	{
		*ptr1 = *ptr2; /* Equivalent to arr1[i] = arr2[i]; */
		ptr1++;  
		ptr2++; 
	}
	ptr1 = arr1; 
	ptr2 = arr2; 
	for(i = 0; i < SIZE; i++)
		printf("arr1[%d] = %d, arr2[%d] = %d\n", i, *(ptr1+ i), i, *(ptr2+i));
	return 0;
}
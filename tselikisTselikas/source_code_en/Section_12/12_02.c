#include <stdio.h>

#define SIZE 10

int num_occurs(int arr[]);

int main()
{
	int i, arr[SIZE];

	for(i = 0; i < SIZE; i++)
	{
		printf("Enter number: ");
		scanf("%d", &arr[i]);
	}
	printf("\nMax occurrences is %d\n", num_occurs(arr));
	return 0;
}

int num_occurs(int arr[])
{
	int i, j, max_times, num_times[SIZE] = {0}; /* In this array we store the occurrences of each element. For example, num_times[0] indicates the occurrences of the first element. */
	max_times = 0;
	for(i = 0; i < SIZE; i++)
	{
		for(j = i; j < SIZE; j++) /* Compare arr[i] against the rest elements. */
		{
			if(arr[i] == arr[j]) 
				num_times[i]++; /* If another element has the same value, increase its occurrences. */
		}
		if(max_times < num_times[i])
			max_times = num_times[i];
	}
	return max_times;
}
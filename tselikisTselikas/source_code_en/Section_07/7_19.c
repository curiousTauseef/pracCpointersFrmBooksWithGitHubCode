#include <stdio.h>

#define SIZE 100

int main()
{
	int i, j, temp, pop[SIZE];

	for(i = 0; i < SIZE; i++)
	{
		printf("Enter population: ");
		scanf("%d", &pop[i]);
		/* Compare the input value with the stored elements. The comparison is performed up to the position of the last input element, indicated by i. */
		for(j = 0; j < i; j++)  
		{
			if(pop[j] > pop[i]) /* Swap elements. */
			{
				temp = pop[j];
				pop[j] = pop[i];
				pop[i] = temp;
			}
		}
	}
	printf("\n*** Populations in increase order ***\n");
	for(i = 0; i < SIZE; i++)
		printf("%d ", pop[i]);
	return 0;
}
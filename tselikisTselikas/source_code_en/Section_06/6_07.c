#include <stdio.h>
int main()
{
	int i, sum;

	sum = 0; /* To calculate the sum, we initialize the sum variable to 0, which is the neutral element of the addition. */
	for(i = 1; i <= 200; i++)
		sum += i;

	printf("Sum = %d\n", sum);
	return 0;
}
#include <stdio.h>

int power(int base, int exp);

int main()
{
	int i, j;

	do
	{
		printf("Enter an integer and a positive integer (exponent): ");
		scanf("%d%d", &i, &j);
	}
	while(j < 0);

	printf("Result = %d\n", power(i, j));
	return 0;
}

int power(int base, int exp)
{
	int k, out;
	
	out = 1; /* Necessary initialization. */
	for(k = 0; k < exp; k++)
		out = out * base;  
	return out;
}
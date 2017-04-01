#include <stdio.h>
int main()
{
	int i, j, num, bits[32]; /* This array holds the bits of the number, that is 0 or 1. Since the size of an integer is 4 bytes, the length of the array is declared as 32. */

	do
	{
		printf("Enter positive number: ");
		scanf("%d", &num);
	} while(num <= 0);

	i = 0;
	/* Successive divisions by 2 and store each last bit in the respective array position. */
	while(num > 0) 
	{
		bits[i] = num % 2;
		num >>= 1; /* Equivalent to num /= 2, but most probably it is executed faster. */
		i++;
	}
	printf("Binary form: ");
	/* Display the number’s bits from left to right. */
	for(j = i-1; j >= 0; j--)
		printf("%d", bits[j]);
	return 0;
}
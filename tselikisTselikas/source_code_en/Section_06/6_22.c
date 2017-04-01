#include <stdio.h>
int main()
{
	int i, num; 

	printf("Enter positive number: ");
	scanf("%d", &num);

	if(num >= 0)
	{
		for(i = 2; i <= num/2; i++)
		{
			if(num % i == 0)
			{
				printf("%d is not prime\n", num);
				return 0; /* When a divisor is found, there is no need to search for other divisors, and the return statement terminates the program immediately. */
			}
		}
		printf("The number %d is prime\n", num);
	}
	else
		printf("Error: enter positive number\n"); 
	return 0;
}
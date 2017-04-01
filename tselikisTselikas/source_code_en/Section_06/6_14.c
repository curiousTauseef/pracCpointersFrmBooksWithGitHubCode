#include <stdio.h>
int main()
{
	int i, num; 
	double fact;

	printf("Enter number within [0, 170]: ");
	scanf("%d", &num);

	if(num >= 0 && num <= 170)
	{
		fact = 1; /* To calculate the factorial of num, we initialize the fact variable to 1. */
		for(i = 1; i <= num; i++)
			fact = fact * i;
		/* If the user enters 0, the for loop won’t be executed because the condition i <= num (1 <= 0) would be false. In such case, the program would display the initial value of the fact variable, which is 1 (and this is correct, since 0! = 1). */
		printf("Factorial of %d is %e\n", num, fact);
	}
	else
		printf("Error: Number should be within [0, 170]\n"); 
	return 0;
}
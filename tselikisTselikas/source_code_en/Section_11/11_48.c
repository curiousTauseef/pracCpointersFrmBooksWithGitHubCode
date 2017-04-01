#include <stdio.h>

double fact(int num);

int main()
{
	int num;

	do
	{
		printf("Enter a positive integer less than 170: ");
		scanf("%d", &num);
	} while(num < 0 || num > 170);

	printf("Factorial of %d is %e\n", num, fact(num));
	return 0;
}

double fact(int num)
{
	double val;

	if((num == 0) || (num == 1))
		val = 1;
	else
		val = num * fact(num - 1);
	return val;
}
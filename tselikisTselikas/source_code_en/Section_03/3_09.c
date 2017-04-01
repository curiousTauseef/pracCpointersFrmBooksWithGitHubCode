#include <stdio.h>
int main()
{
	int num2, res;
	double num1;

	printf("Enter float and int: ");
	scanf("%lf%d", &num1, &num2); 
	res = num1/num2; /* Assume that the user enters the numbers 7.24 and 4. Since res is declared as integer it becomes 1. */
	printf("%f\n", num1 - (res*num2));
	return 0;
}
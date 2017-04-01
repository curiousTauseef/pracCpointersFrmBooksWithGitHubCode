#include <stdio.h>
int main()
{
	int i, j; 

	printf("Enter 2 integers (the second should not be 0):");
	scanf("%d%d", &i, &j); 

	printf("Sum = %d\n", i+j);
	printf("Diff = %d\n", i-j);
	printf("Product = %d\n", i*j);
	printf("Div = %f\n", (float)i/j); /* Typecast of i from int to float to display the decimal part of the division. */ 
	printf("Rem = %d\n", i%j);
	return 0;
}
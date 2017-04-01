#include <stdio.h>
int main()
{
	float i;

	printf("Enter number: ");
	scanf("%f", &i);
	printf("%f is between %d and %d\n", i, (int)i, (int)(i+1));
	return 0;
}
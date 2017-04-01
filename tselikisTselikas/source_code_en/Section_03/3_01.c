#include <stdio.h>
int main()
{
	int i;
	float j, sum;
	
	printf("Enter numbers: ");
	scanf("%d%f", &i, &j);

	sum = i+j;
	printf("%f\n", 3*sum);
	return 0;
}
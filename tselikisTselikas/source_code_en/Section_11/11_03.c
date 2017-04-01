#include <stdio.h>

int square(int a);
int cube(int a);

int main()
{
	int i, j, k;

	printf("Enter number: ");
	scanf("%d", &i);
	
	j = square(i);
	k = cube(i);
	printf("sum = %d\n", j+k); /* Without using the variables j and k, we could write printf("sum = %d\n",square(i) + cube(i)); */
	return 0;
}

int square(int a)
{
	return a*a;
}

int cube(int a)
{
	return a*a*a;
}
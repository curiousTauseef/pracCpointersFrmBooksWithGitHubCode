#include <stdio.h>

void test(int *ptr1, int *ptr2);

int main()
{
	int i = 100, j = 200;
	
	test(&i, &j);
	printf("%d %d\n", i, j);
	return 0;
}

void test(int *ptr1, int *ptr2)
{
	int sum, diff;

	sum = *ptr1 + *ptr2;
	diff = *ptr1 - *ptr2;

	*ptr1 = sum;
	*ptr2 = diff;
}
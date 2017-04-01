#include <stdio.h>
int main()
{
	int *ptr1, *ptr2, i, j, tmp;

	ptr1 = &i;
	ptr2 = &j;

	printf("Enter numbers: ");
	scanf("%d%d", ptr1, ptr2); 

	tmp = *ptr2;
	*ptr2 = *ptr1;
	*ptr1 = tmp;
 
	printf("Values: %d %d\n", i, j);
	return 0;
}
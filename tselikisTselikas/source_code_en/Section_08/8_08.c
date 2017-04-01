#include <stdio.h>
int main()
{
	float *ptr1, *ptr2, i, j;

	/* The pointers should point to the addresses of the variables before calling scanf(). */
	ptr1 = &i;
	ptr2 = &j;
	
	printf("Enter prices: ");
	scanf("%f%f", ptr1, ptr2); 
	if(*ptr1 > *ptr2)
		printf("%f\n", *ptr1);
	else
		printf("%f\n", *ptr2);
	return 0;
}
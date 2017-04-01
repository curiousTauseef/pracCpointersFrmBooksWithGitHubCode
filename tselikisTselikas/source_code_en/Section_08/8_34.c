#include <stdio.h>
int main()
{
	int *ptr, sum, arr[5] = {11, 21, 31, 41, 51};
	
	sum = 0;
	for(ptr = arr; ptr <= arr+4; ptr++)
	{
		--*ptr;
		sum += *ptr;
	}
	printf("Sum = %d\n", sum);
	return 0;
}
#include <stdio.h>
int main()
{
	int i, num, dig;

	num = 0;
	for(i = 0; i < 8; i++)
	{
		printf("Enter digit (0 or 1): ");
		scanf("%d", &dig);

		num += (dig << i);
	}
	printf("The decimal value = %d\n", num);
	return 0;
}
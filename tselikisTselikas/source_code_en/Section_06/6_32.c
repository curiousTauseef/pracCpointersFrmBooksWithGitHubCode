#include <stdio.h>
int main()
{
	int num, sum, dig;

	sum = dig = 0;

	printf("Enter number: ");
	scanf("%d", &num);
	if(num < 0)
		num = -num; /* Make it positive. */
	else if(num == 0)
		dig = 1; /* Check the case of 0. */
	while(num > 0)
	{
		sum += num % 10;
		num = num / 10;
		dig++;
	}
	printf("%d digits and their sum is %d\n", dig, sum);
	return 0;
}
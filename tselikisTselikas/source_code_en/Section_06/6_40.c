#include <stdio.h>
int main()
{
	int i, num;

	printf("Enter number: ");
	scanf("%d", &num);
	i = 1;
	do 
	{
		printf("This\n");
		i++;
	} while(i <= num);

	return 0;
}
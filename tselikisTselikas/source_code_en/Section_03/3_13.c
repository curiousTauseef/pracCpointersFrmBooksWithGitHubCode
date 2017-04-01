#include <stdio.h>
int main()
{
	int i;

	printf("Enter number between 10 and 99: ");
	scanf("%d", &i);
	printf("%d\n", 10*(i%10) + i/10);
	return 0;
}
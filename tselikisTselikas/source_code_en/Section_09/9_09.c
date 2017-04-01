#include <stdio.h>
int main()
{
	int ch, sum;

	printf("Enter characters: ");
	sum = 0;
	ch = getchar();
	while(ch != '\n') 
	{
		sum++; 
		printf("%c", ch);
		ch = getchar();
	}
	printf("\nTotal number is = %d\n", sum);
	return 0;
}
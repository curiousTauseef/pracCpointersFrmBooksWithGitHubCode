#include <stdio.h>
int main()
{
	int i, num, times;

	times = 0;
	while(1)
	{
		printf("Enter number: ");
		scanf("%d", &num);

		if(num < 0)
			break; 

		for(i = 0; i < num; i++)
			printf("Hello\n");

		times += num;
	}
	printf("Total number is = %d\n", times);
	return 0;
}
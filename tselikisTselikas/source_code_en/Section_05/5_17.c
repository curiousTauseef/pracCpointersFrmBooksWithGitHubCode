#include <stdio.h>
int main()
{
	float i, num;

	printf("Enter grade: ");
	scanf("%f", &num);

	i = (num >= 5 && num <= 10) ? num : -1;
	printf("%f\n", i);
	return 0;
}
#include <stdio.h>
int main()
{
	double i, j;

	printf("Enter numbers: ");
	scanf("%lf%lf", &i, &j);
	printf("%d %f\n", (int)i+(int)j, (i-(int)i) + (j-(int)j));
	return 0;
}
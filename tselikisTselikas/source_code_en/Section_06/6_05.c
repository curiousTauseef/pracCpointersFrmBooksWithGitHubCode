#include <stdio.h>
int main()
{
	double i, a, b, step;

	printf("Enter miles interval: ");
	scanf("%lf%lf", &a, &b);

	printf("Enter step: ");
	scanf("%lf", &step);

	printf("MILE\t\t KLM\n");
	printf("------------------------\n");
	for(i = a; i < b; i += step)
		printf("%.2f\t\t %.2f\n", i, 1.6*i);
	return 0;
}
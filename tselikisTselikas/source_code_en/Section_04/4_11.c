#include <stdio.h>
int main()
{
	float tax, a;

	printf("Enter income: ");
	scanf("%f", &a);

	tax = (a > 25000 && a <= 35000)*(a-25000)*0.15 + (a > 35000) * ((a-35000)*0.3 + 10000*0.15);
	printf("Tax = %.2f\n", tax);
	return 0;
}
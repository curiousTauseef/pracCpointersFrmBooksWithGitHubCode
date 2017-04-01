#include <stdio.h>
int main()
{
	int b, exp, tmp;
	double a, val;

	printf("Enter number and power: ");
	scanf("%lf%d", &a, &b);

	val = 1; /* Must be initialized to 1. */
	tmp = 0;
	exp = b;
	if(b < 0) /* If the exponent is negative, make it positive. */
		exp = -exp;
	while(tmp < exp)
	{
		val = val * a;  
		tmp++;
	}
	if(b < 0)
		printf("%f power %d = %f\n", a, b, 1/val);
	else
		printf("%f power %d = %f\n", a, b, val);
	return 0;
}
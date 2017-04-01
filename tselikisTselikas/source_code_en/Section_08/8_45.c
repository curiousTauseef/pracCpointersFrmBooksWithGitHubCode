#include <stdio.h>

float test(float a, float b); 

int main()
{
	float (*ptr)(float a, float b); /* ptr is declared as a pointer to a function, which takes two float parameters and returns a float. */
	float i, j, max;

	printf("Enter grades: ");
	scanf("%f%f", &i, &j);

	ptr = test; 
	max = (*ptr)(i, j); /* Call the function that ptr points to. */
	printf("Max = %f\n", max);
	return 0;
}

float test(float a, float b)
{
	if(a > b)
		return a;
	else
		return b;
}
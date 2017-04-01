#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	int i;
	double var;

	srand((unsigned)time(NULL)); /* The srand() function together with rand() and time() functions generate random positive integers. */
	i = rand() % 101; /* rand() returns a random integer which is constrained in [0,100]. */
	var = i/100.0; /* This division constrains the value within [0,1] with two decimal digits. */
	printf("%.2f\n", var);
	return 0;
}
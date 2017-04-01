#include <stdio.h>
int main()
{
	int i, dig_times[10] = {0}; /* This array holds the appearances of each digit. For example, dig_times[0] indicates how many times the digit 0 appears. */

	printf("Enter number: ");
	scanf("%d", &i);
	if(i < 0) /* If the user enters a negative number make it positive. */
		i = -i;
	else if(i == 0) /* Check if 0 is entered. */
		dig_times[0] = 1;
	while(i > 0)
	{
		dig_times[i%10]++;
		i /= 10;
	}
	for(i = 0; i < 10; i++)
		printf("Digit %d appears %d times\n", i, dig_times[i]);
	return 0;
}
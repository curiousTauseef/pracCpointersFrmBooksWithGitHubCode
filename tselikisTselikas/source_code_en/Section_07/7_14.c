#include <stdio.h>

#define SIZE 31

int main()
{
	int i;
	float max_1, max_2, temp[SIZE];

	printf("Enter temperature: ");
	scanf("%f", &temp[0]);

	max_1 = temp[0];
	for(i = 1; i < SIZE; i++)
	{
		printf("Enter temperature: ");
		scanf("%f", &temp[i]);

		/* Find the maximum value of the array. */
		if(temp[i] > max_1)
			max_1 = temp[i];
	}
	max_2 = max_1;
	/* If the array elements are different, max_2 becomes equal to a value other than max_1. If not, it remains equal to max_1. */
	for(i = 0; i < SIZE; i++)
	{
		if(max_1 != temp[i])
		{
			max_2 = temp[i];
			break;
		}
	}
	/* If max_1 is equal to max_2 implies that all array elements are the same and the loop is not executed. */
	if(max_1 != max_2)
		for(i = 0; i < SIZE; i++) /* Compare the array elements with max_2 and store into max_2 the second maximum value, after checking that it isn’t equal to max_1. */
		{ 
			if((temp[i] > max_2) && (temp[i] != max_1))
				max_2 = temp[i];
		}
	printf("First_Max = %f and Sec_Max = %f\n", max_1, max_2);
	return 0;
}
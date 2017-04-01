#include <stdio.h>

#define SIZE 10

int main()
{
	int i, max_pos, min_pos;
	float max, min, arr[SIZE];

	max = 0;
	min = 10;
	max_pos = min_pos = 0;
	for(i = 0; i < SIZE; i++)
	{
		do
		{
			printf("Enter grade: ");
			scanf("%f", arr+i);
		} while(*(arr+i) > 10 || *(arr+i) < 0); /* Check if the grade is within [0,10]. */
		if(*(arr+i) > max) 
		{
			max = *(arr+i);
			max_pos = i;
		}
		if(*(arr+i) < min) 
		{
			min = *(arr+i);
			min_pos = i;
		}
	}
	printf("Max grade is %.2f in pos #%d\n", max, max_pos);
	printf("Min grade is %.2f in pos #%d\n", min, min_pos);
	return 0;
}
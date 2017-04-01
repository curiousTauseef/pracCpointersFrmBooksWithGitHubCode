#include <stdio.h>
#include <stdlib.h>
int main()
{
	int i, cars;
	float *hours_arr, rem, bill, sum_hours, total_bill;

	do
	{
		printf("Enter number of total cars: ");
		scanf("%d", &cars);
	} while(cars <= 0);

	/* Allocate memory to store the parking hours of all cars. */
	hours_arr = (float *) malloc(cars * sizeof(float));
	if(hours_arr == NULL)
	{
		printf("Error: Not available memory\n");
		exit(1);
	}
	for(i = 0; i < cars; i++)
	{
		do
		{
			printf("Enter hours for car_%d [max=24h]: ", i+1);
			scanf("%f", &hours_arr[i]);
		} while(hours_arr[i] > 24 || hours_arr[i] < 0);
	}
	sum_hours = total_bill = 0;

	printf("\nCar\tHours\tCharge\n");
	for(i = 0; i < cars; i++)
	{
		bill = 6; /* For the first 3 hours. */
		rem = hours_arr[i] - 3; /* Find the extra hours. */
		if(rem > 0)
		{
			/* We check whether rem has a decimal part or not. For example, if rem = 3.2, the statement if(rem – (int)rem) = if(3.2 – 3) = if(0.2 != 0) is true, so rem is increased. In fact, rem should be increased, because the 3.2 hours are charged as if it were 4. */ 
			if(rem - (int)rem != 0) 
				rem++;

			bill += (int)rem * 1.5; /* Use typecasting to remove the decimal part of rem. */
			if(bill > 12)
				bill = 12;
		}
		printf("%d\t%.2f\t%.2f\n", i+1, hours_arr[i], bill);
	
		sum_hours += hours_arr[i];
		total_bill += bill;
	}
	printf("SUM\t%.2f\t%.2f\n", sum_hours, total_bill);
	free(hours_arr);
	return 0;
}
#include <stdio.h>
int main()
{
	int i, studs_num, times;
	float grd, min_grd, max_grd, sum_grd;

	printf("Enter number of students: ");
	scanf("%d", &studs_num);

	if(studs_num <= 0)
	{
		printf("Wrong number of students\n");
		return 0; /* Program termination. */ 
	}
	printf("Enter grade [0-10]: ");
	scanf("%f", &grd); /* We assume that the user enters a number within [0,10]. */

	min_grd = max_grd = grd; 
	sum_grd = grd;
	times = 1; /* First appearance of the maximum grade. */

	for(i = 1; i < studs_num; i++)
	{
		printf("Enter grade [0-10]: ");
		scanf("%f", &grd); 

		if(grd < min_grd)
			min_grd = grd;
		if(grd > max_grd)
		{
			max_grd = grd;
			times = 1; /* First appearance of the new maximum grade. */
		}
		else if(max_grd == grd)
			times++;

		sum_grd += grd;
	}
	printf("Min = %.2f, Max = %.2f (appeared %d times) Avg = %.2f\n", min_grd, max_grd, times, sum_grd/studs_num);
	return 0;
}
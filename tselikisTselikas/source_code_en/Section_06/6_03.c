#include <stdio.h>
int main()
{
	int i;
	float grd;
	for(i = 0; i < 10; i++)
	{
		printf("Enter grade: ");
		scanf("%f", &grd);

		if(grd >= 5 && grd <= 10)
			printf("Grade = %f\n", grd);
	}
	return 0;
}
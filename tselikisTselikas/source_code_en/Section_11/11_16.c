#include <stdio.h>

#define SIZE 50

float avg_arr(float arr[], int min, int max);

int main()
{
	int i; 
	float a, b, ret, arr[SIZE];

	for(i = 0; i < SIZE; i++)
	{
		printf("Enter grade: ");
		scanf("%f", &arr[i]);
	}
	do
	{
		printf("Enter min and max grades: ");
		scanf("%f%f", &a, &b);
	} while(a > b);

	ret = avg_arr(arr, a, b);
	if(ret == -1)
		printf("None grade in [%f, %f]\n", a, b);
	else
		printf("Avg = %.2f\n", ret);
	return 0;
}

float avg_arr(float arr[], int min, int max)
{
	int i, cnt = 0;
	float sum = 0;

	for(i = 0; i < SIZE; i++)
	{
		if(arr[i] >= min && arr[i] <= max)
		{
			cnt++;
			sum += arr[i];
		}
	}
	if(cnt == 0)
		return -1;
	else
		return sum/cnt;
}
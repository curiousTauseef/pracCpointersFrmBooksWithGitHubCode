#include <stdio.h>

int linear_search(double arr[], int size, double num, int *t);

int main()
{
	int i, times, pos;
	double num, arr[100];

	for(i = 0; i < 100; i++)
	{
		printf("Enter number: ");
		scanf("%lf", &num);
		if(num == -1)
			break;
		arr[i] = num;
	}
	printf("Enter number to search: ");
	scanf("%lf", &num);

	pos = linear_search(arr, i, num, &times); /* The variable i indicates the number of the array�s elements. */
	if(pos == -1)
		printf("%f isn�t found\n", num);
	else
		printf("%f appears %d times (first pos = %d)\n", num, times, pos);
	return 0;
}

int linear_search(double arr[], int size, double num, int *t)
{
	int i, pos;

	pos = -1;
	*t = 0;
	for(i = 0; i < size; i++)
	{
		if(arr[i] == num)
		{
			(*t)++;
			if(pos == -1) /* Store the position of the first occurrence. */
				pos = i;
		}
	}
	return pos;
}
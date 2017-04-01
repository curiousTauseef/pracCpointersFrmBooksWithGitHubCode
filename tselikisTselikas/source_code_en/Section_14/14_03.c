#include <stdio.h>
#include <stdlib.h>
int main()
{
	double *arr;
	int i, size;

	printf("Enter size: ");
	scanf("%d", &size);

	arr = (double *) malloc(size * sizeof(double));
	if(arr == NULL)
	{
		printf("Error: Not available memory\n");
		exit(1); 
	}

	for(i = 0; i < size; i++)
	{
		printf("Enter price: ");
		scanf("%lf", &arr[i]);
	}
	for(i = 0; i < size; i++)
		printf("%f\n", arr[i]);

	free(arr);
	return 0;
}
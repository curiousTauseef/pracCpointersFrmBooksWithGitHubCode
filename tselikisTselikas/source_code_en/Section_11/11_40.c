#include <stdio.h>

#define ROWS 2
#define COLS 4

void add_arrays(int arr1[][COLS], int arr2[][COLS], int arr3[][COLS]);

int main()
{
int i, j, arr1[ROWS][COLS], arr2[ROWS][COLS], arr3[ROWS][COLS];

	printf("***** First array *****\n");
	for(i = 0; i < ROWS; i++)
		for(j = 0; j < COLS; j++)
		{
			printf("arr1[%d][%d] = ", i, j);
			scanf("%d", &arr1[i][j]);
		}

	printf("***** Second array *****\n");
	for(i = 0; i < ROWS; i++)
		for(j = 0; j < COLS; j++)
		{
			printf("arr2[%d][%d] = ", i, j);
			scanf("%d", &arr2[i][j]);
		}

	add_arrays(arr1, arr2, arr3); 

	printf("***** Sum array *****\n");
	for(i = 0; i < ROWS; i++)
		for(j = 0; j < COLS; j++)
			printf("sum[%d][%d] = %d\n", i, j, arr3[i][j]);
	return 0;
}

void add_arrays(int arr1[][COLS], int arr2[][COLS], int arr3[][COLS])
{
	int i, j;
	for(i = 0; i < ROWS; i++)
		for(j = 0; j < COLS; j++)
			arr3[i][j] = arr1[i][j] + arr2[i][j];
}
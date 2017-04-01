#include <stdio.h>
#include <stdlib.h>
int main()
{
	FILE *fp;
	double prc;

	fp = fopen("test.txt", "w");
	if(fp == NULL)
	{
		printf("Error: File can’t be created\n");
		exit(1); 
	}
	while(1)
	{
		printf("Enter price: ");
		scanf("%lf", &prc);
		if(prc == -1)
			break;
		if(prc > 10 && prc < 20)
			fprintf(fp, "%.2f\n", prc);
	}
	fclose(fp);
	return 0;
}
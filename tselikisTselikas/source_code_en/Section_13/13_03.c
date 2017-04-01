#include <stdio.h>

#define SIZE 100

struct stock
{
	char name[50]; 
	int code;
	double prc;
};

int main()
{
	int i;
	double prc;
	struct stock s[SIZE]; 

	for(i = 0; i < SIZE; i++)
	{
		printf("\nEnter name: ");
		gets(s[i].name); 

		printf("Enter code: ");
		scanf("%d", &s[i].code);

		printf("Enter price: ");
		scanf("%lf", &s[i].prc);

		getchar();
	}
	printf("\nEnter price to check: ");
	scanf("%lf", &prc);
	
	for(i = 0; i < SIZE; i++)
	{
		if(s[i].prc <= prc)
			printf("\nN: %s C: %d P: %f\n", s[i].name, s[i].code, s[i].prc);
	}
	return 0;
}
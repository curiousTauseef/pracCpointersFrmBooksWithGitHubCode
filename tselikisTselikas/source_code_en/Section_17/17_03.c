#include <stdio.h>
#include <string.h>

#define SIZE 100

struct city
{
	char name[50]; 
	char country[50]; 
	int pop;
};

int main()
{
	char country[50];
	int i, pop, flag;
	struct city cities[SIZE]; 

	for(i = 0; i < SIZE; i++)
	{
		printf("\nCity: ");
		gets(cities[i].name); 

		printf("Country: ");
		gets(cities[i].country); 

		printf("Population: ");
		scanf("%d",  &cities[i].pop);

		getchar();
	}
	printf("\nEnter country to search: ");
	gets(country); 

	printf("Population: ");
	scanf("%d", &pop);

	flag = 0;	
	for(i = 0; i < SIZE; i++)
	{
		if((strcmp(cities[i].country, country) == 0) && (cities[i].pop > pop))
		{
			flag = 1;
			printf("C: %s P: %d\n", cities[i].name, cities[i].pop);
		}
	}
	if(flag == 0)
		printf("\nNone city is found\n");
	return 0;
}
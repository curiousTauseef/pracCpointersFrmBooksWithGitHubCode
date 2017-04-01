#include <stdio.h>

#define SIZE 100

typedef struct
{
	char name[50];
	int code;
	float prc;
} product;

product *find_stud(product pro[], int code); /* Define a function that takes as parameters an array of structures and an integer and returns a pointer to a structure of type product. */
int main()
{
	int i, code;
	product *ptr, pro[SIZE]; 

	for(i = 0; i < SIZE; i++)
	{
		printf("\nName: ");
		gets(pro[i].name);

		printf("Code: ");
		scanf("%d", &pro[i].code);

		printf("Price: ");
		scanf("%f", &pro[i].prc);

		getchar();
	}
	printf("\nEnter code to search: ");
	scanf("%d", &code);

	ptr = find_stud(pro, code);
	if(ptr == NULL)
		printf("\nNo product with code = %d\n", code);
	else
		printf("\nN: %s C: %d P: %.2f\n", ptr->name, code, ptr->prc);
	return 0;
}

product *find_stud(product pro[], int code)
{
	int i;

	for(i = 0; i < SIZE; i++)
	{
		if(pro[i].code == code)
			return &pro[i]; /* If the code is found, the function terminates and returns the address of that structure. */
	}
	return NULL; /* If the code is not found, the function returns NULL. */
}
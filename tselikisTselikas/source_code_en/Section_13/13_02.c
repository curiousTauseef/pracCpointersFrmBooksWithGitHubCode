#include <stdio.h>

#define SIZE 100

struct student
{
	char name[50]; 
	int code;
	float grd;
};

int main()
{
	int i;
	struct student *stud_ptr, stud[SIZE]; 

	stud_ptr = stud; /* Equivalent to stud_ptr = &stud[0]; */
	for(i = 0; i < SIZE; i++)
	{
		printf("\nEnter name: ");
		gets(stud_ptr->name); 

		printf("Enter code: ");
		scanf("%d", &stud_ptr->code);

		printf("Enter grade: ");
		scanf("%f", &stud_ptr->grd);

		printf("\nN: %s C: %d G: %.2f\n", stud_ptr->name, stud_ptr->code, stud_ptr->grd);
		getchar();
		
		stud_ptr++; /* The pointer points to the next element. */ 
	}
	return 0;
}
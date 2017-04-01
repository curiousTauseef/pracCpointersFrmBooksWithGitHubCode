#include <stdio.h>

#define SIZE 100

void sort_by_grade(struct student studs[], int num_studs);
void show_students(struct student studs[], int num_studs, float avg_grd);

struct student
{
	char name[50];
	int code;
	float grd;
};

int main()
{
	int i;
	float sum_grd;
	struct student studs[SIZE];

	sum_grd = 0;
	for(i = 0; i < SIZE; i++)
	{
		printf("\nGrade [0-10]: ");
		scanf("%f", &studs[i].grd);
		if(studs[i].grd == -1)
			break;

		sum_grd += studs[i].grd;
		getchar();

		printf("Name: ");
		gets(studs[i].name);

		printf("Code: ");
		scanf("%d", &studs[i].code);
	}
	sort_by_grade(studs, i); /* Sort the structures in grade ascending order. The variable i specifies the number of students. */
	show_students(studs, i, sum_grd/i); /* The last argument is the average grade of all students. */
	return 0;
}

void sort_by_grade(struct student studs[], int num_studs)
{
	int i, j;
	struct student temp;

	for(i = 0; i < num_studs; i++)
	{
		/* In each iteration, the grd field is compared against the others. If it is less, the structures are swapped. */ 
		for(j = i+1; j < num_studs; j++)
		{
			if(studs[i].grd > studs[j].grd)
			{
				temp = studs[i];
				studs[i] = studs[j];
				studs[j] = temp;
			}
		}
	}
}

void show_students(struct student studs[], int num_studs, float avg_grd)
{
	int i;

	for(i = 0; i < num_studs; i++)
		if(studs[i].grd >= avg_grd)
			printf("N: %s C: %d G: %f\n", studs[i].name, studs[i].code, studs[i].grd);
}
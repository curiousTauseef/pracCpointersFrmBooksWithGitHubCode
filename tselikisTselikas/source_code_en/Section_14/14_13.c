#include <stdio.h>
#include <stdlib.h>

typedef struct student
{
	char name[100];
	int code;
	float grd; 
	struct student *next; /* Pointer to the next node. */
} student;

student *head; /* Global pointer that always points to the head of the stack. */

void add_stack(const student *stud_ptr);
void show_stack();
void pop();
int size_stack();
void free_stack();

int main()
{
	int sel; 
	student stud;

	head = NULL; /* This initial value indicates that the stack is empty. */
	while(1) 
	{
		printf("\nMenu selections\n");
		printf("---------------\n");

		printf("1. Add student\n");
		printf("2. View all students\n");
		printf("3. View top student\n");
		printf("4. Delete top student\n");
		printf("5. Number of students\n");
		printf("6. Exit\n");

		printf("\nEnter choice: ");
		scanf("%d", &sel);

		switch(sel)
		{
			case 1:
				getchar();

				printf("Name: ");
				gets(stud.name);
				printf("Code: ");
				scanf("%d", &stud.code);

				printf("Grade: "); 
				scanf("%f", &stud.grd);

				add_stack(&stud);
			break;

			case 2:
				if(head != NULL)
					show_stack();
				else
					printf("\nThe stack is empty\n");
			break;

			case 3:
				if(head != NULL)
					printf("\nData: %d %s %.2f\n\n",
					head->code,head->name,head->grd);
				else
					printf("\nThe stack is empty\n");
			break;

			case 4:
				if(head != NULL)
					pop();
				else
					printf("\nThe stack is empty\n");
			break;

			case 5:
				if(head != NULL)
					printf("\n%d students exist in stack\n", size_stack());
				else
					printf("\nThe stack is empty\n");
			break;
			case 6:
				if(head != NULL)
					free_stack();
			return 0; 

			default:
				printf("\nWrong choice\n");
			break;
		}
	}
	return 0;
}

void add_stack(const student *stud_ptr)
{
	student *new_node;

	/* Allocate memory to create a new node. */
	new_node = (student *) malloc(sizeof(student));
	if(new_node == NULL)
	{
		printf("Error: Not available memory\n");
		exit(1);
	}
	*new_node = *stud_ptr; 	/* Copy the student’s data into the new node. */
	new_node->next = head; /* The new node is inserted at the beginning of the stack. For example, when the first node is inserted the value of new_node->next becomes NULL, because that is the initial value of the head pointer. */
	head = new_node; /* head points to the new node, therefore that new node becomes the new head of the stack. */ 
}

void show_stack()
{
	student *ptr;

	ptr = head; 
	printf("\n***** Student Data *****\n\n");
	while(ptr != NULL)
	{
		printf("Code: %d\n", ptr->code);
		printf("Name: %s\n", ptr->name);
		printf("Grade: %.2f\n\n", ptr->grd); 
		ptr = ptr->next; /* In each iteration, ptr points to the next node. When its value becomes NULL means that there is no other node in the stack and the loop terminates. */
	}
}
void pop()
{
	student *ptr;

	ptr = head->next; /* ptr points to the node after the head. This node will become the new head of the stack. */
	printf("\nStudent with code =%d is deleted\n",head->code);
	free(head); /* Release the allocated memory. The information for which is the next node is not lost, because we saved it in ptr. */
	head = ptr; /* head points to the new head of the stack. */
}
int size_stack()
{
	student *ptr;
	int num;

	num = 0; 
	ptr = head; 
	while(ptr != NULL)
	{
		ptr = ptr->next;
		num++; /* This variable counts the nodes, until we reach the last one. */
	}
	return num;
}

void free_stack()
{
	student *ptr, *next_node;

	ptr = head; 
	while(ptr != NULL)
	{
		next_node = ptr->next; /* next_node always points to the node after the one to be deleted. */
		free(ptr); /* Release the allocated memory. The information for which is the next node is not lost, because we saved it in next_node. */
		ptr = next_node; /* ptr points to the next node. */
	}
}
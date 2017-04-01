#include <stdio.h>
#include <stdlib.h>

typedef struct student 
{
	char name[100];
	int code;
	float grd; 
	struct student *next; 
} student;

student *head; /* Global pointer that always points to the head of the queue. */
student *tail; /* Global pointer that always points to the tail of the queue. */

void add_queue(const student *stud_ptr);
void show_queue();
void pop();
void free_queue();

int main()
{
	int sel; 
	student stud;

	head = NULL; 
	while(1) 
	{
		printf("\nMenu selections\n");
		printf("---------------\n");
		printf("1. Add student\n");
		printf("2. View all students\n");
		printf("3. View last student\n");
		printf("4. Delete top student\n");
		printf("5. Exit\n");

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

				add_queue(&stud);
			break;

			case 2:
				if(head != NULL)
					show_queue();
				else
					printf("\nThe queue is empty\n");
			break;

			case 3:
				if(head != NULL)
					printf("\nData: %d %s %.2f\n\n",
					tail->code,tail->name,tail->grd);
				else
					printf("\nThe queue is empty\n");
			break;

			case 4:
				if(head != NULL)
					pop();
				else
					printf("\nThe queue is empty\n");
			break;

			case 5:
				if(head != NULL)
					free_queue();
			return 0; 

			default:
				printf("\nWrong choice\n");
			break;
		}
	}
	return 0;
}

void add_queue(const student *stud_ptr)
{
	student *new_node;

	new_node = (student *) malloc(sizeof(student));
	if(new_node == NULL)
	{
		printf("Error: Not available memory\n");
		exit(1);
	}
	*new_node = *stud_ptr;
	new_node->next = NULL; 

	if(head == NULL)  
		head = tail = new_node; /* If the queue is empty, both pointers point to the new node. */
	else
	{
		tail->next = new_node; /* The new node is inserted at the end of the queue. */
		tail = new_node; /* Now, tail points to the last node. */
	}
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

void show_queue()
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

void free_queue()
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

#include <stdio.h>
#include <stdlib.h>

typedef struct student
{
	char name[100];
	int code;
	float grd; 
	struct student *next; 
} student;

student *head; /* Global pointer that always points to the head of the list. */
student *tail; /* Global pointer that always points to the head of the list. */

void add_list_end(const student *stud_ptr);
void add_list(const student *stud_ptr, int code);
void show_list();
student *find_node(int code);
void del_node(int code);
void free_list();

int main()
{
	int sel, code; 
	float grd;
	student stud, *ptr;

	head = NULL; 
	while(1) 
	{
		printf("\nMenu selections\n");
		printf("---------------\n");

		printf("1. Add student at the end\n");
		printf("2. Add student\n");
		printf("3. View all students\n");
		printf("4. View student\n");
		printf("5. Modify student\n");
		printf("6. Delete student\n");
		printf("7. Exit\n");

		printf("\nEnter choice: ");
		scanf("%d", &sel);

		switch(sel)
		{
			case 1: 
			case 2: /* To avoid the repetition of the same code we use the same case. Then, the if statement checks the user’s choice and calls the respective function. */
				getchar();

				printf("Name: ");
				gets(stud.name);
			
				printf("Code: ");
				scanf("%d", &stud.code);

				printf("Grade: "); 
				scanf("%f", &stud.grd);
		
				if(sel == 1)
					add_list_end(&stud);
				else
				{
					printf("\nEnter student code after which the new student will be added: ");  
					scanf("%d", &code);
					add_list(&stud, code);
				}
			break;

			case 3:
				if(head == NULL)
					printf("\nThe list is empty\n");
				else
					show_list();
			break;

			case 4:
				if(head == NULL)
					printf("\nThe list is empty\n");
				else
				{
					printf("\nEnter student code to search: "); 
					scanf("%d", &code); 
					ptr = find_node(code);
					if(ptr == NULL) 
						printf("\nStudent with code = %d does not exist\n", code);
					else
						printf("\nData:%s %.2f\n\n", ptr->name, ptr->grd);

				}
			break;

			case 5:
				if(head == NULL)
					printf("\nThe list is empty\n");
				else
				{
					printf("\nEnter student code to modify: "); 
					scanf("%d", &code); 
					
					printf("Enter new grade: "); 
					scanf("%f", &grd); 
					ptr = find_node(code);
					if(ptr != NULL)
						ptr->grd = grd;
					else
						printf("\nStudent with code = %d does not exist\n", code);
				}
			break;

			case 6:
				if(head == NULL)
					printf("\nThe list is empty\n");
				else
				{
					printf("\nEnter student code to delete: "); 
					scanf("%d", &code); 
					del_node(code); 
				}
			break;

			case 7:
				if(head != NULL)
					free_list();
			return 0; 

			default:
				printf("\nWrong choice\n");
			break;
		}
	} 
	return 0;
}

/* For a better understanding of the add_list_end(), read the comments of the add_queue() in the previous exercise. */
void add_list_end(const student *stud_ptr)
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
		head = tail = new_node; 
	else
	{
		tail->next = new_node; 
		tail = new_node; 
	}
}

void add_list(const student *stud_ptr, int code)
{
	student *new_node, *ptr;

	ptr = head; 
	/* We traverse the list, until the node with the indicated code is found. If it is found, the new node is added after it and the function terminates. */
	while(ptr != NULL)
	{
		if(ptr->code == code)
		{
			new_node = (student *)malloc(sizeof(student));
			if(new_node == NULL)
			{
				printf("Error: Not available memory\n");
				exit(1);
			}
			*new_node = *stud_ptr; /* Copy the student’s data. */  
			new_node->next = ptr->next; /* Now, the new node is linked to the node after the current node. */
			ptr->next = new_node; /* Now, the current node is linked to the new node. */
			if(ptr == tail) /* Check if the new node is added at the end of the list. If it is, it becomes the new tail. */
				tail = new_node;
			return;
		}
		ptr = ptr->next; /* Check the next node. */
	}
	/* If the execution reaches this point, means that the input code doesn’t correspond to an existing student. */
	printf("\nStudent with code = %d does not exist\n", code);
}

void show_list()
{
	student *ptr;

	ptr = head; 
	printf("\n***** Student Data *****\n\n");
	while(ptr != NULL)
	{
		printf("Code: %d\n", ptr->code);
		printf("Name: %s\n", ptr->name);
		printf("Grade: %.2f\n\n", ptr->grd); 
		ptr = ptr->next; 
	}
}

student *find_node(int code)
{
	student *ptr;

	ptr = head; 
	while(ptr != NULL)
	{
		if(ptr->code == code)
			return ptr;
		ptr = ptr->next; 
	}
	return NULL;
}

void del_node(int code)
{
	student *ptr, *prev_node; /* prev_node always points to the previous node from the one that is going to be deleted. */

	ptr = prev_node = head;
	while(ptr != NULL)
	{
		if(ptr->code == code)
		{
			if(ptr == head) 
				head = ptr->next; /* If the node is the head of the list, the next node becomes the new head. If there is no other node, the list becomes empty and the value of head becomes NULL. */
			else
			{
				/* Now, ptr points to the node that will be deleted and prev_node points to the previous one. This statement links the previous node with the node after the one that will be deleted. */
				prev_node->next = ptr->next;
				if(ptr == tail) /* Check if the deleted node is the tail of the list. If it is, the previous node becomes the new tail. */
					tail = prev_node;
			}
			free(ptr); /* Delete the node. */
			printf("\nStudent with code = %d is deleted\n", code);
			return;
		}
		prev_node = ptr; /* Now, prev_node points to the node that was just checked and found that it doesn’t correspond to the node having the input code. */
		ptr = ptr->next; /* Now, ptr points to the next node. Note that prev_node points always to the previous node from the one that is going to be checked. */
	}
	printf("\nStudent with code = %d does not exist\n", code);
}

void free_list()
{
	student *ptr, *next_node;

	ptr = head; 
	while(ptr != NULL)
	{
		next_node = ptr->next; 
		free(ptr);
		ptr = next_node; 
	}
}
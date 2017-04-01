#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct publisher
{
	char *name;
	char *addr; 
	char *phone; 
} pub;

typedef struct book
{
	char *title;
	char *auth;
	char *code;
	pub  *pub_ptr; 
	float prc; 
} book;

/* For the sake of brevity, we assume that all malloc() calls are successful. */
int main()
{
	book *books_ptr;
	char str[100];
	int i, num;

	printf("Enter number of books: ");
	scanf("%d", &num);
	getchar();

	books_ptr = (book *) malloc(num * sizeof(book)); 
	for(i = 0; i < num; i++)
	{
		printf("\nTitle: ");
		gets(str);
		books_ptr[i].title = (char *)malloc(strlen(str)+1);
		strcpy(books_ptr[i].title, str);

		printf("Authors: ");
		gets(str);
		books_ptr[i].auth = (char *) malloc(strlen(str)+1);
		strcpy(books_ptr[i].auth, str);

		printf("Code: ");
		gets(str);
		books_ptr[i].code = (char *) malloc(strlen(str)+1);
		strcpy(books_ptr[i].code, str);

		printf("Price: ");
		scanf("%f", &books_ptr[i].prc);

		getchar();
		/* Allocate memory to store the data of the publishing firm. */
		books_ptr[i].pub_ptr = (pub *) malloc(sizeof(pub));

		printf("Name: ");
		gets(str);
(books_ptr[i].pub_ptr)->name = (char *) malloc(strlen(str)+1);
		strcpy((books_ptr[i].pub_ptr)->name, str);

		printf("Address: ");
		gets(str);
		(books_ptr[i].pub_ptr)->addr = (char *) malloc(strlen(str)+1);
		strcpy((books_ptr[i].pub_ptr)->addr, str);

		printf("Phone: ");
		gets(str);
		(books_ptr[i].pub_ptr)->phone = (char *) malloc(strlen(str)+1);
		strcpy((books_ptr[i].pub_ptr)->phone, str);
	}
	printf("\nEnter code to search: ");
	gets(str);

	for(i = 0; i < num; i++)
	{
		if(strcmp(books_ptr[i].code, str) == 0)
		{
			printf("\nTitle: %s\tPublisher: %s\n\n", books_ptr[i].title, (books_ptr[i].pub_ptr)->name);
			break;
		}
	}
	if(i == num)
		printf("\nCode '%s' isn't registered\n", str);

	for(i = 0; i < num; i++)
	{
		free((books_ptr[i].pub_ptr)->name);
		free((books_ptr[i].pub_ptr)->addr);
		free((books_ptr[i].pub_ptr)->phone);

		free(books_ptr[i].title);
		free(books_ptr[i].auth);
		free(books_ptr[i].code);
		free(books_ptr[i].pub_ptr);
	}
	free(books_ptr);
	return 0;
}
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LEN 30

typedef struct 
{
	char title[LEN];
	char auth[LEN];
	int code;
} book;

void read_data(book *ptr);
void find_book(FILE *fp, char title[]);
void modify_book(FILE *fp, book *ptr, int flag);
void show_books(FILE *fp);

int main()
{
	FILE *fp;
	char title[LEN];
	int sel;
	book b;

	fp = fopen("test.bin", "r+b"); 
	if(fp == NULL)
	{
		/* If the file doesn’t exist, it is created. */
		fp = fopen("test.bin", "w+b"); 
		if(fp == NULL)
		{
			printf("Error: File can't be created\n");
			exit(1);
		}
	}
	while(1) 
	{
		printf("\n\nMenu selections\n");
		printf("---------------\n");

		printf("1. Add Book\n");
		printf("2. Find Book\n");
		printf("3. Modify Book \n");
		printf("4. Erase Book\n");
		printf("5. Exit\n");

		printf("\nEnter choice: ");
		scanf("%d", &sel);
		getchar();

		switch(sel)
		{
			case 1:
				read_data(&b);
				fseek(fp, 0, SEEK_END); /* Add the details of the new book at the end of the file. */
				fwrite(&b, sizeof(book), 1, fp);
			break;

			case 2:
				printf("\nTitle to search: ");
				gets(title);
				if(strcmp(title, "*") != 0)
					find_book(fp, title);
				else
					show_books(fp);
			break;

			case 3:
				read_data(&b);
				modify_book(fp, &b, 0);
			break;

			case 4:
				printf("\nTitle to search: ");
				gets(b.title);
				modify_book(fp, &b, 1);
			break;

			case 5:
				fclose(fp);
			return 0; 

			default:
				printf("\nWrong choice\n");
			break;
		}
	}
	return 0;
}

void read_data(book *ptr)
{
	printf("\nTitle: ");
	gets(ptr->title);

	printf("Authors: ");
	gets(ptr->auth);

	do
	{
		printf("Code [> 0]: ");
		scanf("%d", &ptr->code);
	}
	while(ptr->code <= 0);
}

void find_book(FILE *fp, char title[])
{
	book b;

	fseek(fp, 0, SEEK_SET);
	while(1)
	{
		if(fread(&b, sizeof(book), 1, fp) != 1)
			break;
		else
		{
			if(strcmp(b.title, title) == 0)
			{
				printf("\nT:%s A:%s C:%d", b.title, b.auth, b.code);
				return;
			}
		}
	}
	printf("\n%s doesn’t exist", title);
}

void modify_book(FILE *fp, book *ptr, int flag)
{
	book b;

	fseek(fp, 0, SEEK_SET);
	while(1)
	{
		if(fread(&b, sizeof(book), 1, fp) != 1)
			break;
		else
		{
			if(strcmp(b.title, ptr->title) == 0)
			{
				/* Now, fp points to the next entry. We call fseek() to make it point at the current entry. */
				fseek(fp, -sizeof(book), SEEK_CUR);
				if(flag == 0)
					fwrite(ptr, sizeof(book), 1, fp);
				else
				{
					b.code = -1; /* Set the code to -1. */
					fwrite(&b, sizeof(book), 1, fp);
				}
				return;
			}
		}
	}
	printf("\n%s doesn’t exist", ptr->title);
}

void show_books(FILE *fp)
{
	book b;

	fseek(fp, 0, SEEK_SET);
	while(1)
	{
		if(fread(&b, sizeof(book), 1, fp) != 1)
			return;
		else
		{
			if(b.code != -1)
				printf("T:%s A:%s C:%d\n", b.title, b.auth, b.code);
		}
	}
}
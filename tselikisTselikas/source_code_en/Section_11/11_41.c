#include <stdio.h>
#include <string.h>

#define NUM  20 
#define SIZE 100 

char *find_name(char name[][SIZE], char str[]);

int main()
{
	char *ptr, str[SIZE], name[NUM][SIZE]; /* Declare an array of NUM rows and SIZE columns. The names of the students are stored in the array’s rows. */ 
	int i;

	for(i = 0; i < NUM; i++)
	{
		printf("Enter name: ");
		gets(name[i]); /* We use the name[i] as a pointer to the respective i row of SIZE characters. */
	}
	printf("Enter name to search: ");
	gets(str);

	ptr = find_name(name, str);
	if(ptr == NULL)
		printf("%s is not contained\n", str);
	else
		printf("%s is contained\n", ptr);
	return 0;
}

char *find_name(char name[][SIZE], char str[])
{
	int i;
	for(i = 0; i < NUM; i++)
		if(strcmp(name[i], str) == 0)
			return name[i]; 
	return NULL; /* If this point is reached, the name isn’t found in the array. */
}
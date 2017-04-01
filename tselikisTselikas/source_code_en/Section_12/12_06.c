#include <stdio.h>
#include <string.h>

#define NUM 10 

int main()
{
	char temp[100], name[NUM][100]; /* Array of NUM rows (each row contains up to 100 characters). For example, the first name is stored at name[0] and its first character at name[0][0]. Each name[i] can be used as a pointer to the corresponding row. */
	int i, j;

	for(i = 0; i < NUM; i++)
	{
		printf("Enter name: ");
		gets(name[i]);
	}
	for(i = 0; i < NUM; i++)
	{
		for(j = i+1; j < NUM; j++)
		{
			if(strcmp(name[i], name[j]) > 0) /* Swap the names. */
			{
				strcpy(temp, name[j]);
				strcpy(name[j], name[i]);
				strcpy(name[i], temp);
			}
		}
	}
	printf("\n***** Names in increase order *****\n");
	for(i = 0; i < NUM; i++)
		printf("%s\n", name[i]);
	return 0;
}
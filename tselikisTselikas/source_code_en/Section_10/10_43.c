#include <stdio.h>
#include <string.h>

#define NUM 10

int main()
{
	char *ptr[NUM], *temp, str[NUM][40];
	int i, j;

	for(i = 0; i < NUM; i++)
	{
		printf("Enter name: ");
		gets(str[i]);
		ptr[i] = str[i]; /* The elements of the array point to the input strings. */
	}
	for(i = 0; i < NUM; i++)
	{
		for(j = i+1; j < NUM; j++)
		{
/* If the string pointed to by ptr[j] is less than the string pointed to by ptr[i], swap the respective pointers. */
			if(strcmp(ptr[j], ptr[i]) < 0)
			{
				temp = ptr[j];
				ptr[j] = ptr[i];
				ptr[i] = temp;
			}	 
		}
	}
	for(i = 0; i < NUM; i++)
		printf("%s\n", ptr[i]);
	return 0;
}
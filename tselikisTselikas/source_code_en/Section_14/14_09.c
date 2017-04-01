#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 5

int main()
{
	char *ptr[SIZE];
	int i, pos, len, max_len; /* The variable pos indicates the ptr element, which points to the larger string. The variable max_len holds its length. */

	pos = max_len = 0; 
	/* Each pointer points to a dynamically allocated memory of 100 bytes. */ 
	for(i = 0; i < SIZE; i++)
	{
		ptr[i] = (char *) malloc(100);
		if(ptr[i] == NULL)
		{
			printf("Error: Not available memory\n");
			exit(1);
		}
		printf("Enter text: ");
		gets(ptr[i]);
		/* We compare the length of each string against max_len and if a larger string is found, we store its position and length. */
		len = strlen(ptr[i]);
		if(len > max_len)
		{
			pos = i;
			max_len = len;
		}
	}
	printf("Larger string: %s\n", ptr[pos]);
	for(i = 0; i < SIZE; i++)
		free(ptr[i]);
	return 0;
}
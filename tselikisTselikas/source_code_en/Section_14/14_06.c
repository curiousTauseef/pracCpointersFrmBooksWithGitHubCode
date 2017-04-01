#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *str_cpy(char *trg, const char *src);

int main()
{
	char *trg, src[100];

	printf("Enter text: ");
	gets(src);
	/* Allocate memory to store the input string and the null character. */
	trg = (char *) malloc(strlen(src)+1);
	if(trg == NULL)
	{
		printf("Error: Not available memory\n");
		exit(1);
	}
	printf("Copied text: %s\n", str_cpy(trg, src));
	free(trg);
	return 0;
}

char *str_cpy(char *trg, const char *src)
{
	int i = 0;
	while(*(src+i) != '\0') /* Equivalent to while(src[i] != '\0')*/
	{
		*(trg+i) = *(src+i); /* Equivalent to trg[i] = src[i]; */
		i++;
	}
	*(trg+i) = '\0'; /* Add the null character. */
	return trg;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
	char *tot_str;
	int i, tot_chars;

	if(argc == 1) /* Check if there is only one argument. */
	{
		printf("Missing arguments ...\n");
		exit(1);
	}
	tot_chars = 0; /* It counts the characters of all arguments. */
	for(i = 1; i < argc; i++) /* Remember that argv[1] points to the first argument, argv[2] to the second one, and so forth. argv[0] points to the name of the program. */
		tot_chars += strlen(argv[i]);

	tot_str = (char *) malloc(tot_chars+1); /* Allocate an extra place for the null character. */
	if(tot_str == NULL)
	{
		printf("Error: Not available memory\n");
		exit(1);
	}
	*tot_str = '\0'; /* Initialize the allocated memory with the null character. */
	for(i = 1; i < argc; i++)
		strcat(tot_str, argv[i]);

	printf("The merged string is: %s\n", tot_str);
	free(tot_str);
	return 0;
}
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void str_cat(char *fin, char *str1, char *str2);

int main()
{
	char *fin, str1[100], str2[100];

	printf("Enter first text: ");
	gets(str1);

	printf("Enter second text: ");
	gets(str2);
	/* Allocate memory to store both strings and the null character. */
	fin = (char *) malloc(strlen(str1)+strlen(str2)+1);
	if(fin == NULL)
	{
		printf("Error: Not available memory\n");
		exit(1);
	}
	str_cat(fin, str1, str2);
	printf("Merged text: %s\n", fin);
	free(fin);
	return 0;
}

void str_cat(char *fin, char *str1, char *str2)
{
	while(*str1 != '\0') /* Equivalent to while(*str1) */
		*fin++ = *str1++;

	/* Copy the second string right after the first one. */
	while(*str2 != '\0') /* Equivalent to while(*str2) */
		*fin++ = *str2++;

	*fin = '\0'; /* Add the null character. */
}
#include <stdio.h>
#include <string.h>

int str_end(char str1[], char str2[]);

int main()
{
	char str1[100], str2[100];
	int ret;

	printf("Enter first text: ");
	gets(str1);

	printf("Enter second text: ");
	gets(str2);

	ret = str_end(str1, str2);
	if(ret == 0)
		printf("%s is not at the end of %s\n", str2, str1);
	else
		printf("%s is at the end of %s\n", str2, str1);
	return 0;
}

int str_end(char str1[], char str2[])
{
	int i, len1, len2;

	len1 = strlen(str1);
	len2 = strlen(str2);

	if(len1 < len2) /* If the length of the second string is bigger, the function returns. */
		return 0;

	for(i = 1; i <= len2; i++)
		if(str1[len1-i] != str2[len2-i]) /* If two characters are not the same, it’s not needed to compare the rest and the function returns. */ 
			return 0;

	/* If this point is reached, it means that all compared characters were the same, and the function returns 1. */ 
	return 1;
}
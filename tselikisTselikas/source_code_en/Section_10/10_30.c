#include <stdio.h>
#include <string.h>
int main()
{
	char str1[100], str2[100];
	int ret;

	printf("Enter first text: ");
	gets(str1);

	printf("Enter second text: ");
	gets(str2);

	ret = strcmp(str1, str2);
	/* Without using the variable ret we could write if(strcmp(str1,str2) == 0) */
	if(ret == 0)
		printf("Same texts\n");
	else
	{
		printf("Different texts\n");
		if(strncmp(str1, str2, 3) == 0)
			printf("But the first 3 chars are the same\n");
	}
	return 0;
}
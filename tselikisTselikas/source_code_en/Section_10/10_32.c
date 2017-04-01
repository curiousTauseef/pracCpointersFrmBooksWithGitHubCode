#include <stdio.h>
#include <string.h>
int main()
{
	char str[100], min_str[100], max_str[100];

	printf("Enter text: ");
	gets(str);

	/* Use the first string as a base to compare the rest. */
	strcpy(min_str, str);
	strcpy(max_str, str);
	if(strncmp(str, "end", 3) == 0) 
	{
		printf("\nMax = %s Min = %s\n", max_str, min_str); 
		return 0;
	}
	while(1)
	{
		printf("Enter text: ");
		gets(str);

		if(strncmp(str, "end", 3) == 0)
			break;

		if(strcmp(str, min_str) < 0)
			strcpy(min_str, str);

		if(strcmp(str, max_str) > 0)
			strcpy(max_str, str);
	}
	printf("\nMax = %s Min = %s\n", max_str, min_str);
	return 0;
}
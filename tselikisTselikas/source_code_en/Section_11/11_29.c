#include <stdio.h>

char *str_chr(char str[], char ch, int f); 
int main()
{
	char *ptr, ch, str[100];
	int flag;

	printf("Enter text: ");
	gets(str);

	printf("Enter character to search: ");
	scanf("%c", &ch);
	printf("Enter choice (0-first, other-last): ");
	scanf("%d", &flag);

	ptr = str_chr(str, ch, flag);
	if(ptr == NULL)
		printf("'%c' is not included in the text\n", ch);
	else
		printf("The rest string is: %s\n", ptr);
	return 0;
}

char *str_chr(char str[], char ch, int f)
{
	char *tmp = NULL; /* If the character is not found, the function returns NULL. */
	while(*str != '\0') 
	{
		if(*str == ch) 
		{
			tmp = str;
			if(f == 0) /* If the character is found and the choice is 0, the loop terminates and the function returns the pointer. If it isn’t 0, tmp points to the place of its last appearance. */
				break;
		}
		str++;  
	}
	return tmp; 
}
#include <stdio.h>
int main()
{
	char ch;
	
	printf("Enter character: ");
	scanf("%c", &ch);

	if(ch == ' ')
		printf("The character is a space\n");
	else if(ch == '\n')
		printf("The character is a new line\n");
	else if(ch >= '0' && ch <= '9')
		printf("The character is a number\n");
	else if(ch >= 'a' && ch <= 'z')
		printf("The character is a lower case letter\n");
	else if(ch >= 'A' && ch <= 'Z')
		printf("The character is an upper case letter\n");
	return 0;
}
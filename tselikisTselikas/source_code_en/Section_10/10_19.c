#include <stdio.h>
#include <string.h>
int main()
{
	char ch, str[100];
	int i, len;

	do
	{
		printf("Enter text (more than 2 chars): ");
		gets(str);
		len = strlen(str);
	} while(len < 3);

	printf("Enter character: ");
	ch = getchar();

	for(i = 0; i <= len-3; i++)
		if(str[i] == ch && str[i+1] == ch && str[i+2] == ch)
		{
			printf("There are three successive '%c's in position %d\n", ch, i+1);
			return 0;
		}
	printf("There aren’t three successive '%c's\n", ch);
	return 0;
}
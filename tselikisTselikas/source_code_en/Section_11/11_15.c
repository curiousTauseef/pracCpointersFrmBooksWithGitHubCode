#include <stdio.h>
#include <string.h>

int str_chr(char str[], char ch);
int main()
{
	char ch, str[100];

	while(1)
	{
		printf("Enter text: ");
		gets(str);
		if(strcmp(str, "end") == 0) 
			break;

		printf("Enter character to search: ");
		scanf("%c", &ch);

		printf("'%c' is contained %d times in '%s'\n\n", ch, str_chr(str, ch), str);
		getchar(); 
	}
	return 0;
}

int str_chr(char str[], char ch)
{
	int i, times;
	
	i = times = 0;
	while(str[i] != '\0')
	{
		if(str[i] == ch) 
			times++;
		i++;
	}
	return times; 
}
#include <stdio.h>
#include <string.h>
int main()
{
	char str[100];
	int i, len;

	printf("Enter text: ");
	gets(str);

	len = strlen(str);
	for(i = 0; i < len; i++)
	{
		if(str[i] == 'a')
			str[i] = ' ';
		else 
			break;
	}
	for(i = len-1; i >= 0; i--)
	{
		if(str[i] == 'a')
			str[i] = ' ';
		else 
			break;
	}
	printf("Text: %s\n", str);
	return 0;
}
#include <stdio.h>
#include <string.h>
int main()
{
	char str[100];
	int i, len;

	printf("Enter text: ");
	gets(str);

	len = strlen(str);
	if(len > 1 && str[len-1] == 'a' && str[len-2] == 'a')
	{
		printf("Reversed text: ");
		for(i = len-1; i >= 0; i--) 
			printf("%c", str[i]);
	}
	return 0;
}
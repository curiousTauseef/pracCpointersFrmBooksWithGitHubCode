#include <stdio.h>
#include <string.h>
int main()
{

	char str[100];
	int i, diff, len;

	while(1)
	{
		printf("Enter text: ");
		gets(str);
	
		if(strcmp(str, "exit") == 0)
			break;

		len = strlen(str);
		diff = 0;
		for(i = 0; i < len/2; i++)
		{
			if(str[i] != str[len-1-i]) /* /* If two characters are not the same, then the loop terminates. */
			{
				diff = 1;
				break;
			}
		}
		if(diff == 1)
			printf("%s is not a palindrome\n", str);
		else
			printf("%s is a palindrome\n", str);
	}
	return 0;
}
#include <stdio.h>
#include <string.h>
int main()
{
	char str[100];
	int i, ch;

	printf("Enter text (> 5 && < 100): ");
	while(1)
	{
		i = 0;
		while((ch = getchar()) != '\n' && ch != EOF)
		{
			if(i < 99)
			{
				str[i] = ch;
				i++;
			}
		}
		str[i] = '\0';
		if(strlen(str) > 5)
			break;
		else
			printf("Enter text (> 5 && < 100): ");
	} 
	printf("%s\n", str);
	return 0;
}
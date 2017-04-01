#include <stdio.h>
#include <string.h>

#define NUM 10

int main()
{
	char str[NUM][40];
	int i, len;

	for(i = 0; i < NUM; i++)
	{
		printf("Enter name: ");
		gets(str[i]);

		len = strlen(str[i]); 
		if(len && str[i][0] == 'a' && str[i][len-1] == 's')
			printf("%s\n", str[i]);
	}
	return 0;
}
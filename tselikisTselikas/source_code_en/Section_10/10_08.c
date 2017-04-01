#include <stdio.h>
int main()
{
	char str[100];
	int i, cnt;

	printf("Enter text: ");
	gets(str);

	cnt = 0;
	for(i = 0; str[i] != '\0'; i++)
	{
		if(str[i] == ' ')
			str[i] = '\n';
		else if(str[i] == 'a')
			str[i] = 'p';
		else if(str[i] == 'b')
			cnt++;
	}
	printf("Len = %d Times = %d\nText = %s\n", i, cnt, str); 
	return 0;
}
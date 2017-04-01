#include <stdio.h>
int main()
{
	char *ptr, str[100];
	int cnt;

	printf("Enter text: ");
	gets(str);

	cnt = 0;
	ptr = str;
	while(*ptr != '\0')
	{
		if(*ptr == ' ')
			*ptr = '\n';
		else if(*ptr == 'a')
			*ptr = 'p';
		else if(*ptr == 'b')
			cnt++;
		ptr++;
	}
	printf("Len = %d Times = %d\nText = %s\n", ptr-str, cnt, str); 
	return 0;
}
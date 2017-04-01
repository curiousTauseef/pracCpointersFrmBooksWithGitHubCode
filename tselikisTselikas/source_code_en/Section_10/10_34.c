#include <stdio.h>
#include <string.h>
int main()
{
	char temp, str[100];
	int i, len;

	printf("Enter text: ");
	gets(str);

	len = strlen(str);
	for(i = 0; i < len/2; i++)
	{
		temp = str[i];
		str[i] = str[len-i-1];
		str[len-i-1] = temp;
	}
	printf("Reversed text: %s\n", str);
	return 0;
}
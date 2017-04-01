#include <stdio.h>

unsigned int str_len(const char *str);

int main()
{
	char arr[100];

	printf("Enter text: ");
	gets(arr);
	printf("Length = %d\n", str_len(arr)); 
	return 0;
}

unsigned int str_len(const char *str)
{
	unsigned int i = 0;
	while(str[i] != '\0') /* Count the characters up to the null character. */
		i++;
	return i;
}
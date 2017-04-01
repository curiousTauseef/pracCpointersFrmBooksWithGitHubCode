#include <stdio.h>
#include <string.h>
int main()
{
	char str[100];
	int i, pos, max_times, occurs[256] = {0}; /* To declare the size of the array we assume that the ASCII set is used. */

	printf("Enter text: ");
	gets(str);

	for(i = 0; str[i] != '\0'; i++)
		occurs[str[i]]++; /* This array contains the number of appearances of each character. For example, occurs[97] holds the number of appearances of character 'a' within the string. */
	max_times = occurs[0];
	pos = 0;
	for(i = 1; i < 256; i++)
	{
		if(occurs[i] > max_times)
		{
			max_times = occurs[i];
			pos = i;
		}
	}
	printf("'%c' appears %d times\n", pos, max_times);
	return 0;
}
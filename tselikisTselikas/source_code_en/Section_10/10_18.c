#include <stdio.h>
#include <string.h>
int main()
{
	char str1[100], str2[200]; /* The new string will be stored into str2. Its size is declared as the double of the size of the str1 array, just for the case that the input string contains only 'a's. */
	int i, j;

	printf("Enter text: ");
	gets(str1);

	j = 0;
	for(i = 0; i < strlen(str1); i++)
	{
		str2[j] = str1[i]; /* Copy each character of the input string in the position indicated by j. */
		if(str1[i] == 'a') 
		{
			j++; /* Increase j to store another 'a'. */
			str2[j] = 'a';
		}
		j++; /* Increase j to store the next character. */
	}
	str2[j] = '\0'; /* Add the null character. */
	printf("Text: %s\n", str2);
	return 0;
}
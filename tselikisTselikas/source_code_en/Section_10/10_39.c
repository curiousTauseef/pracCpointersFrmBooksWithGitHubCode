#include <stdio.h>
int main()
{
	char str[100];
	int i, words;

	i = words = 0;
	printf("Enter text: ");
	gets(str);
	if(str[0] != ' ' && str[0] != '\0') /* If the first character is other than the space character means that a word begins, so the value of words is increased by one. */
		words++;

	while(str[i] != '\0')
	{
		if(str[i] == ' ')
		{
			/* Since more than one space characters may be included between words, we check if the next character, that is str[i+1], is the space character. If it isn’t, it means that a new word begins, so the value of words is increased by one. */
			if(str[i+1] != ' ' && str[i+1] != '\0')
			{
				words++;
				printf("\n");
			}
		}
		else
			printf("%c", str[i]);
		i++;
	}
	printf("\nThe text contains %d words\n", words);
	return 0;
}
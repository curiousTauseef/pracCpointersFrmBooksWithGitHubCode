#include <stdio.h>
#include <string.h>

#define LETTERS 26

int main()
{
	char str[100], key[LETTERS];
	int i, j, len, found;

	printf("Enter original text: ");
	gets(str);

	do
	{
		printf("Enter key (%d different characters): ", LETTERS);
		gets(key);

		found = 0;
		for(i = 0; i < LETTERS; i++)
		{
			for(j=i+1; j < LETTERS; j++)
			{
				if(key[i] == key[j])
				{
					found = 1;
					printf("Key characters should be different\n");
					break;
				}
			}
			if(found == 1)
				break;
		}
	}
	while(found != 0);

	len = strlen(str);
	for(i = 0; i < len; i++)
	{
		if(str[i] >= 'a' && str[i] <= 'z')
			str[i] = key[str[i]-'a'];
	}
	printf("Encrypted text: %s\n", str);
	for(i = 0; i < len; i++)
	{
		for(j = 0; j < LETTERS; j++)
		{
			if(str[i] == key[j])
			{
				str[i] = 'a'+j;
				break;
			}
		}
	}
	printf("Original text: %s\n", str);
	return 0;
}
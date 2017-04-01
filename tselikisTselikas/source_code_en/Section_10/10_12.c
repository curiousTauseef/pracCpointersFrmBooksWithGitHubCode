#include <stdio.h>
int main()
{
	char str[100];
	int i, small_let, big_let;

	while(1) 
	{
		printf("Enter text: ");
		gets(str);

		if(str[0] == 'e' && str[1] == 'n' && str[2] == 'd')
			break;

		i = small_let = big_let = 0;
		while(str[i] != '\0') 
		{
			if(str[i] >= 'a' && str[i] <= 'z')
			{
				str[i] -= 32; /* In ASCII code, the difference between an upper case letter and the respective lower case letter is 32. */
				big_let++;
			}
			else if(str[i] >= 'A' && str[i] <= 'Z')
			{
				str[i] += 32;
				small_let++;
			}
			i++;
		}
		printf("%s contains %d lower case and %d upper case letters\n", str, small_let, big_let);
	}
	return 0;
}
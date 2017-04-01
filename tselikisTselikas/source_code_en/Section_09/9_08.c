#include <stdio.h>
int main()
{
	char ch, end_ch;

	end_ch = 'z';
	for(ch = 'a'; ch <= end_ch; ch++)
	{
		printf("%c ", ch);
		if(ch == 'z')
		{
			ch = 'A'-1; /* Subtract 1, so that the ch++ statement in the next loop iteration will make it equal to 'A'. */
			end_ch = 'Z'; /* Change the end character, so that the loop displays all upper case letters. */
			printf("\n");
		}
		else if(ch == 'Z')
		{
			ch = '0'-1; 
			end_ch = '9'; 
			printf("\n");
		}
	}
	return 0;
}
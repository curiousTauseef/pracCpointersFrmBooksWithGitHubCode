#include <stdio.h>
int main()
{
	int ch, sign, val;

	val = 0; /* The value of val is 0 until the user enters the first digit. Then, if the user enters a non-digit character the program terminates. */
	printf("Enter number: ");
	while((ch = getchar()) != '\n' && ch != EOF)
	{
		if(ch == ' ' || ch == '\t')
		{
			if(val != 0)
			{
				printf("Error: Not spaces between digits\n");
				return 0;
			}
		}
		else if(ch == '+' || ch == '-')
		{
			if(val != 0)
			{
				printf("Error: Not signs between digits\n");
				return 0;
			}
			else 
				sign = ch;
		}
		else if(ch >= '0' && ch <= '9')
			val = 10*val + (ch-'0'); /* The expression ch-'0' calculates the numerical value of the digit character. */
		else
		{
			printf("Error: Input isn't a digit\n");
			return 0;
		}
	}
	if(sign == '-')
		val = -val;
	printf("%d\n", val);
	return 0;
}
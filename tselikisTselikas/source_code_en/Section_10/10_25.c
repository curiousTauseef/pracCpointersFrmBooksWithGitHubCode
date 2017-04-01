#include <stdio.h>
#include <string.h>
int main()
{
	char upc[13];
	int i, flag, chk_dig, sum;

	while(1)
	{
		printf("Enter UPC (12 digits): ");
		gets(upc);

		if(strlen(upc) != 12)
		{
			printf("Error: wrong length\n");
			continue;
		}
		flag = 1;
		for(i = 0; i < 12; i++)
		{
			if(upc[i] < '0' || upc[i] > '9')
			{
				printf("Error: only digits allowed\n");
				flag = 0;
				break;
			}
		}
		if(flag == 1)
			break;
	}
	sum = 0;
	for(i = 0; i < 11; i+=2)
		sum += upc[i] - '0'; /* Subtract '0' to get the numerical value of the digit character. */
	sum *= 3;
	for(i = 1; i < 11; i+=2)
		sum += upc[i] - '0';

	chk_dig = 10-(sum%10);
	if(chk_dig == 10)
		chk_dig = 0;
	
	if(chk_dig == (upc[11] - '0'))
		printf("Valid check digit\n");
	else
		printf("Wrong check digit. The correct is %d.\n", chk_dig);

	return 0;
}
#include <stdio.h>

#define SIZE 50

int main()
{
	int i, j, num, found, code[SIZE];

	i = 0;
	while(i < SIZE)
	{
		printf("Enter code: ");
		scanf("%d", &num);

		found = 0;
		/* The variable i indicates how many codes have been stored in the array. The for loop checks if the input code is already stored. If it does, the variable found becomes 1 and the loop terminates. */
		for(j = 0; j < i; j++)
		{
			if(code[j] == num)
			{
				printf("Error: Code %d exists. ", num);
				found = 1;
				break; 
			}
		}
		/* If the code is not stored, we store it and the index position is increased by one. */
		if(found == 0)
		{
			code[i] = num;
			i++;
		}
	}
	printf("\nCodes: ");
	for(i = 0; i < SIZE; i++)
		printf("%d ", code[i]);
	return 0;
}
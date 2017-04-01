#include <stdio.h>
int main()
{
	int i, j, sel;
	while(1) 
	{
		printf("\n\nMenu selections\n");
		printf("---------------\n");
		printf("1. Add numbers\n");
		printf("2. Subtract numbers\n");
		printf("3. Multiply numbers\n");
		printf("4. Divide numbers\n");
		printf("5. Exit\n");

		printf("\nSelect an option: ");
		scanf("%d", &sel);
		if(sel == 5) /* Program termination. */
			return 0;

		printf("\nEnter numbers: ");
		scanf("%d%d", &i, &j);

		switch(sel)
		{
			case 1:
				printf("Sum = %d\n", i+j);
			break;

			case 2:
				printf("Diff = %d\n", i-j);
			break;

			case 3:
				printf("Product = %d\n", i*j);
			break;
			case 4:
				if(j != 0)
					printf("Div= %.2f\n", (float)i/j);
				else
					printf("Error: Second number should not be zero\n");
			break;

			default:
				printf("Wrong input\n");
			break;
		}
getchar();
	}
	return 0;
}
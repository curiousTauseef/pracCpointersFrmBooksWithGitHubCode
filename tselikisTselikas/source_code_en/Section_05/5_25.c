#include <stdio.h>
int main()
{
	int clas;
	float cost, weight;

	printf("Enter class (1-Eco, 2-Business, 3-VIP): ");
	scanf("%d", &clas);

	printf("Enter weight: ");
	scanf("%f", &weight);

	cost = 0; /* All cases where the passenger pays nothing. */
	switch(clas)
	{
		case 1:
			if(weight > 40)
				cost = 22.5 + 2*(weight-40); /* 22.5 = 1.5 * 15. */
			else if(weight > 25) /* Since the previous "if" checks if the weight is more than 40lb, this else-if statement checks whether 25 < weight <= 40. */
				cost = 1.5*(weight-25);
		break;

		case 2:
			if(weight > 50)
				cost = 18.75 + 1.5*(weight-50); /* 18.75 = 1.25 * 15. */
			else if(weight > 35)
				cost = 1.25*(weight-35);
		break;

		case 3:
			if(weight > 60)
				cost = 30;
		break;

		default:
			printf("Error: Wrong traffic class\n");
		break;
	}
	printf("Total cost = %.2f\n", cost);
	return 0;
}
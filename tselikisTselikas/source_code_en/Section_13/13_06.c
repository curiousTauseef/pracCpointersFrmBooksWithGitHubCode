#include <stdio.h>

void swap(struct book *b1, struct book *b2);

struct book
{
	char title[50]; 
	int code;
	float prc;
};

int main()
{
	int i;
	struct book b[2]; 

	for(i = 0; i < 2; i++)
	{
		printf("\nEnter title: ");
		gets(b[i].title); 

		printf("Enter code: ");
		scanf("%d", &b[i].code);

		printf("Enter price: ");
		scanf("%f", &b[i].prc);

		getchar();
	}
	swap(&b[0], &b[1]);
	for(i = 0; i < 2; i++)
		printf("\nN: %s C: %d P: %.2f\n", b[i].title, b[i].code, b[i].prc);
	return 0;
}

void swap(struct book *b1, struct book *b2)
{
	struct book temp;

	temp = *b1;
	*b1 = *b2;
	*b2 = temp;
}
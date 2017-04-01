#include <stdio.h>

struct computer
{
/* Assume that 50 characters are enough to hold the computer’s characteristics. */
	char comp[50];
	char model[50];
	char cpu[50];
	float prc;
};
int main()
{
	struct computer pc;

	printf("Enter company: ");
	gets(pc.comp);

	printf("Enter model: ");
	gets(pc.model);

	printf("Enter cpu: ");
	gets(pc.cpu);

	printf("Enter price: ");
	scanf("%f", &pc.prc);

	printf("\nC:%s M:%s CPU:%s P:%.2f\n", pc.comp, pc.model, pc.cpu, pc.prc);
	return 0;
}
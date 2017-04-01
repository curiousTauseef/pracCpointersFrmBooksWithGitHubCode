#include <stdio.h>

#define f(type, text, a) printf(text); scanf(type, &a); printf(type"\n", a);

int main()
{
	int i;
	float fl;
	char str[100];

	f("%d", "Enter integer: ", i);
	f("%f", "Enter float: ", fl);
	f("%s", "Enter text: ", str);
	return 0;
}
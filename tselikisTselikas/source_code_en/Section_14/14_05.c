#include <stdio.h>
#include <stdlib.h>

int mem_cmp(const void *ptr1, const void *ptr2, size_t size);

int main()
{
	char str1[100], str2[100];
	int num;

	printf("Enter first text: ");
	gets(str1);

	printf("Enter second text: ");
	gets(str2);

	printf("Enter characters to compare: ");
	scanf("%d", &num);

	printf("%d\n", mem_cmp(str1, str2, num));
	return 0;
}

int mem_cmp(const void *ptr1, const void *ptr2, size_t size)
{
	char *p1, *p2;
	
	p1 = (char *)ptr1;
	p2 = (char *)ptr2;
	while(size != 0) 
	{
		if(*p1 != *p2)
			return *p1 - *p2; 
		p1++;
		p2++;
		size--;
	}
	return 0;
}
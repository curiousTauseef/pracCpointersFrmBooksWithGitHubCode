#include <stdio.h>
#include <string.h>

int str_cmp(const char *str1, const char *str2);

int main()
{
	int ret;
	char buf1[100], buf2[100];

	printf("Enter first string: ");
	gets(buf1);
	printf("Enter second string: ");
	gets(buf2);

	ret = str_cmp(buf1, buf2);
	if(ret == 0)
		printf("%s = %s\n", buf1, buf2);
	else if(ret < 0)
		printf("%s < %s\n", buf1, buf2);
	else
		printf("%s > %s\n", buf1, buf2);
	return 0;
}

int str_cmp(const char *str1, const char *str2)
{
	while(*str1 == *str2)
	{
		if(*str1 == '\0') 
			return 0;
		str1++;
		str2++;
	}
	return *str1 - *str2;
}
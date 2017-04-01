#include <stdio.h>
int main()
{
	int i, j, k, cnt; 

	printf("Enter numbers: ");
	scanf("%d%d%d", &i, &j, &k);

	if((i+j == k) || (j+k == i) || (i+k == j))
	{
		if(i >= 0 && i <= 10)
			printf("%d\n", i);
		if(j >= 0 && j <= 10)
			printf("%d\n", j);
		if(k >= 0 && k <= 10)
			printf("%d\n", k);
	}
	else
	{
		printf("Enter numbers: ");
		scanf("%d%d%d", &i, &j, &k);

		cnt = 0;
		if(i%6 == 0)
			cnt++;
		if(j%6 == 0)
			cnt++;
		if(k%6 == 0)
			cnt++;

		printf("%d\n", cnt);
	}
	return 0;
}

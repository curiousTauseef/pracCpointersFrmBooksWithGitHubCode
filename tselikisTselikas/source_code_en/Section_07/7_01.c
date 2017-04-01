#include <stdio.h>
int main()
{
	int i, arr[] = {10, 20, 30, 40, 50};

	for(i = 0; i < 5; i++)
	{ /* The braces are not necessary. */
		if(arr[i] > 20)
			printf("%d\n", arr[i]);
	}
	return 0;
}
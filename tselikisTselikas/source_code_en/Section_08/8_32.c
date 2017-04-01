#include <stdio.h>

#define SIZE 100

int main()
{
	int *ptr1, *ptr2, num, arr[SIZE];

	ptr1 = ptr2 = arr; /* ptr2 points to the position of the array where the last code is stored. */
	while((ptr2 - arr) != SIZE)
	{
		printf("Enter code: ");
		scanf("%d", &num);

		ptr1 = arr;
		while(ptr1 != ptr2) /* Starting from the beginning, we check if the input code is already stored. */
		{
			if(*ptr1 == num)
			{
				printf("Error: Code %d exists\n", *ptr1);
				break;
			}
			ptr1++;
		}
		/* If the code is not stored, it’s stored and the pointer is increased. */
		if(*ptr1 != num)
		{
			*ptr2 = num;
			ptr2++;
		}
	}
	/* Display the codes. */
	ptr1 = arr;
	while(ptr1 < ptr2)
	{
		printf("C: %d\n", *ptr1);
		ptr1++;
	}
	return 0;
}
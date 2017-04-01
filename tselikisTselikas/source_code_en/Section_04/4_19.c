#include <stdio.h>
int main()
{
	unsigned int num, temp;

	printf("Enter number [0-255]: ");
	scanf("%d", &num);

	if(num >= 0 && num <= 255)
	{
		temp = num & 0xF; /* The value of the four low bits is stored in temp. 0xF is coded as 00001111 in binary. */
		temp <<= 4; /* Shift temp by four places to the left.  */
		temp += num >> 4; /* Add to temp the value of num shifted by four places to the right. */
		printf("Num_1 = %d  Num_2 = %d\n", num, temp);
	}
	else
		printf("Number should be in [0-255]\n");
	return 0;
}
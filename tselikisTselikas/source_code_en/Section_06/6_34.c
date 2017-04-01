#include <stdio.h>
int main()
{
      int i, num;

      while(1)
      {
            printf("\nEnter number: ");
            scanf("%d", &num);

            if(num < 0 || num > 255)
                  break;

            for(i = 0; i < 8; i++) /* Check the value of each bit. */
            {
                  (num & 128) ? printf("1") : printf("0");
                  num <<= 1; /* Shift all bits one place left. */
            }
      }
	return 0;
}
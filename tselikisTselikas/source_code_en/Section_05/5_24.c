#include <stdio.h>
int main()
{
      int sex;
      float height;

      printf("Enter sex (0:male - 1:female): ");
      scanf("%d",&sex);

      printf("Enter height (in feet): ");
      scanf("%f",&height);

      switch(sex)
      {
            case 0:
                  if(height < 5.50)
                        printf("Result: Short\n");
                  else if(height < 6.00)
                        printf("Result: Normal\n");
                  else
                        printf("Result: Tall\n");
            break;

            case 1:
                  if(height < 5.25)
                        printf("Result: Short\n");
                  else if(height < 5.75)
                        printf("Result: Normal\n");
                  else
                        printf("Result: Tall\n");
            break;

            default:
                  printf("Error: Wrong input\n");
            break;
      }
      return 0;
}
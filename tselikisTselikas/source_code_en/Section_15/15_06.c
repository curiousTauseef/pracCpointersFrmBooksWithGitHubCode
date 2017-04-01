#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
      FILE *fp;
      char flag, str[20], prod[20];
      double prc;

      fp = fopen("test.txt", "w+"); /* Open file for reading and writing. */
      if(fp == NULL)
      {
            printf("Error: File can't be created\n");
            exit(1);
      }
      while(1)
      {
            printf("Enter price: ");
            scanf("%lf", &prc);
            if(prc == -1)
                  break;
            getchar();
            printf("Enter product code: ");
            gets(str);
            fprintf(fp, "%s %f\n", str, prc);
      }
      getchar();
      printf("Enter product code to search for: ");
      gets(prod);
      
      flag = 0;
      fseek(fp, 0, SEEK_SET); 
      while(1)
      {
            if(fscanf(fp, "%s%lf", str, &prc) != 2) 
                  break;
            if(strcmp(str, prod) == 0)
            {
                  flag = 1;
                  break; /* Since the product is found exit from the loop. */
            }
      }
      if(flag == 0)
            printf("The %s product is not listed\n", prod);
      else
            printf("The price for product %s is %f\n", prod, prc);
      fclose(fp);
      return 0;
}
#include <stdio.h>
#include <stdlib.h>

typedef struct {
      char name[50];
      char capital[50];
      int pop;
} country; 

int main()
{
      FILE *fp;
      country *cntr;
      char fname[100];
      int i, num_cntr, pop;

      printf("Enter file name: ");
      gets(fname);

      fp = fopen(fname, "r");
      if(fp == NULL)
      {
            printf("Error: File can't be loaded\n");
            exit(1);
      }
      if(fscanf(fp, "%d", &num_cntr) != 1)
      {
            printf("Error: fscanf() failed\n");
            exit(1);
      }
	/* Dynamic memory allocation to store the countries’ data. */
      cntr = (country *)malloc(num_cntr * sizeof(country));
      if(cntr == NULL)
      {
            printf("Error: Not available memory\n");
            exit(1);
      }
      for(i = 0; i < num_cntr; i++)
            if(fscanf(fp, "%s%s%d", cntr[i].name, cntr[i].capital, &cntr[i].pop) != 3)
            {
                  printf("Error: fscanf() read error\n");
                  exit(1);
            }
      fclose(fp);
      printf("Enter population: ");
      scanf("%d", &pop);

      for(i = 0; i < num_cntr; i++)
            if(cntr[i].pop >= pop)
                  printf("%s %s\t%d\n", cntr[i].name, cntr[i].capital, cntr[i].pop);

      free(cntr);
	return 0;
}
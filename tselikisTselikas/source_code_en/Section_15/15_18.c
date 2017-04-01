#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 100
#define LEN  30

struct employee 
{
      char name[LEN];
      int tax_num;
      int salary;
};

int main()
{
      FILE *fp;
      int i, num_empl;
      struct employee empl[SIZE];

      fp = fopen("test.bin", "wb"); 
      if(fp == NULL)
      {
            printf("Error: File can't be created\n");
            exit(1);
      }
      num_empl = 0; 
      for(i = 0; i < SIZE; i++)
      {
            printf("\nEnter full name: ");
            gets(empl[i].name);
            if(strcmp(empl[i].name, "fin") == 0)
                  break;

            printf("Enter tax number: ");
            scanf("%d", &empl[i].tax_num);

            printf("Enter salary: ");
            scanf("%d", &empl[i].salary);

            num_empl++;
		getchar();
      }
	/* Write the data structures in a single step. */
      fwrite(empl, sizeof(struct employee), num_empl, fp); 
      fclose(fp);
      return 0;
}
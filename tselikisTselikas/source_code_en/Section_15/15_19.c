#include <stdio.h>
#include <stdlib.h>

#define LEN 30

struct employee 
{
      char name[LEN];
      int tax_num;
      int salary;
};

int main()
{
      FILE *fp_in, *fp_out;
      int count, amount, sum_sal;      
      struct employee tmp_emp;

      fp_in = fopen("test.bin", "rb"); 
      if(fp_in == NULL)
      {
            printf("Error: Input file can't be loaded\n");
            exit(1);
      }
      fp_out = fopen("data.bin", "wb"); 
      
if(fp_out == NULL)
      {
            printf("Error: Output file can't be created\n");
            exit(1);
      }
      printf("Enter amount: ");
      scanf("%d", &amount);
      count = sum_sal = 0;
      while(1)
      {
            if(fread(&tmp_emp, sizeof(employee), 1, fp_in) != 1)
                  break;
            if(tmp_emp.salary > amount)
            {
                  fwrite(&tmp_emp, sizeof(employee), 1, fp_out);
                  sum_sal += tmp_emp.salary;
                  count++;
            }
      }
      if(count)
            printf("Avg = %.2f\n", (float)sum_sal/count);
      else 
            printf("No employee gets more than %d\n", amount);

      fclose(fp_in);
      fclose(fp_out);
      return 0;
}
#include <stdio.h>
#include <stdlib.h>
int main()
{
      FILE *fp_in, *fp_out;
      char fname[100];
      int ch, key_ch;

      printf("Enter input file: ");
      gets(fname);

      fp_in = fopen(fname, "r");
      if(fp_in == NULL)
      {
            printf("Error: Input file can't be loaded\n");
            exit(1); 
      }
      printf("Enter output file: ");
      gets(fname);

      fp_out = fopen(fname, "w");
      if(fp_out == NULL)
      {
            printf("Error: Output file can't be created\n");
            exit(1); 
      }
      printf("Enter key char: ");
      key_ch = getchar();
      while(1)
      {
            ch = getc(fp_in);
            if(ch == EOF)
                  break;
            putc(ch ^ key_ch, fp_out); 
      }
      fclose(fp_in);
      fclose(fp_out);
	return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
      FILE *fp;
      char str[100];
      int i, cnt;

      printf("Enter file name: ");
      gets(str);
      fp = fopen(str, "a"); /* Open file for appending. */
      if(fp == NULL)
      {
            printf("Error: File can’t be created\n");
            exit(1);
      }
      cnt = 0;
      while(1)
      {
            printf("Enter text: ");
            gets(str);
            if(strcmp(str, "final") == 0)
                 	break;
            if((str[0] == 'a') && (strlen(str) < 10))
            {
                  cnt++;
                  fputs(str, fp);
            }
      }
      printf("\n%d strings were written\n", cnt);
      fclose(fp);
	return 0;
}
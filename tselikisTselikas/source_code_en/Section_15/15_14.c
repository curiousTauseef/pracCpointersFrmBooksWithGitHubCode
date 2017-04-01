#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
      FILE *fp;
      char found, str[100], tmp_str[100];
      int i, len;

      printf("Enter file name: ");
      gets(str);

      fp = fopen(str, "w+b"); 
      if(fp == NULL)
      {
            printf("Error: File can't be created\n");
            exit(1); 
      }
      for(i = 0; i < 10; i++)
      {
            printf("Enter text: ");
            gets(str);

            len = strlen(str);
            fwrite(&len, sizeof(int), 1, fp);
            fwrite(str, 1, len, fp);
      }
      printf("Enter title to search: ");
      gets(tmp_str);

      found = 0;
      fseek(fp, 0, SEEK_SET);
      while(1)
      {
            if(fread(&len, sizeof(int), 1, fp) != 1) 
                  break; 
            if(fread(str, 1, len, fp) != len) 
                  break; 
            str[len] = '\0';
            if(strcmp(str, tmp_str) == 0)
            {
                  found = 1;
                  break;
            }
      }
      if(found == 0)
            printf("\n%s isn't found\n", tmp_str);
      else
            printf("\n%s is found\n", tmp_str);

      fclose(fp);
	return 0;
}
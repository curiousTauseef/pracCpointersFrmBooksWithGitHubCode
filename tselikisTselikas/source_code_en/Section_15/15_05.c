#include <stdio.h>
#include <stdlib.h>

FILE *open_file(char name[], int *f);

int main()
{
	FILE *fp;
	char name[100];
	int flag, sel;

	flag = 0;
	do
	{
		printf("Enter file name: ");
		scanf("%s", name);

		fp = fopen(name, "r"); /* Check whether the file exists or not. If not, we create and open it for writing. Otherwise, we close the file and ask the user. */
		if(fp == NULL)
			fp = open_file(name, &flag);
		else
		{
			fclose(fp);
			printf("Would you like to overwrite existing file (Yes:1 - No:0)? ");
			scanf("%d", &sel);
			if(sel == 1) /* Overwrites the existing file. */
				fp = open_file(name, &flag);
		}
      } while(flag == 0);
 
	fputs("One", fp);
	fclose(fp);
	return 0;
}

FILE *open_file(char name[], int *f)
{
	FILE *fp;

      fp = fopen(name, "w"); 
      if(fp == NULL)
      {
            printf("Error: File can�t be created\n");
            exit(1);
      }
	*f = 1;
      return fp;
}
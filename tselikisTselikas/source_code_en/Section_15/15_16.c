#include <stdio.h>
#include <stdlib.h>
int main()
{
      FILE *fp;
      int i, grd_num;
      float grd, *grd_arr;

      fp = fopen("test.bin", "rb"); 
      if(fp == NULL)
      {
            printf("Error: File can't be loaded\n");
            exit(1); 
      }
      fseek(fp, 0, SEEK_END); 
      grd_num = ftell(fp) / sizeof(float); /* Since the file pointer is at the end of file, ftell() returns the size of the file in bytes. Since each grade is stored as float, their division calculates the number of grades stored in the file. */
      fseek(fp, 0, SEEK_SET); 
      grd_arr = (float *) malloc(grd_num * sizeof(float)); /* Allocate memory to store the grades. */
      if(grd_arr == NULL)
      {
            printf("Error: Not available memory\n");
            exit(1);
      }
	/* Read all grades and check if they are read successfully. */
      if(fread(grd_arr, sizeof(float), grd_num, fp) == grd_num) 
      {
            printf("Enter grade: ");
            scanf("%f", &grd);
            for(i = 0; i < grd_num; i++)
                  if(grd_arr[i] > grd)
                        printf("%f\n", grd_arr[i]);
      }
	else 
            printf("Error: fread() failed\n");

      free(grd_arr);
      fclose(fp); 
      return 0;
}
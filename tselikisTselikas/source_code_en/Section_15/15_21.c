#include <stdio.h>
#include <stdlib.h>

#define LESSONS 5

int main()
{
      FILE *fp;
      int i, j, stud_num, grd_num;
      float sum_grd, **grd_arr;

      fp = fopen("test.bin", "rb"); 
      if(fp == NULL)
      {
            printf("Error: File can't be loaded\n");
            exit(1); 
      }
      fseek(fp, 0, SEEK_END); 
      grd_num = ftell(fp) / sizeof(float); 
      fseek(fp, 0, SEEK_SET); 

      stud_num = grd_num / LESSONS; /* Since grd_num indicates the total number of grades stored in the file and each line contains LESSONS grades, their division calculates the number of rows, that is the number of students. */
	/* We use the grd_arr as a two-dimensional array of 'stud_num' rows and 'LESSONS' columns, meaning that each line holds a student’s grades in 'LESSONS' courses. */
      grd_arr = (float **) malloc(stud_num * sizeof(float *)); 
   
      if(grd_arr == NULL)
      {
            printf("Error: Not available memory\n");
            exit(1);
      }
      for(i = 0; i < stud_num; i++)
      {
            grd_arr[i] = (float *) malloc(LESSONS * sizeof(float));
            if(grd_arr[i] == NULL)
            {
                  printf("Error: Not available memory\n");
                  exit(1);
            }
      }
      for(i = 0; i < stud_num; i++)
      {
            sum_grd = 0;
            if(fread(grd_arr[i], sizeof(float), LESSONS, fp) == LESSONS) 
            {
                  for(j = 0; j < LESSONS; j++)
                        sum_grd += grd_arr[i][j];

                  printf("%d. %f\n", i+1, sum_grd/LESSONS);
            }
            else 
            {
                  printf("Error: fread() failed\n");
                  break; /* Stop reading. */
            }
      }
      for(i = 0; i < stud_num; i++)
            free(grd_arr[i]);

      free(grd_arr);
      fclose(fp); 
      return 0;
}
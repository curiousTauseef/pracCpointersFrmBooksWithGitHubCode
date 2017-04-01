#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN 30

typedef struct {
      char name[LEN];
      char category[LEN];
      char singer[LEN];
      int records;
} band; 

int main()
{
      FILE *fp;
      band *band_arr;
      char found, name[LEN], singer[LEN];
      int i, band_num;

      fp = fopen("test.bin", "r+b"); 
      if(fp == NULL)
      {
            printf("Error: File can't be loaded\n");
            exit(1);
      }
      fseek(fp, 0, SEEK_END); 
      band_num = ftell(fp) / sizeof(band); /* We divide the return value of ftell() with the size of one structure to calculate the number of the stored structures. */
      fseek(fp, 0, SEEK_SET); 

      band_arr = (band *) malloc(sizeof(band) * band_num); 
      if(band_arr == NULL)
      {
            printf("Error: Not available memory\n");
            exit(1);
      }
      if(fread(band_arr, sizeof(band), band_num, fp) == band_num) 
      {
            printf("Enter band name: ");
            gets(name);

            printf("Enter new singer: ");
            gets(singer);

            found = 0;
            for(i = 0; i < band_num; i++)
                  if(strcmp(band_arr[i].name, name) == 0)
                  {
                        fseek(fp, i*sizeof(band), SEEK_SET); /* If the band is found, move the file pointer to the beginning of this structure. */
                        strcpy(band_arr[i].singer, singer); /* Change the singer field and write the data structure in the current position. */
                        fwrite(&band_arr[i], sizeof(band), 1, fp);
				printf("\n%Singer of band %s is changed to %s\n", name, singer);
                        found = 1;
                        break;
                  }
      }
      else 
            printf("Error: fread() failed !!!\n");

      if(found == 0)
            printf("\n%s band isn't found\n\n", name);

      free(band_arr);
      fclose(fp); 
      return 0;
}
#include <stdio.h>
#include <stdlib.h>

#define SIZE 5 

int main()
{
      FILE *fp;
      int i, arr[SIZE] = {10, 20, 30, 40, 50};

      fp = fopen("test.bin", "w+b"); 
      if(fp == NULL)
      {
            printf("Error: File can't be created\n");
            exit(1); 
      }
      fwrite(arr, sizeof(int), SIZE, fp); 

      printf("Enter new value: ");
      scanf("%d", &i);
      fseek(fp, 2*sizeof(int), SEEK_SET); /* Since each integer is 4 bytes, fseek() moves the file pointer 2*sizeof(int) = 8 bytes from the beginning of the file to get to the third integer. */
      fwrite(&i, sizeof(int), 1, fp); /* The second and third arguments specify that one element of sizeof(int) = 4 bytes will be written in the file. The first argument specifies the memory address of the written number. */
      fseek(fp, 0, SEEK_SET);
      fread(arr, sizeof(int), SIZE, fp);
      printf("\n***** File contents *****\n");
      for(i = 0; i < SIZE; i++)
            printf("%d\n", arr[i]);

      fclose(fp);
	return 0;
}
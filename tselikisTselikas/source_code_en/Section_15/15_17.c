#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 5

int main()
{
	FILE *fp;
	int i, found, len, buf[SIZE], pat[SIZE];

	fp = fopen("test.dat", "r+b");
	if(fp == NULL)
	{
		printf("Error: File can't be loaded\n");
		exit(1);
	}
	printf("Enter virus signature (%d integers)\n", SIZE);
	for(i = 0; i < SIZE; i++)
	{
		printf("Enter number: ");
		scanf("%d", &pat[i]);
	}
	len = sizeof(pat);
	found = 0;
	while(1)
	{
		if(fread(buf, sizeof(int), SIZE, fp) != SIZE)
			break;
		if(memcmp(buf, pat, len) == 0)
		{
			found = 1;
			break;
		}
		else
			fseek(fp, -(len-sizeof(int)), SEEK_CUR); /* Go back to check the next group of five. */
	}
	if(found == 1)
		printf("SOS: Virus found\n");
	else
		printf("That virus signature isn't found\n");

	fclose(fp);
	return 0;
}
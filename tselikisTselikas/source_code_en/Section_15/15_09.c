#include <stdio.h>
#include <stdlib.h>
int main()
{
	FILE *fp;
	char fname[100];
	int ch, lines;

	printf("Enter file name: ");
	gets(fname);
	
	fp = fopen(fname,"r");
	if(fp == NULL)
	{
		printf("Error: File can’t be loaded\n");
		exit(1); 
	}
	printf("\nLine contents\n");
	lines = 1;
	while(1)
	{
		ch = getc(fp); 
		if((ch == EOF) || (lines > 2))
			break;
		if(ch == '\n') /* Increase the line counter. */
			lines++;
		if(lines == 2) /* Only the characters of the second line are displayed. */
			printf("%c", ch);
	}
	fclose(fp);
	return 0;
}
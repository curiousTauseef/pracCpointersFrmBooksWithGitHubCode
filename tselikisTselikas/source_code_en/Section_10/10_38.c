#include <stdio.h>
int main()
{
	char ch, str[100];
	int i, low_let[26] = {0}; /* The size of the array is equal to the number of low-case letters. This array holds the number of the appearances of each letter. For example, low_let[0] holds the appearances of 'a' and low_let[25] the appearances of 'z'. */
	int dig[10] = {0}; /* Similarly, dig[0] holds the appearances of digit 0 and dig[9] the appearances of digit 9. */
	printf("Enter text: ");
	gets(str);
	for(i = 0; str[i] != '\0'; i++) 
	{
		ch = str[i];
		if((ch >= 'a') && (ch <= 'z'))
			low_let[ch - 'a']++; /* For example, if the read character is 'a', the value of low_let['a'–'a'] = low_let[0], which holds the appearances of 'a' will be increased by one. */
		else if((ch >= '0') && (ch <= '9'))
			dig[ch - '0']++; 
	}
	printf("***** Lower case letters appearances\n"); 
	for(i = 0; i < 26; i++)
		if(low_let[i] != 0) /* Check if the character appears once at least. */
			printf("Letter %c appeared %d times\n", 'a'+i, low_let[i]);

	printf("***** Digits appearances\n"); 
	for(i = 0; i < 10; i++)
		if(dig[i] != 0)
			printf("Digit %d appeared %d times\n", i, dig[i]);
	return 0;
}
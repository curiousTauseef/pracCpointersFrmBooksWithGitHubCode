#include <stdio.h>
#include <string.h>

#define TOURISTS	100
#define ANSWERS	6

int main()
{
	int i, j, sel, pnts[ANSWERS] = {0}; /* This array holds the points of each answer. For example, pnts[0] holds the points of the first answer, pnts[1] holds the points of the second answer and so forth. */

	int given_ans[ANSWERS] = {0}; /* This array is used to check whether an answer is already given or not. If an element’s value is 1, means that the respective answer is selected. For example, if the user selects the third answer the value of given_ans[2] becomes 1. */
	for(i = 0; i < TOURISTS; i++)
	{
		printf("\nEnter answers of tourist_%d:\n", i+1);

		memset(given_ans, 0, sizeof(given_ans)); /* The values of the given_ans array must be zeroed before reading the answers of a new tourist. See memset() in Appendix C. */
		for(j = 0; j < ANSWERS; j++)
		{
			while(1) /* Infinite loop until the user enters a valid answer in [1,6], not already given. */
			{
				printf("Answer_%d [1-%d]: ", j+1, ANSWERS);
				scanf("%d", &sel);
				
				if(sel < 1 || sel > ANSWERS)
					printf("Wrong answer ...\n");
				else if(given_ans[sel-1] == 1)
					printf("Error: This answer is already given ...\n");
				else
					break;
			} 
			pnts[sel-1] += ANSWERS - j; /* For example, if the first answer (j = 0) is the fifth one, then pnts[sel-1] = pnts[5-1] = pnts[4] += 6–0 = 6; meaning that 6 more points will be added to the points of the fifth choice. */
			given_ans[sel-1] = 1;
		}
	}
	printf("\n***** Answer Results *****\n");
	for(i = 0; i < ANSWERS; i++)
		printf("Answer #%d gets %d points\n", i+1, pnts[i]);
	return 0;
}
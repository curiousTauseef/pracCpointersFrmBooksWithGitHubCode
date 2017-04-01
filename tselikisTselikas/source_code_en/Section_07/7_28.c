#include <stdio.h>
#include <stdlib.h>

#define ROWS 30
#define COLS 20

int main()
{
	int i, j, sel, row, col, rsvd_seats, cost, seats[ROWS][COLS] = {0}; /* We use the array seats to manage the cinema’s seats. If an element’s value is 0, it implies that the seat is free. */

	rsvd_seats = cost = 0;
	while(1) 
	{
		printf("\nMenu selections\n");
		printf("---------------\n");

		printf("1. Buy Ticket\n");
		printf("2. Ticket Refund\n");
		printf("3. Show Information\n");
		printf("4. Exit\n");

		printf("\nEnter choice: ");
		scanf("%d", &sel);

		switch(sel)
		{
			case 1:
				if(rsvd_seats == ROWS*COLS)
				{
					printf("\nSorry, no free seats\n");
					break;
				}
				printf("\nWould you like a specific seat (No: 0)? ");
				scanf("%d", &sel);
				if(sel == 0)
				{
					do
					{
						row = rand() % ROWS; /* Use rand() to select a random seat. */
						col = rand() % COLS;
					} while(seats[row][col] == 1);
				}
				else
				{
					do
					{
						printf("\nEnter row (0-%d): ", ROWS-1);
						scanf("%d", &row);
					} while(row < 0 || row > ROWS-1);

					do
					{
						printf("Enter seat (0-%d): ", COLS-1);
						scanf("%d", &col);
					} while(col < 0 || col > COLS-1);
				}
				if(seats[row][col] == 1)
					printf("\nSorry, seat in row_%d and column_%d is reserved\n", row, col);
				else
				{
					seats[row][col] = 1;
					cost += 6;
					rsvd_seats++;
				}
			break;

			case 2:
				if(rsvd_seats == 0)
				{
					printf("\nAll seats are free\n");
					break;
				}
				do
				{
					printf("\nEnter row (0-%d): ", ROWS-1);
					scanf("%d", &row);
				} while(row < 0 || row > ROWS-1);

				do
				{
					printf("Enter seat (0-%d): ", COLS-1);
					scanf("%d", &col);
				} while(col < 0 || col > COLS-1);

				if(seats[row][col] != 1)
					printf("\nSeat in row_%d and column_%d is not reserved\n", row, col);
				

else
				{
					seats[row][col] = 0;
					cost -= 5;
					rsvd_seats--;
				}
			break;

			case 3:
				printf("\nFree seats: %d, Income: %d\n\n", ROWS*COLS – rsvd_seats, cost);
				for(i = 0; i < ROWS; i++)
				{
					for(j = 0; j < COLS; j++)
					{					
						if(seats[i][j] == 1)
							printf("%2s", "X");
						else
							printf("%2s", "#");
					}
					printf("\n"); 
				}
			break;

			case 4:
			return 0;

			default:
				printf("\nWrong choice\n");
			break;
		}
	}
	return 0;
}
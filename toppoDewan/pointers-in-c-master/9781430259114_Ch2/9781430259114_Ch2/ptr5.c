#include <stdio.h>
//Conio was developed by Borland, no more part of linux or POSIX
//#include <conio.h>
//sudo apt-get install libncurses-dev
#include <curses.h>	
									    
struct inner_node
{					
	int in_a;	
	int in_b;
};
struct node{   
	int *a;	
	int *b;	
	struct inner_node* in_node;	
};
int main()		
{	
	struct node *p;
	int *arrptr;
	int arr[10];
	arrptr = arr;
	printf("Size of pointer variable (struct node*) = %d\n",sizeof(struct node*));
	printf("Size of pointer variable pointing to int array = %d\n", sizeof(arrptr));
	return 0;
}

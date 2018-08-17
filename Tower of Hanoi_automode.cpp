/*  Tower of Hanoi (3 towers) 
	First tower contains few discs of all different radius, and placed according to increasing order of radius, biggest at bottom.
	And remaining 2 towers are empty.
	
	Challenge -
	Shift all those discs to other empty tower.
	
	Conditions -
	Only one disc at a time can be shifted.
	At any moment, smaller disc shouldn't be under bigger disc.
	
	This code is written to solve above puzzle in minimum number of steps.
	It is recursive algorithm.
	
	You can change number of discs to any integer by editing line number 38.
	Line number 38: (#define size 		6)
	
	As well as, you can decide initial tower and final tower of discs by editing line number 39 & 40.
	Line number 39: (#define initial_positions 		1)
	Line number 40: (#define final_positions 		3)


	Author - Pravin Mote
	4th Oct 2014
*/





#include <string.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>


// User inputs
#define size 					5			//  Total number of rings in tower
#define initial_positions 		1			//  Shows which tower contains rings initially,  VAlid inputs = 1,2,3 
#define final_positions 		3			//  Shows number of desired tower where finally all rings should be collected,   Valid input = 1,2,3



void print_positions(int stack[3][size]);
void move(int ring, int source, int target, int stack[3][size], int top[3]);



int main()
{
	int i, stack[3][size];
	int top[3] = {0, 0, 0};	// This array will indicate position of top ring in each tower, or we can say, number of rings in each tower.

	int source = initial_positions-1, target = final_positions-1;
	

	
	if(initial_positions<1 || initial_positions>3 || final_positions<1 || final_positions>3)	// Check whether inputs are valid or not.
	{
		printf("\nInvalid input for initial position or final position of rings.\n");
		
		return 0;
	}
	
	if(initial_positions == final_positions)				// No need of rearrangement
	{
		printf("\nRings are already in final positions.\n");
		
		return 0;
	}
	

	
	top[source] = size;
	
	for(i=0; i<size; i++)
	{
		stack[initial_positions-1][i] = size-i;
		stack[(initial_positions)%3][i] = 0;
		stack[(initial_positions+1)%3][i] = 0;
	}
	
	print_positions(stack);

	move(size, source, target, stack, top);


	printf("\n\n Total replacement count = %d\n", (0b01<<size)-1);
	
	return 0;
}


void print_positions(int stack[3][size])
{
	int i, j;

	printf("\n\n");

	for(i=0; i<3; i++)
	{
		printf("       Stack%d----", i+1);
		
		for(j=0; j<size; j++)
		{
			printf(" %d", stack[i][j]);
		}
	}
	

	//  Check for wrong placement of ring
	for(i=0; i<3; i++)
	{
		for(j=0; j<size-1; j++)
		{
			if(stack[i][j] < stack[i][j+1])
			{
				printf("\n       Wrong placement of ring in stack%d----", i+1);
			}
		}
	}
}


void move(int ring, int source, int target, int stack[3][size], int top[3])
{
	int extra=0;
	
	if(stack[source][top[source]-1] != ring)					//	Move upper rings before moving current ring
	{
		move(ring-1, source, 2*(source+target)%3, stack, top);
		extra = 1;
	}
	
	
	/* Move current ring */
	stack[target][top[target]] = stack[source][top[source]-1];
	top[target]++;
	
	stack[source][top[source]-1] = 0;
	top[source]--;
		
	print_positions(stack);
	
	
	if(extra == 1)												// Bring back upper rings to current ring
	{
		move(ring-1, 2*(source+target)%3, target, stack, top);
	}
}

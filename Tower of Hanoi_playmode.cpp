/*  Tower of Hanoi (3 towers) 
	First tower contains few discs of all different radius, and placed according to increasing order of radius, biggest at bottom.
	And remaining 2 towers are empty.
	
	Challenge -
	Shift all those discs to other empty tower.
	
	Conditions -
	Only one disc at a time can be shifted.
	At any moment, smaller disc shouldn't be under bigger disc.

	How to play -
	3 towers with name "A,B,C". Initially tower 'A' contains all discs.
	If you want to move top disc from 'A' to 'B', then type "A B" or "AB" (with space or without space between 2 letters. & press Enter.)
	You can use all different combinations like - "A C", "B c", "C B", "C A", "B A".

	Levels -
	You can increase/decrease number of discs by editing varible named "size" at line number 38.
	Line number 38: (#define size 	3)
	
	You can change initial tower to 'B' or 'C' by editing line number 39. Here, 1 means A, 2 means B, 3 means C.
	Line number 39: (#define initial_positions 		1)

	Author - Pravin Mote
	7th Oct 2014
*/



#include <string.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


// User inputs
#define size 					3			//  Total number of rings in tower
#define initial_positions 		1			//  Shows which tower contains rings initially,  VAlid inputs = 1,2,3


void print_positions(int stack[3][size]);


int main()
{
	int i, source, target, count = 1, stack[3][size];
	int top[3] = {0, 0, 0};	// This array will indicate position of top ring in each tower, or we can say, number of rings in each tower.
	char source_char, target_char;

	
	top[initial_positions-1] = size;
	
	for(i=0; i<size; i++)
	{
		stack[initial_positions-1][i] = size-i;
		stack[(initial_positions)%3][i] = 0;
		stack[(initial_positions+1)%3][i] = 0;
	}
	
	print_positions(stack);
	
	
	
	while((top[initial_positions-1]!=0) || ((top[(initial_positions)%3]!=0)&&(top[(initial_positions+1)%3]!=0)))
	{
		printf("             (count = %d) Give source and destination names - ", count);
		
		std::cin >> source_char >> target_char;
		
		
		if((int(source_char)>64)&&(int(source_char<68)))		// Converts input char to int. Converts A to 0, B to 1, C to 2
		{
			source = int(source_char) - 65;
		}
		else if((int(source_char)>96)&&(int(source_char<100)))
		{
			source = int(source_char) - 97;
		}
		else
		{
			printf("\nInvalid input name of stack. Valid inputs are 'A', 'B', 'C'. Try again.");
			continue;
		}
		
		if((int(target_char)>64)&&(int(target_char<68)))
		{
			target = int(target_char) - 65;
		}
		else if((int(target_char)>96)&&(int(target_char<100)))
		{
			target = int(target_char) - 97;
		}
		else
		{
			printf("\nInvalid input name of stack. Valid inputs are 'A', 'B', 'C'. Try again.");
			continue;
		}
		
		
		
		if(top[source]==0)
		{
			printf("\nWrong move. No ring is available to move from source. Try again.");
			continue;
		}
		
		if((top[target]!=0)&&(stack[source][top[source]-1]>stack[target][top[target]-1]))
		{
			printf("\nWrong move. You can not place bigger ring on smaller one. Try again.");
			continue;
		}
		
		if(source == target)
		{
			printf("\nSame source and destination. No change in positions.");
			continue;
		}
		
		
		/* Move current ring */
		stack[target][top[target]] = stack[source][top[source]-1];
		top[target]++;
		
		stack[source][top[source]-1] = 0;
		top[source]--;
		
		print_positions(stack);
		count++;
	}
	

	printf("\n\n     Yeah, that was great. Total replacement count = %d   (Minimum number of replacements can be %d)\n", count-1, (0b01<<size)-1);
	if(count == (0b01<<size))
	{
		printf("     You have achieved it in minimum number of replacements.\n");
	}
	
	return 0;
}


void print_positions(int stack[3][size])
{
	int i, j;

	printf("\n\n");

	for(i=0; i<3; i++)
	{
		printf("     Stack(%c)----", char(i+65));
		
		for(j=0; j<size; j++)
		{
			printf(" %d", stack[i][j]);
		}
	}
}

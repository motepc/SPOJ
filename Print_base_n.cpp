/*

Print continuous numbers for any base system.


Obeservation -
int* array = int* array + 1  gives next integer.
Means pointer shiftes from array[i] to array[i+1]. Not a byte shift, it is a word shift.


Author - Pravin Mote
17th July 2015

*/



#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>


int main()
{
	// Change the base for numbering system, 2 for binary, 10 for decimal, 16 for hexadecimal, or any number.
	int base = 16;

	// Assign number of digits in a output (max is 8)
	int digit = 4;


	int i;
	int operate[8] = {0};
	printf("\n\n");

	while(operate[0] != base)
	{
		printf("\n");
		for(i=0; i<digit; i++)
		{
			if(operate[i] < 10)
				printf("  %d", operate[i]);
			else
				printf("  %c", operate[i]+55);
		}


		i = digit - 1;
		operate[i]++;

		while(operate[i] == base)
		{
			if(i==0)
				break;

			operate[i] = 0;
			i--;
			operate[i]++;
		}
	}

	printf("\n\n");

	return 0;
}


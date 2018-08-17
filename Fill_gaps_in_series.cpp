/*

1 2 3 4 5 6 7 8 9 = 100
Fill gaps by '+' or '-'.
If nothing is in between 2 digits, it means it is a number.
e.g. 1 2 + 3 - 4 means 12+3-4

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

int calculate(int* operate);

int main()
{
	int i, found;
	int operate[9] = {0,0,0,0,0,0,0,0,0};
	printf("\n");

	while(operate[0] != 2)
	{
		found = calculate(&operate[0]);

		if(found == 1)		// means total is 100
		{
			printf("\n  ");

			for(i=0; i<9; i++)
			{
				if(operate[i] == 1)
					printf(" - ");
				else if(operate[i] == 2)
					printf(" + ");

				printf("%d",i+1);
			}

			printf(" = 100");
		}

		// Next number in base 3 system
		i = 8;
		operate[i]++;

		while(operate[i] == 3)
		{
			if(i==0)
				break;

			operate[i] = 0;
			i--;
			operate[i]++;
		}
	}

	printf("\n\n\n");

	return 0;
}


int calculate(int* operate)
{
	int i, ten;
	long long total, current;

	ten = 10; total = 0; current = 9;

	for(i=8; i>0; i--)
	{
		switch(operate[i])
		{
			case 0:
			{
				current = i*ten + current;
				ten = ten * 10;
				break;
			};

			case 1:
			{
				total = total - current;
				current = i;
				ten = 10;
				break;
			};

			case 2:
			{
				total = total + current;
				current = i;
				ten = 10;
				break;
			};

			default :
			{
				printf("\n\n  Error in input operator sequence.\n");
				return 0;
			}
		}
	}

	if(operate[0] == 1)
		total = total - current;
	else
		total = total + current;

	if(total == 100)
		return 1;
	else
		return 0;
}


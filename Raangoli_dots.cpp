/*

For N=3

Output is
      04
   07    02
09    05    01
   08    03
      06


For N = 4

Output is
         07
      11    04
   14    08    02
16    12    05    01
   15    09    03
      13    06
         10


Author - Pravin Mote
12th Aug 2015
*/



#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>


/*
   space = 0 means next line
   space = 1 means digits times spaces
   space = 2 means print digits
*/
void print(int space, int digits);

int main()
{
	int N, column, limit, shift;
	int i, j, k=0;

	printf("\n\n  Give integer input -  ");
	std::cin >> N;

	column = 2*N - 1;
	int trans[column][column];


	for(i=0; i<column; i++)
	{
		for(j=0; j<column; j++)
		{
			trans[i][j] = 0;
		}
	}



	j = 1;
	while(k < column)
	{
		limit = (k+1)<N?(k+1):(2*N-k-1);
		shift = N - limit;

		for(i=0; i<limit; i++)
		{
			trans[2*i+shift][column-1-k] = j;
			j++;
		}

		k++;
	}



	for(i=0; i<k; i++)
	{
		print(0,2);

		for(j=0; j<(2*N-1); j++)
		{
			print(2, trans[i][j]);
			print(1,1);
		}
	}



	printf("\n\n\n");
	return 0;
}

void print(int space, int digits)
{
	int i;

	if(space == 0)
	{
		for(i=0; i<digits; i++)
		{
			printf("\n");
		}

		return;
	}

	if(space == 1)
	{
		for(i=0; i<digits; i++)
		{
			printf("   ");
		}

		return;
	}

	if(digits == 0)
	{
		print(1,1);
		return;
	}

	if(digits<10)
		printf("0%d ", digits);
	else if(digits<100)
		printf("%d ", digits);
	else
		printf("%d", digits);

	return;
}


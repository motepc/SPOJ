/*

Input is n.
Output is nth digit of series  110100100010000 ........

Author - Pravin Mote
27th June 2015

*/



#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>


int main()
{
	int n, disc;
	double sqrt_d;

	while(1)
	{
		printf("\n\n  Digit location   -  ");
		std::cin >> n;

		if (n==0)
		{
			n++;
		}
		else if (n<0)
		{
			n = n*(-1);
		}

		disc = 8*n - 7;
		sqrt_d = sqrt(disc);

		disc = (int)sqrt_d;

		if(sqrt_d == (double)disc)
		{
			printf("  digit in series  -  1\n\n");
		}
		else
		{
			printf("  digit in series  -  0\n\n");
		}
	}

	return 0;
}


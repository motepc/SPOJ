/*

Let A(n) = sin(1–sin(2+sin(3–sin(4+…sin(n))…)
Let S(n) = (…(A1+n)A2+n–1)A3+…+2)An+1
For given N print S(N)

Author - Pravin Mote
25th Apr 2015

*/



#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>

void print_A (int i, int max);
void print_S (int i, int max);

int main ()
{
	int i, j;

	printf ("\n	Input an integer -  ");
	std::cin >> i;
	printf ("\n	");

	print_S (i, i);
	printf ("\n\n");

return 0;
}

void print_A (int i, int max)
{
	printf ("sin(%d", max-i+1);

	if (i>1)
	{
		if ((max-i)%2 == 0)
			printf ("-");
		else
			printf ("+");

		print_A (i-1, max);
	}

	printf (")");
}

void print_S (int i, int max)
{
	if (i>1)
	{
		printf ("(");
		print_S (i-1, max);
		printf (")");
	}

		print_A (i, i);
		printf ("+%d", max-i+1);
}


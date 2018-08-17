/*

Two integers are input - i,j.
Output is, i*(i-j)*(i-2j)*......*(i%j)

*/


#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>

int fact (int i, int j);

int main ()
{
	int i, j;

	printf ("\n	Input any 2 integers -  ");
	std::cin >> i >> j;

	if (i < j)		// Exchange values of i, j
	{
		i = i+j;
		j = i-j;
		i = i-j;
	}

	printf ("\n	Factorial -  %d\n\n", fact(i, j));

return 0;
}

int fact (int i, int j)
{
	if (i < 2)
		return 1;
	else
		return i*fact(i-j, j);
}


/*

Input is a number n.
Output is nth prime number.

*/




#include<iostream>
#include<stdio.h>
#include<math.h>



int main()
{
	int i, j, output[1000], prime_bool[8000], counter, start, stop, asked;

	/*  Initialise  */
	output[0] = 2;
	counter = 0;
	start = 2;
	for(i=0; i<8000; i++)
		prime_bool[i] = 0;

	printf("\n Input integer less than 1001 - ");
	std::cin >> asked;
	if(asked > 1000)
	{
		printf("\nGiven number is outside range.\n");
		return 0;
	}

	/*  Check for divisors  */
	for(i=0; i<1000; i++)
	{
		if(counter < 1000)
		{
			j = 2;
			while(output[i]*j < 8000)
			{
				prime_bool[output[i]*j] = 1;
				j++;
			}

			stop = output[i]*output[i];
			for(j=start; j<stop; j++)
			{
				if(prime_bool[j] == 0)
				{
					output[counter] = j;
					counter++;
				}
			}
			start = stop;
		}
		else
			break;
	}

	printf("\n\n %dth prime number is %d\n", asked, output[asked-1]);

	return 0;
}

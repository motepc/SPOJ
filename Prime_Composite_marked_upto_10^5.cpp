/*

All 17984 prime numbers (less than 200000) are marked 0 in prime_bool array.

prime_bool[0] = 1;
prime_bool[1] = 1;
prime_bool[2] = 0;
prime_bool[3] = 0;
prime_bool[4] = 1;
prime_bool[5] = 0;	So on ......

Change the value of RANGE(but less than MAX) for any smaller part of array.

*/

#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<ctime>


using namespace std;



#define MAX 200000
#define RANGE 200000


int main()
{
	int i, current, limit;
	bool prime_bool[RANGE];

	/*  Initialise  */
	for(i=0; i<RANGE; i++)
		prime_bool[i] = 0;

	prime_bool[0] = 1;
	prime_bool[1] = 1;
	prime_bool[2] = 0;

	limit = 1 + (int)sqrt(RANGE);

	/*	Mark multiples of prefound primes	*/
	current = 2;
	while(current < limit)
	{
		i = current*current;
		while(i < RANGE)
		{
			prime_bool[i] = 1;
			i += current;
		}

		current++;
		while(prime_bool[current])
			current++;
	}

	return 0;
}

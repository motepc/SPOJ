/*

All 17984 prime numbers (less than 200000) are stored in prime_num array.

prime_num[0] = 2;
prime_num[1] = 3;
prime_num[2] = 5;
prime_num[3] = 7;
prime_num[4] = 11;
prime_num[5] = 13;	So on ......

Change the value of RANGE(but less than MAX) for any smaller part of array.
Accordingly, reduce allotted memory to prime_num from 18000 to corresponding counter.

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
	int i, current, limit, start, stop, counter, prime_num[18000];
	bool prime_bool[RANGE];

	/*  Initialise  */
	for(i=0; i<RANGE; i++)
		prime_bool[i] = 0;

	prime_bool[0] = 1;
	prime_bool[1] = 1;
	prime_bool[2] = 0;

	limit = 1 + (int)sqrt(RANGE);

	prime_num[0] = 2;
	counter = 1;
	start = 3;

	/*	Mark multiples of prefound primes	*/
	current = 0;
	while(prime_num[current] < limit)
	{
		i = prime_num[current]*prime_num[current];
		while(i < RANGE)
		{
			prime_bool[i] = 1;
			i += prime_num[current];
		}

		stop = prime_num[current]*prime_num[current];
		for(i=start; i<stop; i++)
		{
			if(prime_bool[i] == 0)
			{
				prime_num[counter] = i;
				counter++;
			}
		}
		start = stop;

		current++;
	}

	for(i=start; i<RANGE; i++)
	{
		if(prime_bool[i] == 0)
		{
			prime_num[counter] = i;
			counter++;
		}
	}

	return 0;
}

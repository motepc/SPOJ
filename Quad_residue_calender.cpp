/*
The infamous Bytelandian Bit-eating Fanatic Organisation (BBFO for short) plans to launch an all-out denial-of-service attack
on the Bytelandian McDecimal's fast food network by blocking the entrance to every restaurant with a camel
(the purpose being to rid the Organisation of unhealthy competition, obviously).
In a sly and perfidious move, the head cryptographer of BBFO decided to disclose the date and time of the planned attack
to the management of McDecimal's, but in encrypted form (ha ha).

He calculated the number of seconds from midnight 1970.01.01 GMT to the moment of attack, squared it, divided it by 4000000007
and sent the remainder by e-mail to McDecimal's. This made the original date impossible to decode.

Or did it?

*   *   *
You work as the head algorthimist at McDecimal's HQ and know nothing of what is happening in Byteland.
Things are not going well. You are playing a quiet game of hearts against your computer
and wondering why on earth Management are considering making you redundant. Suddenly, the CEO bursts into your office, saying:

- Look here, young man[lady]! I have this number and those guys claim it is supposed to be some date.
I am giving you one second to tell me what it all means!

I am afraid you have no choice. You can't ask any further questions.
You just have to answer, now.


Input
The encrypted timestamp.

Output
The decrypted GMT time and date of attack, somewhere between 1970 and 2030, using standard 26 character formatting.

Example

Input:
1749870067

Output:
Sun Jun 13 16:20:39 2004
*/

#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>


using namespace std;



int main()
{
	static long long prime = 4000000007LL;
	unsigned long long input, root, acc = 1, twice, target, pow_n, reached = 0;
	int time[7], quarter, i, month[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

	cin >> input;

	if(input == 0)
	{
		printf("Thu Jan 01 00:00:00 1970");
		return 0;
	}

	pow_n = 1 + ((prime-3)/4);

	while(reached < pow_n)
	{
		root = input; twice = 1; target = pow_n - reached;
		while((2*twice) < target)
		{
			root = (root*root)%prime;
			twice *= 2;
		}
		acc = (acc*root)%prime;
		reached = reached + twice;
	}
	root = prime - acc;


	time[0] = (int)root%60;		// Seconds
	root = root/60;

	time[1] = (int)root%60;		// Minutes
	root = root/60;

	time[2] = (int)root%24;		// Hours
	root = root/24;

	time[3] = (int)root%7;			// Day

	quarter = (int)root/(365*4+1);
	time[6] = 4*quarter + 1970;	// Year

	root = root%(365*4+1);

	i = 1;
	while(root > (364 + ((int)i/3)))
	{
		root = root - (365+((int)i/3));
		time[6]++;
		i++;
	}

	if(i == 3)
		month[1]++;

	quarter = 0;
	while(root >= month[quarter])
	{
		root = root - month[quarter];

		quarter++;
	}

	time[5] = quarter;				// Month
	time[4] = root + 1;				// Date

	switch(time[3])
	{
		case 0:
			printf("Thu");
			break;
		case 1:
			printf("Fri");
			break;
		case 2:
			printf("Sat");
			break;
		case 3:
			printf("Sun");
			break;
		case 4:
			printf("Mon");
			break;
		case 5:
			printf("Tue");
			break;
		case 6:
			printf("Wed");
			break;
	}

	switch(time[5])
	{
		case 0:
			printf(" Jan");
			break;
		case 1:
			printf(" Feb");
			break;
		case 2:
			printf(" Mar");
			break;
		case 3:
			printf(" Apr");
			break;
		case 4:
			printf(" May");
			break;
		case 5:
			printf(" Jun");
			break;
		case 6:
			printf(" Jul");
			break;
		case 7:
			printf(" Aug");
			break;
		case 8:
			printf(" Sep");
			break;
		case 9:
			printf(" Oct");
			break;
		case 10:
			printf(" Nov");
			break;
		case 11:
			printf(" Dec");
			break;
	}

	printf(" %02d %02d:%02d:%02d %d", time[4], time[2], time[1], time[0], time[6]);

	return 0;

}

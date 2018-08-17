/*

A positive integer is called a palindrome if its representation in the decimal system is the same when read from left to right
and from right to left.
For a given positive integer K of not more than 1000000 digits, write the value of the smallest palindrome larger than K to output.
Numbers are always displayed without leading zeros.


Input
The first line contains integer t, the number of test cases. Integers K are given in the next t lines.

Output
For each K, output the smallest palindrome larger than K.


Example

Input:
2
808
2133

Output:
818
2222

Warning: large Input/Output data, be careful with certain languages

*/



#include<stdio.h>
#include<iostream>
#include<math.h>
#include<string.h>
#include<stdlib.h>

using namespace std;


int main()
{
	string input[100];
	int freq, t, odd, increase;
	long long i, j, half;

	/*	Input process	*/
	scanf ("%d\n", &freq);

	for(t=0; t<freq; t++)
	{
		getline(cin, input[t]);
	}

	for(t=0; t<freq; t++)
	{
		odd = input[t].size()%2;
		half = (int)(input[t].size()/2);
		if(half == 0)
		{
			printf("11\n");
			continue;
		}

		i = 0; increase = 1;
		while(i<half)
		{
			if(input[t].at(half-1-i) == input[t].at(half+odd+i))
				i++;
			else if(input[t].at(half-1-i) > input[t].at(half+odd+i))
			{
				increase = 0;
				break;
			}
			else if(input[t].at(half-1-i) < input[t].at(half+odd+i))
				break;
		}

		if(increase == 1)
		{
			i = 0;
			while(i < (half+odd))
			{
				if(input[t].at(half+odd-1-i) < 57)
				{
					input[t].at(half+odd-1-i)++;
					break;
				}
				else
				{
					input[t].at(half+odd-1-i) = input[t].at(half+odd-1-i) - 9;
					i++;
				}
			}
		}

		if(i == (half+odd))
		{
			printf("1");
			j=1;
		}
		else
			j=0;

		for(i=0; i<(half+odd); i++)
			printf("%c", input[t].at(i));
		for(i=(half+odd); i<(2*half+odd-1); i++)
			printf("%c", input[t].at(2*half+odd-1-i));

		printf("%c\n", input[t].at(0)+j);
	}

	return 0;
}

/*

Input
There is a single positive integer T on the first line of input (equal to about 100000). It stands for the number of testcases.
Then there are T lines, each containing exactly one positive integer number N, 1 <= N <= 1000000000.

Output
For every number N, output a single line containing the single non-negative integer equal to number of trailing zeros in factorial of input.


Example

Sample Input:
6
3
60
100
1024
23456
8735373

Sample Output:
0
14
24
253
5861
2183837

*/

#include<iostream>
#include<cstdio>
 
using namespace std;
 
 
int main()
{
	int freq, t;
	long long pow5, input, output;
 
	scanf ("%d\n", &freq);
 
	for(t=0; t<freq; t++)
	{
		cin >> input;
 
		output = 0; pow5 = 5;
		while(pow5 <= input)
		{
			output = output + ((int)(input/pow5));
			pow5 = pow5*5;
		}
 
		printf("%lld\n", output);
	}
 
	return 0;
}

/*

You are asked to calculate factorials of some small positive integers.

Input
An integer t, 1<=t<=100, denoting the number of testcases, followed by t lines, each containing a single integer n, 1<=n<=100.

Output
For each integer n given at input, display a line with the value of n!


Example

Sample input:
4
1
2
5
3

Sample output:
1
2
120
6

*/


#include<iostream>
#include<cstdio>
#include<cmath>
#include<string>


using namespace std;


void fact(int input, string output);

int main()
{
	int t, freq, input;
	string output, unity = "1";

		/*	Input process	*/
	scanf ("%d\n", &freq);

	for(t=0; t<freq; t++)
	{
		cin >> input;

		output.clear();
		output = unity;

		fact(input, output);
	}

	return 0;
}


void fact(int input, string output)
{
	int i, carry, temp;

	if(input == 1)
	{
		for(i=0; i<output.size(); i++)
			printf("%c", output.at(output.size()-1-i));
		printf("\n");

		return;
	}

	carry = 0;
	for(i=0; i<output.size(); i++)
	{
		carry = carry + (output.at(i)-48)*input;

		temp = carry%10 + 48;
		carry = carry/10;
		output.replace(i, 1, (char*)(&temp));
	}
	while(carry > 0)
	{
		temp = carry%10 + 48;
		carry = carry/10;
		output.append((char*)(&temp), 0, 1);
	}

	fact(input-1, output);

	return;
}

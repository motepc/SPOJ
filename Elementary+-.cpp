/*

Input
The first line contains integer t(<=1000), the number of test cases.
Next T line contains 2 numbers(with <= 500 digits) with =,-,* operation

Output
As follows.


Example

Input:
4
12345+67890
324-111
325*4405
1234*4


Output:
12345
+67890
------
 80235

 324
-111
----
 213

    325
  *4405
  -----
   1625
     0
 1300
1300
-------
1431625

1234
  *4
----
4936

Warning: large Input/Output data, be careful with certain languages

*/



#include<stdio.h>
#include<iostream>
#include<math.h>
#include<string.h>
#include<stdlib.h>

using namespace std;

string output;
string input;

void addition(string input, int loc);
void substraction(string input, int loc);
void multiplication(string input, int location);


int main()
{
	int freq, t, i, j, op_loc[2];

	scanf ("%d\n", &freq);

	for(t=0; t<freq; t++)
	{
		getline(cin, input);

		for(i=0; i<input.size(); i++)
		{
			if((input.at(i) == '+') || (input.at(i) == '-') || (input.at(i) == '*'))
			{
				op_loc[0] = input.at(i);
				op_loc[1] = i;
				break;
			}
		}

		switch(op_loc[0])
		{
			case 43:
				addition(input, op_loc[1]);
				break;
			case 45:
				substraction(input, op_loc[1]);
				break;
			case 42:
				multiplication(input, op_loc[1]);
				break;
		}
	}

	return 0;
}


void addition(string input, int loc)
{
	int i, size1, size2, sum, carry;

	size1 = loc;
	size2 = input.size()-loc-1;
	output.clear();

	i=0; carry = 0;
	while((i<size1)||(i<size2))
	{
		sum = carry;

		if(i<size1)
			sum = sum + input.at(size1 -1-i) - 48;

		if(i<size2)
			sum = sum + input.at(size1 + size2 -i) - 48;

		carry = (int)(sum/10);
		sum = sum%10 + 48;

		output.append((char*)(&sum), 0, 1);
		i++;
	}
	if(carry != 0)
	{
		carry = carry + 48;
		output.append((char*)(&carry), 0, 1);
	}

	sum = size1 > (size2+1) ? size1 : (size2+1);
	sum = sum > output.size() ? sum : output.size();

	for(i=0; i<(sum-size1); i++)
		printf(" ");
	for(i=0; i<size1; i++)
		printf("%c", input.at(i));
	printf("\n");

	for(i=0; i<(sum-size2-1); i++)
		printf(" ");
	printf("+");
	for(i=(size1+1); i<input.size(); i++)
		printf("%c", input.at(i));
	printf("\n");

	for(i=0; i<sum; i++)
		printf("-");
	printf("\n");

	for(i=0; i<(sum-output.size()); i++)
		printf(" ");
	for(i=0; i<output.size(); i++)
		printf("%c", output.at(output.size()-1-i));
	printf("\n\n");
}


void substraction(string input, int loc)
{
	int i, size1, size2, sum, carry, max;

	size1 = loc;
	size2 = input.size()-loc-1;
	output.clear();

	i=0; carry = 0;
	while(i<size1)
	{
		sum = input.at(size1 -1-i) - 48;

		if(i<size2)
			carry = carry + input.at(size1 + size2 -i) - 48;

		if(sum < carry)
		{
			sum = sum + 10 - carry + 48;
			carry = 1;
		}
		else
		{
			sum = sum - carry + 48;
			carry = 0;
		}

		output.append((char*)(&sum), 0, 1);
		i++;
	}

	carry = 1;
	for(i=0; i<output.size(); i++)
		if(output.at(i) != '0')
			carry = i+1;

	sum = size1 > (size2+1) ? size1 : (size2+1);
	sum = sum > carry ? sum : carry;
	max = carry > (size2+1) ? carry : (size2+1);

	for(i=0; i<(sum-size1); i++)
		printf(" ");
	for(i=0; i<size1; i++)
		printf("%c", input.at(i));
	printf("\n");

	for(i=0; i<(sum-size2-1); i++)
		printf(" ");
	printf("-");
	for(i=(size1+1); i<input.size(); i++)
		printf("%c", input.at(i));
	printf("\n");

	for(i=0; i<(sum-max); i++)
		printf(" ");
	for(i=0; i<max; i++)
		printf("-");
	printf("\n");

	for(i=0; i<(sum-carry); i++)
		printf(" ");
	for(i=0; i<carry; i++)
		printf("%c", output.at(carry-1-i));
	printf("\n\n");
}


void multiplication(string input, int location)
{
	int i, j, size1, size2, sum, carry, n2, max;
	int loc[501], size[501];

	size1 = location;
	size2 = input.size()-location-1;
	output.clear();

	i=0; loc[0] = 0;
	while(i<size2)
	{
		size[i] = 0;
		if(i != 0)
			loc[i] = size[i-1] + loc[i-1];

		n2 = input.at(size1 + size2 -i) - 48;
		if(n2 == 0)
		{
			sum = 48;
			output.append((char*)(&sum), 0, 1);
			size[i]++;
		}
		else
		{
			j = 0; carry = 0;
			while(j<size1)
			{
				sum = carry + (input.at(size1 -1-j) - 48)*n2;
				carry = (int)(sum/10);
				sum = sum%10 + 48;

				output.append((char*)(&sum), 0, 1);
				size[i]++;
				j++;
			}
			if(carry != 0)
			{
				carry = carry + 48;
				output.append((char*)(&carry), 0, 1);
				size[i]++;
			}
		}

		i++;
	}

	max = 0;
	for(i=0; i<size2; i++)
		if(max < (size[i]+i))
			max = size[i] + i;

	size[size2] = 0;
	loc[size2] = size[size2-1] + loc[size2-1];

	carry = 0;
	for(i=0; i<max; i++)
	{
		j = 0; sum = carry;
		while((j<(i+1)) && (j<size2))
		{
			if((i-j) < size[j])
				sum = sum + (output.at(loc[j]+i-j) - 48);

			j++;
		}

		carry = (int)(sum/10);
		sum = sum%10 + 48;

		output.append((char*)(&sum), 0, 1);
		size[size2]++;
	}
	while(carry != 0)
	{
		sum = carry%10 + 48;
		output.append((char*)(&sum), 0, 1);
		size[size2]++;

		carry = (int)(carry/10);
	}


	sum = size1 > (size2+1) ? size1 : (size2+1);
	sum = sum > max ? sum : max;
	sum = sum > size[size2] ? sum : size[size2];

	max = (size2+1) > size[0] ? (size2+1) : size[0];

	for(i=0; i<(sum-size1); i++)
		printf(" ");
	for(i=0; i<size1; i++)
		printf("%c", input.at(i));
	printf("\n");

	for(i=0; i<(sum-size2-1); i++)
		printf(" ");
	printf("*");
	for(i=(size1+1); i<input.size(); i++)
		printf("%c", input.at(i));
	printf("\n");

	for(i=0; i<(sum-max); i++)
		printf(" ");
	for(i=0; i<max; i++)
		printf("-");
	printf("\n");

	if(size2 != 1)
	{
		for(j=0; j<size2; j++)
		{
			for(i=0; i<(sum-j-size[j]); i++)
				printf(" ");
			for(i=0; i<size[j]; i++)
				printf("%c", output.at(loc[j]+size[j]-1-i));
			printf("\n");
		}

		for(i=0; i<(sum-size[size2]); i++)
			printf(" ");
		for(i=0; i<size[size2]; i++)
			printf("-");
		printf("\n");
	}

	for(i=0; i<(sum-size[size2]); i++)
		printf(" ");
	for(i=0; i<size[size2]; i++)
		printf("%c", output.at(loc[size2]+size[size2]-1-i));
	printf("\n\n");
}

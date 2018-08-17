/*

The goal of this problem is to illusrate that all arithmetic operations on natural numbers in binary format can be implemented
by using a few logical operations on the individual bits.
The allowed operations are XOR, NOT, AND, OR, and SHIFT,
where the latter is the operation of shifting the bits of a number to the right or to the left
(with digits disappearing or new zeroes appearing at one or the other end as needed).

Note that in principle, NOT, AND, and OR are superfluous because they can be expressed in terms of XOR only.
No automatic check will be performed on if the submitted code satisfies the aforementioned restrictions.
This means that the problem solver needs to impose the restrictions on their code, keeping in mind the goal that we are trying to mimick how the CPU hardware handles
integers.


Input
The first number is the number of test cases, in binary. Then the next numbers are in groups of 3, all in binary.
In each group, the first number encodes the operatioin to be performed on the next 2 numbers. The encoding convention is as follows.

0 greater than
1 addition
10 subtraction
11 multiplication
100 division

All numbers in the input are understood to be nonnegative integers. If needed, you can assume that the number of bits in each integer does not exceed 200.


Output
For each test case, the output must include one or two binary numbers.
In case of division only, the output consists of two numbers: Supposing that the pair of numbers in the input are A and B,
the output should be A/B (integer division) and A%B (remainder). If B happens to be 0, the output should be 0 0 (two zeroes).

For the operation "greater than", output 1 if the first number is greater than the second number, and output 0 otherwise.

If the first argument A of a subtraction is smaller than the second argument B, then A should be replaced by A + 2N, where N is the smallest integer
such that 2N > max{A,B}.
For example, in the operation 100 - 101 (dec. 4 - 5), the first argument should be increased by 1000 (dec. 8), making it 1100 (dec. 12),
and the output corresponding to the operation 100 - 101 should be 111 (dec. 12 - 5 = 7).


Example

Input:
111
0 10 10
1 10 11
0 11 10 
11 101 11
10 11 10
100 1011 11
10 10 11

Output:
0
101
1 
1111
1
11 10
11

*/




#include<stdio.h>
#include<iostream>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include <bitset>



/*	std::cout << "\n" << std::bitset<8>(a);
	std::cout << "\n" << std::bitset<8>(dec);

	NOT !
	OR  |
	AND &
	XOR ^
*/

int compare(int a, int b);
int add(int a, int b);
int add16(int a, int b);
int sub(int a, int b);
int mult(int a, int b);
int divide(int a, int b);


int main()
{
	int freq, i, j, k, found, dec, input[100][3];


	scanf ("%d\n", &freq);

	dec = 0;
	for(i=0; i<8; i++)
	{
		dec += freq%2 << i;
		freq = freq/10;
	}
	freq = dec;

	for(i=0; i<freq; i++)
	{
		std::cin >> input[i][0] >> input[i][1] >> input[i][2];
	}


	for(i=0; i<freq; i++)
	{
		for(j=1; j<3; j++)
		{
			dec = 0;
			for(k=0; k<8; k++)
			{
				dec += input[i][j]%2 << k;
				input[i][j] = input[i][j]/10;
			}
			input[i][j] = dec;
		}

		switch(input[i][0])
		{
			case 0:
				dec = compare(input[i][1], input[i][2]);
				printf("%d", dec);
				break;
			case 1:
				dec = add(input[i][1], input[i][2]);

				//std::cout << std::bitset<9>(dec) << "\n";
				found = 0;
				for(j=8; j>=0; j--)
				{
					if((found == 1)||((dec&(1<<j)) != 0))
					{
						found = 1;
						printf("%d", (dec&(1<<j))>>j);
					}
				}

				break;
			case 10:
				dec = sub(input[i][1], input[i][2]);
				break;
			case 11:
				dec = mult(input[i][1], input[i][2]);

				//std::cout << std::bitset<16>(dec) << "\n";
				found = 0;
				for(j=15; j>=0; j--)
				{
					if((found == 1)||((dec&(1<<j)) != 0))
					{
						found = 1;
						printf("%d", (dec&(1<<j))>>j);
					}
				}
				break;
			case 100:
				dec = divide(input[i][1], input[i][2]);
				break;
		}

		printf("\n");

	}

	return 0;
}



/*	Remaining part of code here onwards uses only logical operations	*/

int compare(int a, int b)
{
	bool out = 0;

	out = ((!(((a^b)>>0)&1))&out)|((((a^b)>>0)&1)&((a>>0)&1));
	out = ((!(((a^b)>>1)&1))&out)|((((a^b)>>1)&1)&((a>>1)&1));
	out = ((!(((a^b)>>2)&1))&out)|((((a^b)>>2)&1)&((a>>2)&1));
	out = ((!(((a^b)>>3)&1))&out)|((((a^b)>>3)&1)&((a>>3)&1));
	out = ((!(((a^b)>>4)&1))&out)|((((a^b)>>4)&1)&((a>>4)&1));
	out = ((!(((a^b)>>5)&1))&out)|((((a^b)>>5)&1)&((a>>5)&1));
	out = ((!(((a^b)>>6)&1))&out)|((((a^b)>>6)&1)&((a>>6)&1));
	out = ((!(((a^b)>>7)&1))&out)|((((a^b)>>7)&1)&((a>>7)&1));

	//printf("%d", out);

	return out;
}


int add(int a, int b)
{
	int out = 0, carry;

	out = out | ((a^b)&(1<<0)); carry = ((a&b)&(1<<0))<<1;
	out = out | (carry^((a^b)&(1<<1))); carry = (((!carry)<<1)&((a&b)&(1<<1))|(carry&((a|b)&(1<<1))))<<1;
	out = out | (carry^((a^b)&(1<<2))); carry = (((!carry)<<2)&((a&b)&(1<<2))|(carry&((a|b)&(1<<2))))<<1;
	out = out | (carry^((a^b)&(1<<3))); carry = (((!carry)<<3)&((a&b)&(1<<3))|(carry&((a|b)&(1<<3))))<<1;
	out = out | (carry^((a^b)&(1<<4))); carry = (((!carry)<<4)&((a&b)&(1<<4))|(carry&((a|b)&(1<<4))))<<1;
	out = out | (carry^((a^b)&(1<<5))); carry = (((!carry)<<5)&((a&b)&(1<<5))|(carry&((a|b)&(1<<5))))<<1;
	out = out | (carry^((a^b)&(1<<6))); carry = (((!carry)<<6)&((a&b)&(1<<6))|(carry&((a|b)&(1<<6))))<<1;
	out = out | (carry^((a^b)&(1<<7))); carry = (((!carry)<<7)&((a&b)&(1<<7))|(carry&((a|b)&(1<<7))))<<1;
	out = out | (carry^((a^b)&(1<<8)));

	//std::cout << std::bitset<9>(out);

	return out;
}


int add16(int a, int b)
{
	int out = 0, carry;

	out = out | ((a^b)&(1<<0)); carry = ((a&b)&(1<<0))<<1;
	out = out | (carry^((a^b)&(1<<1))); carry = (((!carry)<<1)&((a&b)&(1<<1))|(carry&((a|b)&(1<<1))))<<1;
	out = out | (carry^((a^b)&(1<<2))); carry = (((!carry)<<2)&((a&b)&(1<<2))|(carry&((a|b)&(1<<2))))<<1;
	out = out | (carry^((a^b)&(1<<3))); carry = (((!carry)<<3)&((a&b)&(1<<3))|(carry&((a|b)&(1<<3))))<<1;
	out = out | (carry^((a^b)&(1<<4))); carry = (((!carry)<<4)&((a&b)&(1<<4))|(carry&((a|b)&(1<<4))))<<1;
	out = out | (carry^((a^b)&(1<<5))); carry = (((!carry)<<5)&((a&b)&(1<<5))|(carry&((a|b)&(1<<5))))<<1;
	out = out | (carry^((a^b)&(1<<6))); carry = (((!carry)<<6)&((a&b)&(1<<6))|(carry&((a|b)&(1<<6))))<<1;
	out = out | (carry^((a^b)&(1<<7))); carry = (((!carry)<<7)&((a&b)&(1<<7))|(carry&((a|b)&(1<<7))))<<1;
	out = out | (carry^((a^b)&(1<<8))); carry = (((!carry)<<8)&((a&b)&(1<<8))|(carry&((a|b)&(1<<8))))<<1;
	out = out | (carry^((a^b)&(1<<9))); carry = (((!carry)<<9)&((a&b)&(1<<9))|(carry&((a|b)&(1<<9))))<<1;
	out = out | (carry^((a^b)&(1<<10))); carry = (((!carry)<<10)&((a&b)&(1<<10))|(carry&((a|b)&(1<<10))))<<1;
	out = out | (carry^((a^b)&(1<<11))); carry = (((!carry)<<11)&((a&b)&(1<<11))|(carry&((a|b)&(1<<11))))<<1;
	out = out | (carry^((a^b)&(1<<12))); carry = (((!carry)<<12)&((a&b)&(1<<12))|(carry&((a|b)&(1<<12))))<<1;
	out = out | (carry^((a^b)&(1<<13))); carry = (((!carry)<<13)&((a&b)&(1<<13))|(carry&((a|b)&(1<<13))))<<1;
	out = out | (carry^((a^b)&(1<<14))); carry = (((!carry)<<14)&((a&b)&(1<<14))|(carry&((a|b)&(1<<14))))<<1;
	out = out | (carry^((a^b)&(1<<15)));


	//std::cout << std::bitset<16>(out);

	return out;
}


int sub(int a, int b)
{
	int out;

	out = (add(a, add((~b),1)))&(~(1<<8));

	std::cout << std::bitset<8>(out);

	return out;
}


int mult(int a, int b)
{
	int acc=0;

	acc = add16(acc,(a&(add((!(b&(1<<0))), 0b11111111)))<<0);
	acc = add16(acc,(a&(add((!(b&(1<<1))), 0b11111111)))<<1);
	acc = add16(acc,(a&(add((!(b&(1<<2))), 0b11111111)))<<2);
	acc = add16(acc,(a&(add((!(b&(1<<3))), 0b11111111)))<<3);
	acc = add16(acc,(a&(add((!(b&(1<<4))), 0b11111111)))<<4);
	acc = add16(acc,(a&(add((!(b&(1<<5))), 0b11111111)))<<5);
	acc = add16(acc,(a&(add((!(b&(1<<6))), 0b11111111)))<<6);
	acc = add16(acc,(a&(add((!(b&(1<<7))), 0b11111111)))<<7);


	//std::cout << std::bitset<16>(acc);

	return acc;
}


int divide(int a, int b)
{
	return 0;
}

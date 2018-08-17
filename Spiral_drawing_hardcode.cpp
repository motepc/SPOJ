
/*	Code need to be fixed for spiral size '4n'	*/




/*

Print a straight line spiral pattern as shown in the example below. Please use the * (asterisk) and . (dot) characters.

Input
You are given t - the number of test cases and for each of the test cases one integer: s, 3<s<100 - the size of the shape.


Output
For each of the test cases output the requested pattern. Use one line break in between successive patterns.


Example

Input:
4
4
5
11 
13

Output:
****
...*
*..*
****

*****
....*
***.*
*...*
*****

***********
..........*
*********.*
*.......*.*
*.*****.*.*
*.*...*.*.*
*.*.***.*.*
*.*.....*.*
*.*******.*
*.........*
***********

*************
............*
***********.*
*.........*.*
*.*******.*.*
*.*.....*.*.*
*.*.***.*.*.*
*.*.*...*.*.*
*.*.*****.*.*
*.*.......*.*
*.*********.*
*...........*
*************

*/





#include<stdio.h>
#include<iostream>
#include<math.h>
#include<string.h>
#include<stdlib.h>

int main()
{
	int input[100], order[100];
	int freq, i, j, k, r, temp;


/*	Input process	*/

	scanf ("%d\n", &freq);

	for(i=0; i<freq; i++)
	{
		std::cin >> input[i];
	}


/*	Start to draw maze	*/
	for(i=0; i<freq; i++)
	{
		r = 0;

		if(input[i] == 4)
			temp = 0;
		else
			temp = 1;


/*	Draw upper triangle	*/

		while((input[i]+temp) > 2*r)
		{
			printf("\n");

			for(j=0; j<input[i]; j++)
				order[j] = 0;

			k = r;
			while(k>0)
			{
				order[input[i]-k] = 1;
				k = k - 2;
			}

			k = r - 2;
			while(k>0)
			{
				order[k-1] = 1;
				k = k - 2;
			}

			for(j=0; j<input[i]; j++)
			{
				printf("%c", 42 + 4*(((r%2)+order[j])%2));
			}

			r++;
		}


		temp = 0;
		for(j=0; j<input[i]/2; j++)
		{
			order[j] = temp;
			order[input[i]-1-j] = temp;
			temp = (temp + 1)%2;
		}


		if(input[i]%2)
			temp = input[i] - 3;
		else if(input[i]==4)
			temp = input[i] - 2;
		else
			temp = input[i] - 4;

		temp = temp/2;


/*	Draw lower triangle	*/

		while(temp >= 0)
		{
			printf("\n");

			for(j=temp; j<(input[i]-temp); j++)
			{
				order[j] = temp%2;
			}

			for(j=0; j<input[i]; j++)
			{
				printf("%c", 42 + 4*order[j]);
			}

			temp--;
		}

		printf("\n");
	}

	return 0;
}

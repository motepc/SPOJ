/*

Print a regular grid pattern with diamond-like base elements.
Use the \ (backslash) and the / (slash) characters to print diamonds and . (dots) to fill the rest of the space.

Input
You are given t - the number of test cases and for each of the test cases three positive integers:
r - the number of rows, c - the number of columns in the grid and s - the size of each diamond.

Output
For each of the test cases output the requested pattern (please have a look at the example). Use one line break in between successive patterns.

Example

Input:
3
3 1 2 
4 4 1 
2 5 2

Output:
./\.
/..\
\../
.\/.
./\.
/..\
\../
.\/.
./\.
/..\
\../
.\/.

/\/\/\/\
\/\/\/\/
/\/\/\/\
\/\/\/\/
/\/\/\/\
\/\/\/\/
/\/\/\/\
\/\/\/\/


./\../\../\../\../\.
/..\/..\/..\/..\/..\
\../\../\../\../\../
.\/..\/..\/..\/..\/.
./\../\../\../\../\.
/..\/..\/..\/..\/..\
\../\../\../\../\../
.\/..\/..\/..\/..\/.

*/




#include<stdio.h>
#include<iostream>
#include<math.h>
#include<string.h>

int main()
{
	int input[100][3];
	int freq, i, j, k, l, w;

	scanf ("%d\n", &freq);

	for(i=0; i<freq; i++)
	{
		std::cin >> input[i][0] >> input[i][1] >> input[i][2];
	}

	for(i=0; i<freq; i++)
	{
		for(j=0; j<input[i][0]; j++)
		{
			for(l=0; l<2*input[i][2]; l++)
			{
				printf("\n");

				for(k=0; k<input[i][1]; k++)
				{
					for(w=0; w<2*input[i][2]; w++)
					{
						if(w == ((3*input[i][2]-1-l)%(2*input[i][2])))
							printf("%c", 47);
						else if(w == ((input[i][2]+l)%(2*input[i][2])))
							printf("%c", 92);
						else
							printf(".");
					}
				}
			}
		}

		printf("\n");
	}

	return 0;
}

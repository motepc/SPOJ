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


int NextValid(int size, int* path, int* j, int* k, int* direction, int clockwise);

int main()
{
	int input[100], path[100][100];
	int freq, i, j, k, direction, val, clockwise;

/*	Input process	*/

	scanf ("%d\n", &freq);

	for(i=0; i<freq; i++)
	{
		std::cin >> input[i];
	}


/*	Start to draw maze	*/
	for(i=0; i<freq; i++)
	{
		for(j=0; j<input[i]; j++)
		{
			for(k=0; k<input[i]; k++)
			{
				path[j][k] = 0;
			}
		}


		j = 0; k = 0;
		path[j][k] = 1; direction = 0;		// 0=right, 1=down, 2=left, 3=up
		clockwise = 1;

		while(1)
		{
			val = NextValid(input[i], &path[0][0], &j, &k, &direction, clockwise);

			if(val < 2)
				break;
		}


		for(j=0; j<input[i]; j++)
		{
			printf("\n");
			for(k=0; k<input[i]; k++)
			{
				printf("%c", 46 - 4*path[j][k]);
			}
		}

		printf("\n");
	}

	return 0;
}


int NextValid(int size, int* path, int* j, int* k, int* direction, int clockwise)
{
	int endx, endy,  added, temp;

	switch(*direction)
	{
		case 0:
			endx = *j; endy = size-1;

			while((path[endx*100 + endy] == 1) && (endy > *k))
			{
				endy = endy - 2;
			}

			added = endy - *k;

			if(added > 0)
			{
				for(temp = *k; temp<endy+1; temp++)
					path[endx*100 + temp] = 1;
			}

			if(clockwise == 1)
				*direction = 1;
			else
				*direction = 3;

			*k = endy;

			break;

		case 1:
			endx = size-1; endy = *k;

			while((path[endx*100 + endy] == 1) && (endx > *j))
			{
				endx = endx - 2;
			}

			added = endx - *j;

			if(added > 0)
			{
				for(temp = *j; temp<endx+1; temp++)
					path[temp*100 + endy] = 1;
			}

			if(clockwise == 1)
				*direction = 2;
			else
				*direction = 0;

			*j = endx;

			break;

		case 2:
			endx = *j; endy = 0;

			while((path[endx*100 + endy] == 1) && (endy < *k))
			{
				endy = endy + 2;
			}

			added = *k - endy;

			if(added > 0)
			{
				for(temp = endy; temp<*k; temp++)
					path[endx*100 + temp] = 1;
			}

			if(clockwise == 1)
				*direction = 3;
			else
				*direction = 1;

			*k = endy;

			break;

		case 3:
			endx = 0; endy = *k;

			while((path[endx*100 + endy] == 1) && (endx < *j))
			{
				endx = endx + 2;
			}

			added = *j - endx;

			if(added > 0)
			{
				for(temp = endx; temp<*j; temp++)
					path[temp*100 + endy] = 1;
			}

			if(clockwise == 1)
				*direction = 0;
			else
				*direction = 2;

			*j = endx;

			break;
	}

	return added;
}

/*

Compute the Minimum Bounding Rectangle (MBR) that surrounds the given set of 2D objects,
i.e., the axis-aligned rectangle, which contains all of the specified objects and is the one with minimum area among all rectangles with this property.


Input
First, you are given t (t<100) - the number of test cases.

Each of the test cases starts with one integer n (n < 100) - the number of objects in the set. In the successive n lines, the descriptions of the objects follow.

Each object is described by one character and some parameters:

a point: p x y, where x and y are point coordinates.
a circle: c x y r, where x and y are the center coordinates and r is the radius of the circle.
a line segment: l x1 y1 x2 y2, where xi, yi are the coordinates of the endpoints of the line.
Successive test cases are separated by an empty line.


Output

For each of the test cases output four numbers - the coordinates of the two points that correspond to the lower left and the upper right corner of the MBR,
in the following order: first the x-coordinate of the lower left corner, then the y-coordinate of the lower left corner,
the x-coordinate of the upper right corner and the y-coordinate of upper right corner.

You can assume that all object parameters are integers and that -1000 -1000 1000 1000 is a bounding rectangle for of all of them.

Example

Input:
3
1
p 3 3 

2
c 10 10 20
c 20 20 10

1
l 0 0 100 20

Output:
3 3 3 3 
-10 -10 30 30
0 0 100 20


*/




#include<stdio.h>
#include<iostream>
#include<math.h>
#include<string.h>

int main()
{
	signed int pt[100][100][2], cir[100][100][3], line[100][100][4];
	int in_l[3] = {2,3,4}, counter[100][3] = {0};
	int freq, i, j, k;
	signed int xmin, xmax, ymin, ymax;
	char temp;


	/*   Input process   */

	scanf ("%d\n", &freq);

	for(i=0; i<freq; i++)
	{
		scanf ("%d\n", &j);

		for(k=0; k<j; k++)
		{
			std::cin >> temp;

			if(temp == 'p')
			{
				std::cin >> pt[i][counter[i][0]][0] >> pt[i][counter[i][0]][1];

				counter[i][0]++;
			}
			else if(temp == 'c')
			{
				std::cin >> cir[i][counter[i][1]][0] >> cir[i][counter[i][1]][1] >> cir[i][counter[i][1]][2];

				counter[i][1]++;
			}
			else if(temp == 'l')
			{
				std::cin >> line[i][counter[i][2]][0] >> line[i][counter[i][2]][1] >> line[i][counter[i][2]][2] >> line[i][counter[i][2]][3];

				counter[i][2]++;
			}
		}
	}


	/*   Calculate co-ordinates of rectangle   */
	for(i=0; i<freq; i++)
	{
		xmin = 1000; xmax = -1000; ymin = 1000; ymax = -1000;


		/*   Checking for points   */

		for(j=0; j<counter[i][0]; j++)
		{
			if(xmin > pt[i][j][0])
				xmin = pt[i][j][0];
			if(ymin > pt[i][j][1])
				ymin = pt[i][j][1];
			if(xmax < pt[i][j][0])
				xmax = pt[i][j][0];
			if(ymax < pt[i][j][1])
				ymax = pt[i][j][1];
		}


		/*   Checking for circles   */

		for(j=0; j<counter[i][1]; j++)
		{
			if(xmin > (cir[i][j][0] - cir[i][j][2]))
				xmin = (cir[i][j][0] - cir[i][j][2]);
			if(ymin > (cir[i][j][1] - cir[i][j][2]))
				ymin = (cir[i][j][1] - cir[i][j][2]);
			if(xmax < (cir[i][j][0] + cir[i][j][2]))
				xmax = (cir[i][j][0] + cir[i][j][2]);
			if(ymax < (cir[i][j][1] + cir[i][j][2]))
				ymax = (cir[i][j][1] + cir[i][j][2]);
		}


		/*   Checking for lines   */

		for(j=0; j<counter[i][2]; j++)
		{
			if(xmin > line[i][j][0])
				xmin = line[i][j][0];
			if(ymin > line[i][j][1])
				ymin = line[i][j][1];
			if(xmax < line[i][j][0])
				xmax = line[i][j][0];
			if(ymax < line[i][j][1])
				ymax = line[i][j][1];
			if(xmin > line[i][j][2])
				xmin = line[i][j][2];
			if(ymin > line[i][j][3])
				ymin = line[i][j][3];
			if(xmax < line[i][j][2])
				xmax = line[i][j][2];
			if(ymax < line[i][j][3])
				ymax = line[i][j][3];
		}

		printf("\n%d %d %d %d", xmin, ymin, xmax, ymax);
	}

	return 0;
}

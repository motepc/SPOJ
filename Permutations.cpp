/*
	Problem statement is given in Permutations.jpeg (Problem number 4)
*/

#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>


using namespace std;



void next(int current, int* box)
{
	int i, n = 1, found, num_f, den_f, num, den;

	if(current == 9)
	{
		num_f = 0; den_f = 1;
		for(i=0; i<3; i++)
		{
			num = box[3*i];
			den = 10*box[3*i+1] + box[3*i+2];

			num_f = num_f*den + num*den_f;
			den_f = den_f*den;
		}

		if(num_f == den_f)
		{
			printf("\n");
			for(i=0; i<9; i++)
				printf(" %d", box[i]);
		}

		return;
	}

	while(n<10)
	{
		found = 0;
		for(i=0; i<current; i++)
			if(n == box[i])
				found = 1;

		if(found == 0)
		{
			box[current] = n;
			next(current+1, &box[0]);
		}

		n++;
	}
	
}


int main()
{
	int current = 0, box[9] = {0};

	next(current, &box[0]);

	return 0;
}
